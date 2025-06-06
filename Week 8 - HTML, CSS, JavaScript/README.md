# [Week 8](https://cs50.harvard.edu/x/2022/weeks/8/)

## [Lab 8](https://cs50.harvard.edu/x/2022/labs/8/)

### [Trivia](https://cs50.harvard.edu/x/2022/labs/8/)

Design a webpage using HTML, CSS, and JavaScript to let users answer trivia questions.

- In `index.html`, add beneath “Part 1” a multiple-choice trivia question of your choosing with HTML.
    - You should use an `h3` heading for the text of your question.
    - You should have one `button` for each of the possible answer choices. There should be at least three answer choices, of which exactly one should be correct.
- Using JavaScript, add logic so that the buttons change colors when a user clicks on them.
    - If a user clicks on a button with an incorrect answer, the button should turn red and text should appear beneath the question that says “Incorrect”.
    - If a user clicks on a button with the correct answer, the button should turn green and text should appear beneath the question that says “Correct!”.
- In `index.html`, add beneath “Part 2” a text-based free response question of your choosing with HTML.
    - You should use an `h3` heading for the text of your question.
    - You should use an `input` field to let the user type a response.
    - You should use a `button` to let the user confirm their answer.
- Using JavaScript, add logic so that the text field changes color when a user confirms their answer.
    - If the user types an incorrect answer and presses the confirmation button, the text field should turn red and text should appear beneath the question that says “Incorrect”.
    - If the user types the correct answer and presses the confirmation button, the input field should turn green and text should appear beneath the question that says “Correct!”.

----
<br>

## [Problem Set 8](https://cs50.harvard.edu/x/2022/psets/8/)

### [Homepage](https://cs50.harvard.edu/x/2022/psets/8/homepage/)

Implement in your `homepage` directory a website that must:

- Contain at least four different `.html` pages, at least one of which is `index.html` (the main page of your website), and it should be possible to get from any page on your website to any other page by following one or more hyperlinks.
- Use at least ten (10) distinct HTML tags besides `<html>`, `<head>`, `<body>`, and `<title>`. Using some tag (e.g., `<p>`) multiple times still counts as just one (1) of those ten!
- Integrate one or more features from Bootstrap into your site. Bootstrap is a popular library (that comes with lots of CSS classes and more) via which you can beautify your site. See Bootstrap’s documentation to get started. In particular, you might find some of Bootstrap’s components of interest. To add Bootstrap to your site, it suffices to include

```html
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
```

in your pages’ `<head>`, below which you can also include

```html
<link href="styles.css" rel="stylesheet">
```

to link your own CSS.
- Have at least one stylesheet file of your own creation, `styles.css`, which uses at least five (5) different CSS selectors (e.g. tag (`example`), class (`.example`), or ID (`#example`)), and within which you use a total of at least five (5) different CSS properties, such as `font-size`, or `margin`
- Integrate one or more features of JavaScript into your site to make your site more interactive. For example, you can use JavaScript to add alerts, to have an effect at a recurring interval, or to add interactivity to buttons, dropdowns, or forms. Feel free to be creative!
- Ensure that your site looks nice on browsers both on mobile devices as well as laptops and desktops.


[*Source*](https://cs50.harvard.edu/x/2022/weeks/8/)