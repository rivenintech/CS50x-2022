from cs50 import get_int

# Ask for input until its valid (int and 1-8)
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Print hashes and align it correctly by printing enough whitespaces first
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print(f"{'#' * i}  {'#' * i}")