# [Week 6](https://cs50.harvard.edu/x/2022/weeks/6/)

## [Lab 6](https://cs50.harvard.edu/x/2022/labs/6/)

### [World Cup](https://cs50.harvard.edu/x/2022/labs/6/)

Complete the implementation of `tournament.py`, such that it simulates a number of tournaments and outputs each team’s probability of winning.

First, in `main`, read the team data from the CSV file into your program’s memory, and add each team to the list `teams`.

- The file to use will be provided as a command-line argument. You can access the name of the file, then, with `sys.argv[1]`.
- Recall that you can open a file with `open(filename)`, where `filename` is a variable storing the name of the file.
- Once you have a file `f`, you can use `csv.DictReader(f)` to give you a “reader”: an object in Python that you can loop over to read the file one row at a time, treating each row as a dictionary.
- By default, all values read from the file will be strings. So be sure to first convert the team’s `rating` to an `int` (you can use the `int` function in Python to do this).
- Ultimately, append each team’s dictionary to `teams`. The function call `teams.append(x)` will append `x` to the list `teams`.
- Recall that each team should be a dictionary with a `team` name and a `rating`.

Next, implement the `simulate_tournament` function. This function should accept as input a list of teams and should repeatedly simulate rounds until you’re left with one team. The function should the return the name of that team.

- You can call the `simulate_round` function, which simulates a single round, accepting a list of teams as input and returning a list of all of the winners.
- Recall that if `x` is a list, you can use `len(x)` to determine the length of the list.
- You should not assume the number of teams in the tournament, but you may assume it will be a power of 2.

Finally, back in the `main` function, run `N` tournament simulations, and keep track of how many times each team wins in the `counts` dictionary.

For example, if Uruguay won 2 tournaments and Portugal won 3 tournaments, then your `counts` dictionary should be `{"Uruguay": 2, "Portugal": 3}`.
You should use your `simulate_tournament` to simulate each tournament and determine the winner.
Recall that if `counts` is a dictionary, then syntax like `counts[team_name] = x` will associate the key stored in `team_name` with the value stored in `x`.
You can use the `in` keyword in Python to check if a dictionary has a particular key already. For example, `if "Portugal" in counts:` will check to see if `"Portugal"` already has an existing value in the `counts` dictionary.

----
<br>

## [Problem Set 6](https://cs50.harvard.edu/x/2022/psets/6/)

### [Hello](https://cs50.harvard.edu/x/2022/psets/6/hello/)

