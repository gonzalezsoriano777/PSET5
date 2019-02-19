// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45



// Going to be using the Trie method.. structering
typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

// freeing the dictionary file from memory (No Memory Leaks)
void unloadNode(node *move);

// Will be used for the function Check
int indexChar(char);



node *nullNode(node *);

// This is the head of the node
node *root;

// Pointer
node *movee;

// ------------------------------------------


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




// ------------------------------------------



// Prototypes
bool check(const char *word);



bool load(const char *dictionary);



unsigned int size(void);


bool unload(void);




#endif // DICTIONARY_H

/*

Result of words/names found in lalaland.txt

Success on finding the words and going through each function (check, load, size, unload)

Then closing the dict. file in the end of the resul

WORDS MISSPELLED:     955
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        17756
TIME IN load:         0.03
TIME IN check:        0.04
TIME IN size:         0.00
TIME IN unload:       0.02
TIME IN TOTAL:        0.09



*/
