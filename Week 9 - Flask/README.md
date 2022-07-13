# [Week 9](https://cs50.harvard.edu/x/2022/weeks/9/)

## [Lab 9](https://cs50.harvard.edu/x/2022/labs/9/)

### [Birthdays](https://cs50.harvard.edu/x/2022/labs/9/)

Complete the implementation of a web application to let users store and keep track of birthdays.

- When the `/` route is requested via `GET`, your web application should display, in a table, all of the people in your database along with their birthdays.
    - First, in app.py, add logic in your `GET` request handling to query the `birthdays.db` database for all birthdays. Pass all of that data to your `index.html` template.
    - Then, in `index.html`, add logic to render each birthday as a row in the table. Each row should have two columns: one column for the person’s name and another column for the person’s birthday.
- When the `/` route is requested via `POST`, your web application should add a new birthday to your database and then re-render the index page.
    - First, in `index.html`, add an HTML form. The form should let users type in a name, a birthday month, and a birthday day. Be sure the form submits to `/` (its “action”) with a method of `post`.
    - Then, in `app.py`, add logic in your `POST` request handling to `INSERT` a new row into the `birthdays` table based on the data supplied by the user.

----
<br>

## [Problem Set 9](https://cs50.harvard.edu/x/2022/psets/9/)

### [Finance](https://cs50.harvard.edu/x/2022/psets/9/finance/)

#### `register`
Complete the implementation of `register` in such a way that it allows a user to register for an account via a form.

- Require that a user input a username, implemented as a text field whose `name` is `username`. Render an apology if the user’s input is blank or the username already exists.
- Require that a user input a password, implemented as a text field whose `name` is `password`, and then that same password again, implemented as a text field whose `name` is `confirmation`. Render an apology if either input is blank or the passwords do not match.
- Submit the user’s input via `POST` to `/register`.
- `INSERT` the new user into `users`, storing a hash of the user’s password, not the password itself. Hash the user’s password with `generate_password_hash`. Odds are you’ll want to create a new template (e.g., `register.html`) that’s quite similar to `login.html`.

#### `quote`
Complete the implementation of `quote` in such a way that it allows a user to look up a stock’s current price.

- Require that a user input a stock’s symbol, implemented as a text field whose `name` is `symbol`.
- Submit the user’s input via `POST` to `/quote`.
- Odds are you’ll want to create two new templates (e.g., `quote.html` and `quoted.html`). When a user visits `/quote` via GET, render one of those templates, inside of which should be an HTML form that submits to `/quote` via `POST`. In response to a `POST`, `quote` can render that second template, embedding within it one or more values from `lookup`.

#### `buy`
Complete the implementation of `buy` in such a way that it enables a user to buy stocks.

- Require that a user input a stock’s symbol, implemented as a text field whose `name` is `symbol`. Render an apology if the input is blank or the symbol does not exist (as per the return value of `lookup`).
- Require that a user input a number of shares, implemented as a field whose `name` is `shares`. Render an apology if the input is not a positive integer.
- Submit the user’s input via `POST` to `/buy`.
- Odds are you’ll want to call `lookup` to look up a stock’s current price.
- Odds are you’ll want to `SELECT` how much cash the user currently has in `users`.
- Add one or more new tables to `finance.db` via which to keep track of the purchase. Store enough information so that you know who bought what at what price and when.
    - Use appropriate SQLite types.
    - Define `UNIQUE` indexes on any fields that should be unique.
    - Define (non-`UNIQUE`) indexes on any fields via which you will search (as via `SELECT` with `WHERE`).
- Render an apology, without completing a purchase, if the user cannot afford the number of shares at the current price.
- You don’t need to worry about race conditions (or use transactions).

#### `index`
Complete the implementation of `index` in such a way that it displays an HTML table summarizing, for the user currently logged in, which stocks the user owns, the numbers of shares owned, the current price of each stock, and the total value of each holding (i.e., shares times price). Also display the user’s current cash balance along with a grand total (i.e., stocks’ total value plus cash).

- Odds are you’ll want to execute multiple `SELECT`s. Depending on how you implement your table(s), you might find GROUP BY HAVING SUM and/or WHERE of interest.
- Odds are you’ll want to call `lookup` for each stock.

#### `sell`
Complete the implementation of `sell` in such a way that it enables a user to sell shares of a stock (that he or she owns).

- Require that a user input a stock’s symbol, implemented as a `select` menu whose `name` is `symbol`. Render an apology if the user fails to select a stock or if (somehow, once submitted) the user does not own any shares of that stock.
- Require that a user input a number of shares, implemented as a field whose `name` is `shares`. Render an apology if the input is not a positive integer or if the user does not own that many shares of the stock.
- Submit the user’s input via `POST` to `/sell`.
- You don’t need to worry about race conditions (or use transactions).

#### `history`
Complete the implementation of `history` in such a way that it displays an HTML table summarizing all of a user’s transactions ever, listing row by row each and every buy and every sell.

- For each row, make clear whether a stock was bought or sold and include the stock’s symbol, the (purchase or sale) price, the number of shares bought or sold, and the date and time at which the transaction occurred.
- You might need to alter the table you created for `buy` or supplement it with an additional table. Try to minimize redundancies.

#### `personal touch`
Implement at least one personal touch of your choice:

- Allow users to change their passwords.
- Allow users to add additional cash to their account.
- Allow users to buy more shares or sell shares of stocks they already own via index itself, without having to type stocks’ symbols manually.
- Require users’ passwords to have some number of letters, numbers, and/or symbols.
- Implement some other feature of comparable scope.


[*Source*](https://cs50.harvard.edu/x/2022/weeks/9/)