# Python and Flask Notes

- this is a collection of random bits of code

- Grabbing a variable from a POST request

```python
# Raw POST request value
request.form.get("symbol")

# Creating a variable
symbol = request.form.get("symbol")
```

- Specifying actions to take depending on request type (i.e. GET or POST)

```python
if request.method == "POST":
	#
	# CODE
	#
elif request.method == "GET":
	#
	# CODE
	#
else:
	#
	# CODE
	#

```

- Passing form variables into a template:

```python
if request.method == "POST":
        symbol = request.form.get("symbol")
        hash = lookup(symbol)

        return render_template("quoted.html", hash=hash)
```

- Using that variable in your template:

```python
# it's pretty easy: I just have to wrap my python code in the {% %}, similar to PHP
{% print(hash) %}
```

- Using the `generate_password_hash()` from the werkzeug library

```python
# at the top of your flask file
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

# in your code
passHash = generate_password_hash(password,method='pbkdf2:sha256', salt_length=8)
```

- Creating a dictionary and print values from dictionaries

```python
# pretty similar to JavaScript
obj = {
    'symbol': stock['symbol'],  # notice that I can't use dot notation (at least not in my IDE)
    'price': price,
    'shares': stock['shares'],
    'value': price * stock['shares']
}
```

- Log items to console

```python
# import at the top of file
import logging

# you can log a list
logging.warning(raw) # [{'symbol': 'AAPL', 'shares': 2}, {'symbol': 'MSFT', 'shares': 3}]

# ...or just a number
logging.warning(cash) # 49,550.34

```

### SQL

#### INSERT

```python
# SQL is just like all SQL; nothing crazy there
# escaped / parametered variables have the ":" and then the placeholder name
# the remaining arguments after the statement are the key-value pairs
# 	username=username 	=> the first one is the ":username" and the second is a variable
# 	hash=passHash 		=> hash is the ":hash" and passHash is a variable

db.execute("INSERT INTO users(username, hash, cash) VALUES(:username, :hash, 50000)",
                                username=username, hash=passHash )

```

#### SELECT

- Running a `SELECT` statement and then using the information from the results

```python
# SQL statement is first argument, bounded parameter is second argument
rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

# This particular statement returns one row
# Like PHP, it's an array of objects. So an array of length 1 with a hash/dictionary/object
# with multiple key-value pairs
session["user_id"] = rows[0]["id"]
```


