// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"


typedef struct node
{
    int words_count;
    char **words;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Binary search used to find if the word is in dictionary
bool binary_search(int n, int left, int right, const char *word)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        // Word was found in the middle
        int x = strcasecmp(word, table[n]->words[mid]);
        if (x == 0)
        {
            return true;
        }

        // Search left half
        if (x < 0)
        {
            return binary_search(n, left, mid - 1, word);
        }

        // Search the right half
        return binary_search(n, mid + 1, right, word);
    }

    return false;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int n = hash(word);
    return binary_search(n, 0, table[n]->words_count - 1, word);
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Add "N" nodes to hash table
    for (int i = 0; i < N; i++)
    {
        node *tmp = malloc(sizeof(node));

        tmp->words_count = 0;
        table[i] = tmp;
    }

    char word[LENGTH + 1];

    // Count words by their starting letter
    while (fscanf(file, "%s", word) != EOF)
    {
        int n = hash(word);
        table[n]->words_count++;
    }

    fseek(file, 0, SEEK_SET);

    // Add numbers to arrays and arrays to hash table
    for (int i = 0; i < N; i++)
    {
        if (table[i]->words_count == 0)
        {
            continue;
        }

        char **arr = malloc(table[i]->words_count * sizeof(char *));

        for (int j = 0, x = table[i]->words_count; j < x; j++)
        {
            fscanf(file, "%s", word);
            arr[j] = malloc(strlen(word) + 1);
            strcpy(arr[j], word);
        }
        table[i]->words = arr;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        size += table[i]->words_count;
    }

    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        int x = table[i]->words_count;

        // If the array is not empty
        if (x != 0)
        {
            for (int j = 0; j < x; j++)
            {
                free(table[i]->words[j]);
            }
            free(table[i]->words);
        }
        free(table[i]);
    }

    return true;
}