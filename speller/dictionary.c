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

                // closes dict file which is set as a pointer (beg.)
                fclose(dict);

                return true;
            }

            // Positioning needs to be between 0 & 26
            if (pos >=0 && pos <= 26)
            {
                if (move -> children[pos] == NULL)
                {
                    // Move to a new node
                    move -> children[pos] == nullNode(move -> children[pos]);
                }

                // moving the pointe of move towards the next node
                move = move -> children[pos];

            }
        }
        else
        {
            move -> word_exists = true;

            wordCount++;

            // move back to the head(root) node
            move = root;
        }
    }

    // Error Checking
    if (ferror(dict))
    {
        // if there is an error for the word itself close dict. file
        fclose(dict);
        printf("There was an error found!\n");
        return false;
    }

    // Close file
    fclose(dict);

    // if no error was found then word is found
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // dictionary was loaded = return words

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
