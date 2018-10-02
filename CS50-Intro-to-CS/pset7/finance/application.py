import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash
import logging
import math
from decimal import getcontext, Decimal
TWOPLACES = Decimal(10) ** -2

# Set the precision.
getcontext().prec = 2

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    userID=session['user_id']

    raw = db.execute("SELECT symbol, sum(shareQuantity) as shares from transactions WHERE userID = :userID GROUP BY symbol",
                        userID=userID)
    holdings = []

    # logging.warning(raw)
    for stock in raw:
        # logging.warning(stock)
        # logging.warning(stock['symbol'])
        hash = lookup(stock['symbol'])
        price = hash['price']
        # logging.warning(hash)
        a = price * stock['shares']
        obj = {
            'symbol': stock['symbol'],
            'price': price,
            'shares': stock['shares'],
            'value': '{0:,.2f}'.format(a),
            'name': hash['name']
        }
        holdings.append(obj)

    # get user's cash
    row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
    cash = '{0:,.2f}'.format(row[0]['cash'])

    """Show portfolio of stocks"""
    return render_template("home.html", holdings=holdings, cash=cash)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    if request.method == "GET":
        row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
        cash = row[0]['cash']
        return render_template("buy.html", cash=cash)

    if request.method == "POST":
        # get price of stock
        symbol = request.form.get("symbol")
        hash = lookup(symbol)
        if hash == None:
            return apology("invalid symbol", 400)
        price = hash['price']

        # get users total cash
        row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
        cash = row[0]['cash']

        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("shares must be an integer", 400)

        if shares <= 0:
            return apology('Must be a positive number', 400)
        # get shares


        if shares < 0:
            return apology("shares must be greater than 0", 400)

        # total cost
        cost = int(shares) * price

        # logging.warning(price, " - ",cash, " - ", shares, " - ", cost)

        if(cost > cash):
            return apology("TOO MUCH", 400)
        else:

            # Log transaction
            db.execute("INSERT INTO transactions(symbol, sharePrice, shareQuantity, totalCost, userID) VALUES(:symbol, :price, :shares, :cost, :userID)",
                    symbol=symbol, price=price, shares=shares, cost=cost, userID=session['user_id'])

            # Remaining cash
            remaining = cash - cost
            db.execute("UPDATE users SET cash = :remaining WHERE id = :userID LIMIT 1", remaining=remaining, userID=session['user_id'])
            return redirect("/")

    """Buy shares of stock"""



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    userID=session['user_id']
    if request.method == "GET":
        # Get all transactions
        transactions = db.execute("SELECT * FROM Transactions WHERE userID = :userID", userID=userID)



        return render_template("history.html", transactions=transactions)






@app.route("/add-cash", methods=["GET", "POST"])
@login_required
def addCash():

    userID=session['user_id']
    if request.method == "GET":
        # get users total cash
        row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
        cash = row[0]['cash']

        return render_template("add-cash.html", cash=cash)

    if request.method == "POST":
         # get users total cash NOW
        row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
        cash = float(row[0]['cash'])


        cashToAdd = int(request.form.get("cash"))

        newTotal = cash + cashToAdd

        db.execute("UPDATE users SET cash = :newTotal WHERE id = :id", id=userID, newTotal=newTotal)
        return redirect('/')






@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")
    if request.method == "POST":
        symbol = request.form.get("symbol")
        hash = lookup(symbol)

        if hash == None:
            return apology("invalid symbol", 400)

        quote = {
            "name": hash['name'],
            'symbol': hash['symbol'],
            'price': '{0:,.2f}'.format(hash['price'])
        }

        return render_template("quoted.html", hash=quote)

@app.route("/quoted", methods=["POST"])
@login_required
def quoted():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        hash = lookup(symbol)

        if hash == None:
            return apology("invalid symbol", 400)

        quote = {
            "name": hash['name'],
            'symbol': hash['symbol'],
            'price': '{0:,.2f}'.format(hash['price'])
        }

        return render_template("quoted.html", hash=quote)

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    elif request.method == "POST":

        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")


        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        if not password:
            return apology("must provide password", 400)

        # Ensure password was submitted
        if not confirmation:
            return apology("must confirm your password", 400)

        # Ensure password was submitted
        if not password == confirmation:
            return apology("your passwords must match", 400)

        # Check if username already exists
        user = db.execute("SELECT * FROM users WHERE username=:username", username=username)
        if len(user) == 1:
            return apology("username already exists", 400)

        passHash = generate_password_hash(password,method='pbkdf2:sha256', salt_length=8)
        # Insert into database
        db.execute("INSERT INTO users(username, hash, cash) VALUES(:username, :hash, 500000)",
                                username=username, hash=passHash )

        # Redirect user to home page
        return redirect("/login")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    # show current holdings
    if request.method == "GET":

        userID=session['user_id']

        raw = db.execute("SELECT symbol, sum(shareQuantity) as shares from transactions WHERE userID = :userID GROUP BY symbol",
                        userID=userID)
        holdings = []

        # logging.warning(raw)
        for stock in raw:
            # logging.warning(stock)
            # logging.warning(stock['symbol'])
            hash = lookup(stock['symbol'])
            price = hash['price']
            # logging.warning(hash)
            obj = {
                'symbol': stock['symbol'],
                'price': round(price,2),
                'shares': int(stock['shares']),
                'value': '{0:,.2f}'.format(price * stock['shares']),
                'name': hash['name']
            }
            holdings.append(obj)

        # get user's cash
        row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
        # cash = row[0]['cash']
        cash = '{0:,.2f}'.format(row[0]['cash'])


        return render_template("sell.html", holdings=holdings, cash=cash)

    elif request.method == "POST":
        symbol = request.form.get("symbol")
        shares = 0

        logging.warning(request.form.get("shares"))
        logging.warning(request.form.get("symbol"))
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("shares must be an integer", 400)

        logging.warning("Passed the first check")
        if shares <= 0:
            return apology('Must be a positive number', 400)
        # get shares

        logging.warning("Passed the second check")

        if shares < 0:
            return apology("shares must be greater than 0", 400)

        userID=session['user_id']

        logging.warning("Passed the third check")

        # get the user's current holdings
        raw = db.execute("SELECT symbol, sum(shareQuantity) as shares from transactions WHERE userID = :userID AND symbol = :symbol GROUP BY symbol",
                        userID=userID, symbol=symbol)

        # get the user's current cash
        row = db.execute("SELECT cash FROM users WHERE id = :id LIMIT 1;", id=session["user_id"])
        cash = row[0]['cash']

        logging.warning("Passed the fourth check")
        if len(raw) == 0:
            logging.warning("Passed the 5th check")
            return apology("You do not own that stock", 400)
        elif int(raw[0]['shares']) < shares:
            logging.warning("Passed the 6th check")
            return apology("Not enough shares", 400)
        else:
            # get "negative" shares
            sellQty = shares * -1
            # get price
            hash = lookup(symbol)
            price = hash['price']
            proceeds = price * shares

            newCash = cash + proceeds

            logging.warning("Passed the 7th check")
            # sell the stock
            db.execute("INSERT INTO Transactions(symbol,sharePrice,shareQuantity,totalCost,userID) VALUES(:symbol, :price, :sellQty,:proceeds,:userID)",
                        symbol=symbol, price=price, sellQty=sellQty, proceeds=proceeds, userID=userID)
            db.execute("UPDATE users SET cash=:cash WHERE id = :userID", userID=userID, cash=newCash)
            return redirect("/sell")

def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
