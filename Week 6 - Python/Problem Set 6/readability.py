from cs50 import get_string
import string

# Some default values
letters = set(string.ascii_lowercase)
letter_count = 0
word_count = 1
sentence_count = 0

# Get text from user
text = get_string("Text: ").lower()

# Loop through the whole text and do calculations
for i in text:
    if i in letters:
        letter_count += 1
    elif i == " ":
        word_count += 1
    elif i in ("!", "?", "."):
        sentence_count += 1

# Coleman-Liau formula
index = round(0.0588 * (letter_count / word_count * 100) - 0.296 * (sentence_count / word_count * 100) - 15.8)

# Printing grade
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")