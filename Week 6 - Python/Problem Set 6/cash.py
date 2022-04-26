from cs50 import get_float

coins = [25, 10, 5, 1]
count = 0

# Ask for input until its valid (positive number)
while True:
    cash = get_float("Change owed: ")

    if cash >= 0:
        break

# Converting to cents
cents = cash * 100

# Looping through all types of coins
for coin in coins:
    num = cents // coin
    cents -= num * coin
    count += num

print(int(count))