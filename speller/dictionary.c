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
                move -> is_word = true;

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
    // if dictionary was loaded = return word/words
    if (&load)
    return wordCount;

    else
        return 0;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
   // freeing up the memory in node
   unloadNode(root);
   return true;

}

// This function accpets node pointer
void unloadNode(node *move)
{

     for (int i = 0; i < 27; i++)
     {

         // Pointer set to children
         if (move -> children[i])
             unloadNode(move -> children[i]);

     }
     free(move);
}

// This will be for letter positioning starting at the index
int indexChar(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return letter - 'a';
    else if (letter >= 'A' && letter <= 'Z')
        return letter - 'A';
    else
        return 26;

}

node *nullNode(node *nodePointer)
{
    nodePointer = malloc(sizeof(node));

    // If the pointer is NULL, return NULL
    if (nodePointer == NULL)
    return NULL;

    // children node = null
    for (int i = 0; i < 27; i++)
        nodePointer -> children[i] = NULL;

    nodePointer -> is_word = false;

    // return the node
    return nodePointer;

}
