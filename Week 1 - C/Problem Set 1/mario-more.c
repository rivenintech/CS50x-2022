#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asks user for input (1 - 8)
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Creates pyramid from "#" with the user's height
    for (int i = 0; i < height; i++)
    {
        int spaces = height - i - 1; //Number of spaces (height - row number - 1, because we start counting at 0)
        for (int x = 0; x < spaces; x++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2; j++) // Loops twice because we have to create two pyramids
        {
            for (int y = 0; y <= i; y++)
            {
                printf("#");
            }

            // Add gap between pyramids after creating half of row
            if (j == 0)
            {
                printf("  ");
            }
        }

        printf("\n");
    }
}