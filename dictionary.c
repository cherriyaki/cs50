// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// define node structure as node
typedef struct node
{
    char word[LENGTH+1];
    struct node* nextp;
}
node;

// prototypes
int findind(const char array[LENGTH+1]);

// define array (hashtable) of node pointers, with 26 buckets for each alphabet
node* nodepa[26] = {NULL};

// Loads dictionary into memory, returning true if successful. else false
bool load(const char *dictionary)
{
    // define dictionary file pointer for fscanf
    FILE* dictfp = fopen(dictionary, "r");

    // define array for dict word
    char dword[LENGTH+1];

    // scan each word in the dictionary until the end
    while (fscanf(dictfp, "%s", dword) != EOF)
    {
        // make new node to store word
        node* newnodep = malloc(sizeof(node));

        // set next pointer in new node to NULL
        newnodep->nextp = NULL;

        // if new node doesn't exist, unload dict and return false
        if (newnodep == NULL)
        {
            unload();
            return false;
        }

        // copy word into new node
        strcpy(newnodep->word, dword);

        // determine hashtable index the word belongs to
        int arrind = findind(dword);

        // if there's at least one existing node in linked list
        if (nodepa[arrind] != NULL)
        {
            // link new node to previous head node
            newnodep->nextp = nodepa[arrind];
        }

        // link previous head node ptr to new node
        nodepa[arrind] = newnodep;
    }

    // close dict file pointer
    fclose(dictfp);

    // success
    return true;
}

// Returns true if word is in dictionary. else false
bool check(const char *word)
{
    // define node pointer called cursor that will jump node to node
    node* cursor = nodepa[findind(word)];

    // only while cursor is pointing to a node
    while (cursor != NULL)
    {
        // if text word and dictionary word are equal
        if (strcasecmp(word, cursor->word) == 0)
        {
            // success
            return true;
        }

        // else, let cursor point to next node
        else
        {
            cursor = cursor->nextp;
        }
    }

    // if true had not been returned and we've passed the last node
    return false;
}

// Returns number of words in dictionary if loaded. else 0 if not yet loaded
unsigned int size(void)
{
    // define positive int for counting
    unsigned int count = 0;

    // go through all elements in the array
    for (int n = 0; n < 26; n++)
    {
        // define cursor pointing to first node
        node* cursor = nodepa[n];

        // while cursor is pointing to a node
        while (cursor != NULL)
        {
            // increase count by 1
            count++;

            // let cursor point to next node
            cursor = cursor->nextp;
        }
    }

    // success
    return count;
}

// Unloads dictionary from memory, returning true if successful. else false
bool unload(void)
{
    // go through all elements in the array
    for (int n = 0; n < 26; n++)
    {
        // define cursor that points to first node
        node* cursor = nodepa[n];

        // as long as cursor is pointing to a node
        while (cursor != NULL)
        {
            // create temp pointer, to be passed to free function
            node* tempp = cursor;

            // let cursor point to next node so we don't lose its link to the list
            cursor = cursor->nextp;

            // free node that temp is pointing to
            free(tempp);
        }
    }

    // success
    return true;
}

// Hash function: Finds the index in hashtable where a word belongs to
int findind(const char array[LENGTH+1])
{
    // determine hashtable index the word belongs to
    return (tolower(array[0]) % 97);
}