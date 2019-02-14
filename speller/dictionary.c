// Implements a dictionary's functionality

// To Understand the functionality of this Project..

// Load: Loads up the dictionary file ( for each word in dictionary text file, store into dict. data structure )

// Check: Checks each and every word inserted, Case-Sensitive..
/* checks the string with only alphabetical letter and/or astrophes */

// Size: Returns the number of words that would be identical to the word inserted..
/* If Loaded */

// Unload: Removes Dictionary from Memory

// -----------------------------------------------------

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"


unsigned int wordCount = 0;

// ------------------------------------------------------


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *current_node = root;

    for(int i = 0; len = strlen(word); i < len; i++)
    {
        int index
    }



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
