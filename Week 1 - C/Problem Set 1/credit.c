#include <cs50.h>
#include <stdio.h>

string validation(long card_number);

int main(void)
{
    string verify = validation(get_long("Number: "));
    printf("%s\n", verify);
}

string validation(long card_number)
{
    // Default Values
    int two_num = 0;
    int sum1 = 0;
    int sum2 = 0;
    int i = 0;
    int lenght = 0;

    while (card_number != 0)
    {
        // Adds one to card lenght
        lenght += 1;

        // Saves two first numbers to check card type later
        if (card_number < 100 && card_number > 10)
        {
            two_num = card_number;
        }

        // Adds numbers (once to sum1, then to sum2, and so on)
        if (i == 0)
        {
            sum1 += card_number % 10; // Adds last digit from card number
            i = 1;
        }
        else
        {
            int n = card_number % 10 * 2; // Last digit from card number is multiplied by two
            if (n >= 10) // If the multiplied number has two digits - splits it
            {
                n = (n % 10) + ((n - (n % 10)) / 10); // Adds two digits
            }
            sum2 += n;
            i = 0;
        }

        card_number /= 10; // Removes last digit
    }

    string valid = "INVALID";

    // If the card is valid, then it checks the brand - lenght and first two numbers (only first number if VISA)
    if ((sum1 + sum2) % 10 == 0)
    {
        if ((two_num >= 51 && two_num <= 55) && (lenght == 16))
        {
            valid = "MASTERCARD";
        }
        else if ((two_num == 34 || two_num == 37) && (lenght == 15))
        {
            valid = "AMEX";
        }
        else if ((((two_num - (two_num % 10)) / 10) == 4) && (lenght == 13 || lenght == 16))
        {
            valid = "VISA";
        }
    }

    return valid;
}