Write, in a file called `hello.py`, a program that prompts a user for their name, and then prints `hello, so-and-so`, where `so-and-so` is their provided name, exactly as you did in [Problem Set 1](https://cs50.harvard.edu/x/2022/psets/1/), except that your program this time should be written in Python.

----

### [Mario-less](https://cs50.harvard.edu/x/2022/psets/6/mario/less/)

<img src="https://raw.githubusercontent.com/RiveN000/CS50-2022/main/Week%201/assets/pyramid.png" alt="Mario level screenshot">

Implement a program that prints out a half-pyramid of a specified height, per the below.

```python
$ ./mario
Height: 4
   #
  ##
 ###
####
```

- Write, in a file called `mario-less.py`, a program that recreates the half-pyramid using hashes (`#`) for blocks, exactly as you did in [Problem Set 1](https://cs50.harvard.edu/x/2022/psets/1/), except that your program this time should be written in Python.
- To make things more interesting, first prompt the user with `get_int` for the half-pyramid’s height, a positive integer between `1` and `8`, inclusive.
- If the user fails to provide a positive integer no greater than `8`, you should re-prompt for the same again.
- Then, generate (with the help of `print` and one or more loops) the desired half-pyramid.
- Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.

----

### [Mario-more](https://cs50.harvard.edu/x/2022/psets/6/mario/less/)

<img src="https://raw.githubusercontent.com/RiveN000/CS50-2022/main/Week%201/assets/pyramids.png" alt="Mario level screenshot">

Implement a program that prints out a half-pyramid of a specified height, per the below.

```python
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

- Write, in a file called `mario-more.py`, a program that recreates these half-pyramids using hashes (`#`) for blocks, exactly as you did in [Problem Set 1](https://cs50.harvard.edu/x/2022/psets/1/), except that your program this time should be written in Python.
- To make things more interesting, first prompt the user with `get_int` for the half-pyramid’s height, a positive integer between `1` and `8`, inclusive. (The height of the half-pyramids pictured above happens to be `4`, the width of each half-pyramid `4`, with a gap of size `2` separating them).
- If the user fails to provide a positive integer no greater than `8`, you should re-prompt for the same again.
- Then, generate (with the help of `print` and one or more loops) the desired half-pyramids.
- Take care to align the bottom-left corner of your pyramid with the left-hand edge of your terminal window, and ensure that there are two spaces between the two pyramids, and that there are no additional spaces after the last set of hashes on each row.

----

### [Cash](https://cs50.harvard.edu/x/2022/psets/6/cash/)

Implement a program that calculates the minimum number of coins required to give a user change.

- Write, in a file called `cash.py`, a program that first asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made. You can do this exactly as you did in [Problem Set 1](https://cs50.harvard.edu/x/2022/psets/1/), except that your program this time should be written in Python, and you should assume that the user will input their change in dollars (e.g., 0.50 dollars instead of 50 cents).
- Use get_float from the CS50 Library to get the user’s input and `print` to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
    - We ask that you use `get_float` so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be `9.75` and not `$9.75` or `975`. However, if some customer is owed $9 exactly, assume that your program’s input will be `9.00` or just `9` but, again, not `$9` or `900`. Of course, by nature of floating-point values, your program will likely work with inputs like `9.0` and `9.000` as well; you need not worry about checking whether the user’s input is “formatted” like money should be.
- If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.
- Incidentally, so that we can automate some tests of your code, we ask that your program’s last line of output be only the minimum number of coins possible: an integer followed by a newline.

----

### [Credit](https://cs50.harvard.edu/x/2022/psets/6/credit/)

Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

- In `credit.py`, write a program that prompts the user for a credit card number and then reports (via `print`) whether it is a valid American Express, MasterCard, or Visa card number, exactly as you did in [Problem Set 1](https://cs50.harvard.edu/x/2022/psets/1/), except that your program this time should be written in Python.
- So that we can automate some tests of your code, we ask that your program’s last line of output be `AMEX\n` or `MASTERCARD\n` or `VISA\n` or `INVALID\n`, nothing more, nothing less.
- For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).
- Best to use `get_int` or `get_string` from CS50’s library to get users’ input, depending on how you to decide to implement this one.

----

### [Readability](https://cs50.harvard.edu/x/2022/psets/6/readability/)

Implement a program that computes the approximate grade level needed to comprehend some text.

- Write, in a file called `readability.py`, a program that first asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula, exactly as you did in [Problem Set 2](https://cs50.harvard.edu/x/2022/psets/2/), except that your program this time should be written in Python.
    - Recall that the Coleman-Liau index is computed as `0.0588 * L - 0.296 * S - 15.8`, where `L` is the average number of letters per 100 words in the text, and `S` is the average number of sentences per 100 words in the text.
- Use `get_string` from the CS50 Library to get the user’s input, and `print` to output your answer.
- Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from `a` to `z` or any uppercase character from `A` to `Z`, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
- Your program should print as output `"Grade X"` where `X` is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
- If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output `"Grade 16+"` instead of giving the exact index number. If the index number is less than 1, your program should output `"Before Grade 1"`.

----

### [DNA](https://cs50.harvard.edu/x/2022/psets/6/dna/)

In a file called `dna.py`, implement a program that identifies to whom a sequence of DNA belongs.

- The program should require as its first command-line argument the name of a CSV file containing the STR counts for a list of individuals and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.
    - If your program is executed with the incorrect number of command-line arguments, your program should print an error message of your choice (with `print`). If the correct number of arguments are provided, you may assume that the first argument is indeed the filename of a valid CSV file and that the second argument is the filename of a valid text file.
- Your program should open the CSV file and read its contents into memory.
    - You may assume that the first row of the CSV file will be the column names. The first column will be the word `name` and the remaining columns will be the STR sequences themselves.
- Your program should open the DNA sequence and read its contents into memory.
- For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats of the STR in the DNA sequence to identify. Notice that we’ve defined a helper function for you, `longest_match`, which will do just that!
- If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
    - You may assume that the STR counts will not match more than one individual.
    - If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print `No match`.


[*Source*](https://cs50.harvard.edu/x/2022/weeks/6/)