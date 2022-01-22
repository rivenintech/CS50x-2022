#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
float count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    float words = count_words(text);
    int sentences = count_sentences(text);

    int index = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}


int count_letters(string text)
{
    // Looping through word
    int counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char letter = toupper(text[i]); // Forces all characters to uppercase
        if (letter >= 'A' && letter <= 'Z') // Checks if it's a letter
        {
            counter++; // If it is, then increase counter
        }
    }
    return counter;
}

float count_words(string text)
{
    // Looping through word
    float counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((int) text[i] != 32) // If character is different than space
        {
            counter++;

            while (i < n && (int) text[i + 1] != 32) // Loop to the next space
            {
                i++;
            }
        }
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int t = text[i];
        if (t == 46 || t == 33 || t == 63) // Checking if it's "?", "!" or "."
        {
            int p = text[i - 1];
            if (p != 46 && p != 33 && p != 63) // If previous character different than "?", "!" or "." (avoiding "...", etc.)
            {
                counter++;
            }
        }
    }
    return counter;
}