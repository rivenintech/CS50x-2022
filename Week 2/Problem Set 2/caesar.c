#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Checks if there is only one command-line argument and if it's number
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); // Converts string to int
    string plain = get_string("Plaintext: ");

    //Loops through the word, printing ciphered text
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        printf("%c", rotate(plain[i], key));
    }
    printf("\n");
}

// Checks if everything in string is a digit
bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

// Cipheres every letter
char rotate(char c, int key)
{
    int n = 0;
    if (isalpha(c)) // Checks if it's a letter
    {
        if isupper(c) // If it's uppercase ("A" is 65 in ASCII)
        {
            n = 65;
        }
        else
        {
            n = 97; // ("a" is 97 in ASCII)
        }

        c = (c - n + key) % 26 + n;
    }
    return c;
}