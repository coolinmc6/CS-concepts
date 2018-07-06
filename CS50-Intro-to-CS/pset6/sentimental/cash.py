from cs50 import get_int
from cs50 import get_float

while True:
    num = get_float("How much change is owed? ")
    if num > 0:
        break

change = num * 100

coins = 0

while (change >= 25):
    change -= 25
    coins += 1

#print(f"After Quarters: {change} remaining, {coins} required")

while (change  >= 10):
    change -= 10
    coins += 1

#print(f"After Dimes: {change} remaining, {coins} required")

while (change  >= 5):
    change -= 5
    coins += 1

#print(f"After Nickels: {change} remaining, {coins} required")

while (change  >= 1):
    change -= 1
    coins += 1

#print(f"After Pennies: {change} remaining, {coins} required")

print(f"{coins}")