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
typedef struct Node
{
    bool is_word;
    struct node* children[27];
}
Node;

// freeing the dictionary file from memory (No Memory Leaks)
void unloadNode(char c);

// Will be used for the function Check
int alpha_index(char);



Node *root;
Node *move;

// Prototypes
bool check(const char *word);
{

}


bool load(const char *dictionary);
{

}


unsigned int size(void);
{



}

bool unload(void);
{

}



#endif // DICTIONARY_H
