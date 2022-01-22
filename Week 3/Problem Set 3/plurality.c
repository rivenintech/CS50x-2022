#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare given name with candidates
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    string winners[MAX];
    int index = 0;

    // Searching for candidate with most votes
    for (int i = 0, most_votes = 0; i < candidate_count; i++)
    {
        // Checking if candidate has more votes than the current biggest votes value
        if (candidates[i].votes > most_votes)
        {
            most_votes = candidates[i].votes;
            winners[0] = candidates[i].name; // Overwriting person that had most votes
            index = 1; // Changing index to 1 to make space for next person with the same number of votes
        }
        // Checking if other candidate has the same number of votes
        else if (candidates[i].votes == most_votes)
        {
            winners[index] = candidates[i].name;
            index++;
        }
    }

    // Printing winners
    for (int j = 0; j < index; j++)
    {
        printf("%s\n", winners[j]);
    }
    return;
}