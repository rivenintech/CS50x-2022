#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // If there isn't exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Read the file
    FILE *file = fopen(argv[1], "r");

    // If the file couldn't be opened
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[512];
    char filename[8];
    FILE *img = NULL;
    int n = 0;

    while (fread(&buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check if the first 4 bytes match the JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If any file was already opened - close it
            if (n != 0)
            {
                fclose(img);
            }

            // Create new file
            sprintf(filename, "%03i.jpg", n);
            img = fopen(filename, "w");
            n++;
        }

        // Write data to output file (if the first file was already opened)
        if (n != 0)
        {
            fwrite(&buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close files
    fclose(img);
    fclose(file);
    return 0;
}