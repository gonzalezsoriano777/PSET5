// Implements a dictionary's functionality

// To Understand the functionality of this Project..

// Load:
// Check:

// Size:
// Unload:


#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

#include "dictionary.h"

// Going to be using the Hash method



// A pointer to an array of HASHTABLES_SIZE, containing the buckets in which the hash will use
node* hashtble[HASHTABLE_SIZE];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    // checks to see if the word is valid and that would include the length of the word itself
    int len = strlen(word);

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
