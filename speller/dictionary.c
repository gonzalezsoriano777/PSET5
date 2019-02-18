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

    int incorrect_word = 0;
    int pos = 0;

     // setting the address of move to Node(head)
    move = root;

    for(int i = 0; i < strlen(word); i++)
    {
        // finding the position of each letter
        pos = indexChar(word[i]);

        if (move -> children[pos] == NULL)
        {
            incorrect_word++

            // exit function
            return false;
        }
        else
        {
            // Next Letter , referred to as the next position of children array
            move = move -> children[pos];
        }
    }

    // Next case: if true, then word is in dictionary
    if (move -> word_exists)
        return true;


    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, 'r');

    if (dict == NULL)
    {
        printf("Sorry for the inconvenience, dictionary could not be opened\n");

        return false;

    }

    // Keeps index for the current user
    int position = 0;
    char letter;

    root = nullNode(move);
    move = root;


    //  Load every word from dictionary
    while(true)
    {
        letter = fgetc(dict);

        pos = indexChar(letter);

        if (letter != '\n')
        {
            // indicated the end of file
            if (feof(dict))
            {

                // pointer is set to the word
                move -> word_exists = true;

                fclose(dict);

                return true;
            }

        }


    }

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
