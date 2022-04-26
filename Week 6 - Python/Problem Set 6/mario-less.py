from cs50 import get_int

# Ask for input until its valid (int and 1-8)
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Print hashes with whitespace to align it correctly by using rjust method
for i in range(1, height + 1):
    print(("#" * i).rjust(height))