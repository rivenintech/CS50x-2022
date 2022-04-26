from cs50 import get_string

# Numbers lists
a = 0
b = 0

# Get user's card number
number = get_string("Number: ")

# Some values
reverse = number[::-1]
length = len(number)

# Loop through number and add numbers once to a once to b
for i in range(length):
    n = int(reverse[i])

    if i % 2 == 0:
        a += n
    else:
        n *= 2

        # If "n" is two digits long, split it and add
        if n >= 10:
            n = (n % 10) + (n // 10)

        b += n

total = (a + b) % 10

# If last digit in total isn't 0, card is invalid
if total != 0:
    print("INVALID")
    exit()

# Check card brand
if int(number[:2]) in (51, 52, 53, 54, 55) and length == 16:
    print("MASTERCARD")
elif int(number[:2]) in (34, 37) and length == 15:
    print("AMEX")
elif int(number[0]) == 4 and length in (13, 16):
    print("VISA")