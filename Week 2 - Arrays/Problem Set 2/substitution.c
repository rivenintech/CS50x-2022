#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check_key(int c, string argv[]);
char cipher(char c, string key);

int main(int argc, string argv[])
{
    if (check_key(argc, argv) == false)
    {
        return 1;
    }

    string plain = get_string("plaintext: ");
    string key = argv[1];

    //Loops through the word, printing ciphered text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        printf("%c", cipher(plain[i], key));
    }
    printf("\n");
}


bool check_key(int argc, string argv[])
{
    // Checks if there is only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    string key = argv[1];
    int n = strlen(key);

    // Checks if key is 26 characters long
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        // Check if key containts any character that is not a letter
        if (isdigit(key[i]) != 0)
        {
            printf("Key contains character that is not a letter.\n");
            return false;
        }

        // Checks if a key contains the same character multiple times (counting each occurrence of a letter)
        int x = 0;
        for (int j = 0; j < n; j++)
        {
            if (toupper(key[i]) == toupper(key[j])) // Forcing letters to uppercase
            {
                x++;
                if (x == 2)
                {
                    printf("Key contains same letter multiple times\n");
                    return false;
                }
            }
        }
    }
    return true;
}

// Cipheres every letter
char cipher(char c, string key)
{
    if (isalpha(c)) // Checks if it's a letter
    {
        if isupper(c) // If it's uppercase ("A" - 65, "a" - 97 in ASCII)
        {
            c = toupper(key[c - 65]); // Forcing to uppercase if the "key" is in lowercase
        }
        else
        {
            c = tolower(key[c - 97]); // Forcing to lowercase if the "key" is in uppercase
        }
    }
    return c;
}