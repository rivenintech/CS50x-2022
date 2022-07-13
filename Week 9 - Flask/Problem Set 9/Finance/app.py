import os
import time

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Get user's cash
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    # Get all stocks owned by user
    stocks = db.execute(
        "SELECT symbol, SUM(shares) AS shares FROM transactions WHERE username_id = ? GROUP BY symbol HAVING SUM(shares) > 0", session["user_id"])

    # Total value (stocks + cash)
    total = cash

    # Get price for each stock and calculate total value
    for index, i in enumerate(stocks):
        stock = lookup(i["symbol"])
        i["name"] = stock["name"]
        i["price"] = stock["price"]
        x = stock["price"] * i["shares"]
        i["total"] = x
        total += x

        stocks[index] = i

    return render_template("index.html", stocks=stocks, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        date = time.strftime('%Y-%m-%d %H:%M:%S')

        # Ensure shares' amount is valid
        try:
            shares = int(request.form.get("shares"))

            if shares < 1:
                raise ValueError
        except ValueError:
            return apology("Invalid amount", 400)

        # Ensure symbol was submitted
        if not symbol:
            return apology("Missing symbol", 400)

        # Check if symbol is valid
        share = lookup(symbol)

        if not share:
            return apology("Invalid symbol", 400)

        # Calculate total price
        price = share["price"] * shares

        # Check if user has enough cash to buy shares
        cash = db.execute("SELECT cash FROM users WHERE id = ? AND cash >= ?", session["user_id"], price)

        if not cash:
            return apology("Not enough cash", 400)

        # Update user's cash
        db.execute("UPDATE users SET cash=cash - ? WHERE id=?", price, session["user_id"])

        # Buy stock
        db.execute("INSERT INTO transactions (username_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                   session["user_id"], share["symbol"], shares, share["price"], date)

        flash("Bought!")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        # Get user's cash
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        return render_template("buy.html", cash=cash)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Get all transactions made by user
    stocks = db.execute("SELECT * FROM transactions WHERE username_id = ? ORDER BY date DESC", session["user_id"])

    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

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
    """Get stock quote."""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        symbol = request.form.get("symbol")

        # Ensure symbol was submitted
        if not symbol:
            return apology("Missing symbol", 400)

        # Check if symbol is valid
        share = lookup(symbol)

        if not share:
            return apology("Invalid symbol", 400)

        # Render template with share's data
        return render_template("quoted.html", share=share, price=usd(share["price"]))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        username = request.form.get("username")

        # Ensure username was submitted
        if not username:
            return apology("Must provide username", 400)

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("Must provide password", 400)

        # Check if passwords match
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords don't match", 400)

        # Query database for username (check if username already exists)
        if db.execute("SELECT * FROM users WHERE username = ?", username):
            return apology("Username already taken", 400)

        password = generate_password_hash(request.form.get("password"))

        # Insert user
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, password)

        # Get ID of inserted user
        rows = db.execute("SELECT id FROM users WHERE username = ? AND hash = ?", username, password)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        date = time.strftime('%Y-%m-%d %H:%M:%S')

        # Ensure shares is valid
        try:
            shares = int(request.form.get("shares"))

            if shares < 1:
                raise ValueError
        except ValueError:
            return apology("Invalid amount", 400)

        # Ensure symbol was submitted
        if not symbol:
            return apology("Missing symbol", 400)

        # Check if user has enough stocks to sell
        stock = db.execute("SELECT * FROM transactions WHERE username_id = ? AND symbol = ? GROUP BY symbol HAVING SUM(shares) >= ?",
                           session["user_id"], symbol, shares)

        if not stock:
            return apology("You don't have this amount of stocks", 400)

        # Lookup stock's price
        price = lookup(symbol)["price"]

        # Sell stock
        db.execute("INSERT INTO transactions (username_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                   session["user_id"], symbol, shares * -1, price, date)

        # Update user's cash
        db.execute("UPDATE users SET cash=cash + ? WHERE id=?", price * shares, session["user_id"])

        flash("Sold!")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        # Get all stocks owned by user
        stocks = db.execute(
            "SELECT symbol, SUM(shares) AS shares FROM transactions WHERE username_id = ? GROUP BY symbol HAVING SUM(shares) > 0", session["user_id"])

        # Get price for each stock and calculate total value
        for index, i in enumerate(stocks):
            stock = lookup(i["symbol"])
            i["name"] = stock["name"]
            i["price"] = stock["price"]
            i["total"] = stock["price"] * i["shares"]

            stocks[index] = i

        return render_template("sell.html", stocks=stocks)


@app.route("/change_password", methods=["GET", "POST"])
def change_password():
    """Give option to change password"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        if not request.form.get("old-password"):
            return apology("must provide old password", 400)

        # Ensure password was submitted
        if not request.form.get("new-password"):
            return apology("must provide new password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and old password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("old-password")):
            return apology("invalid username and/or old password", 400)

        # Create hash from new password and update user's password
        password = generate_password_hash(request.form.get("new-password"))
        db.execute("UPDATE users SET hash=? WHERE username=?", password, request.form.get("username"))

        # Forget any user_id
        session.clear()

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("change_password.html")