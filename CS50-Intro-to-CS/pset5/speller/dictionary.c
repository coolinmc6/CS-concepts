// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// define struct for value-pointer pair, i.e., a node
// Notice that each word is of length 45 + 1; it doesn't matter that not every word is going to be 45 characters long
// // this code is from the "load" video
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

///////////////////////////////////////////////////////////////////////////////////////////////////
// This is the hashtable that holds everything
// the hashtable is of size 65536 which is 2 ^ 16
node* hashtable[HASHTABLE_SIZE];


///////////////////////////////////////////////////////////////////////////////////////////////////
// Dictionary Size
// this tracks the number of words in the dictionary
unsigned int word_count = 0;

// keeps track of dictionary load / unload status
bool loaded = false;



///////////////////////////////////////////////////////////////////////////////////////////////////
// Hash function
// https://www.reddit.com/r/cs50/comments/2ipg56/pset6_dereferencing_hash_value/
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
// CHECK
// Returns true if word is in dictionary else false
// in speller.c, bool misspelled = !check(word) so if it is NOT false, misspelled is true
// mispelled => word is mispelled => word is NOT in dictionary => the function "check" returns FALSE
// the word you are receiving is the word you want to check, not from your dictionary
bool check(const char *word)
{
    // For every word, I need to convert to lowercase, hash it, see if hash exists, if hash !exist, the
    // word is misspelled


    // create char array to store copy of word
    // word is a const char* and non-read actions cannot be performed on it
    int len = strlen(word); // get length of word
    char word_copy[len + 1]; // need space for null terminator so I need to add 1

    // convert word to lowercase and store it in word_copy
    for (int i = 0; i < len; i++)
    {
       word_copy[i] = tolower(word[i]);
    }

    // add null terminator to end of char array
    word_copy[len] = '\0';

    // get hash value
    int h = hash_it(word_copy);

    // Now that I have the hash, how do I look for it?
    // I can create a variable that equals the entire linked list at hashtable[h]


    // this is my traversal variable. It starts at hashtable[h]
    node* trav = hashtable[h];

    // while trav is NOT NULL, I need to compare the two strings: (trav->word == word_copy)?
    // Remember that my hashtable has null values for all positions in the dictionary to start
    // So if one element was NULL and no word in my dictionary populates that place, then this while loop
    // will never run and the function will return false
    while (trav != NULL)
    {
        // strcmp returns 0 if the strings are equal
        // strcmp returns < 0 IF first string is less than second string
        // strcmp returns > 0 IF first string is greater than second string
        if (strcmp(trav->word, word_copy) == 0)
        {
            // word is in dictionary
            return true;
        }
        else
        {
            // if there is no next node, my trav variable is equal to trav->next
            //
            trav = trav->next;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// LOAD
// Loads dictionary into memory, returning true if successful else false
// in speller.c, bool loaded is a variable that is TRUE if successfully loaded and FALSE if load fails
// Notice that my hash table IS the working dictionary in memory, not the loaded variable
bool load(const char *dictionary)
{

    // makes all hash table elements NULL
    // So now, every element in my hash table is NULL
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // open dictionary; the dictionary is given
    // this is all pretty standard
    // fp = file pointer
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        // malloc a node for each new word
        // This means that I am dynamically allocating space for this variable. Malloc returns a pointer to that
        // block of memory
        // Every time I  malloc something, I have to check that my pointer is not NULL; if it is, I don't have the
        // memory available
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }

        // read a word from the dictionary and store it in new_node->word
        // I set my next property to NULL

        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;

        // so now I have my new node with a word from the file


        // feof is from stdio.h and checks whether it's the end of the file
        // it returns a non-zero value if it is
        // this returns false until we hit the end of the file
        if (feof(fp))
        {
            free(new_node);
            break;
        }

        // I increment my word counter
        word_count++;

        // I create a hash using my hash function from the word I just collected
        int h = hash_it(new_node->word);

        node* temp = hashtable[h];

        // if bucket is empty, insert the first node
        // I am checking to see whether temp exists. If temp exists, or is NOT NULL, then something is already there
        // (a previous node). If it is NULL, I have to create a new node
        if (temp == NULL)
        {
            // hashtable[h] does not exist so set it to the new node
            hashtable[h] = new_node;
        }


        else
        {
            // hashtable[h] DOES exist so I need to add it to the linked list
            // to add it to the front, I just set the previous occupants as my "next" variable for the new_node
            // and then set hashtable[h] to my new_node
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    // close dictionary
    fclose(fp);

    // update my loaded boolean to true
    loaded = true;
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// SIZE
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // if my dictionary is successfully loaded, return the word_count
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// UNLOAD
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // I am going through every single element in my hashtable and free each node
    // So there are two loops: the outer loop which is 0 - 65536 and the inner loop which is the linked list
    // at that position (every single node at that position)
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            // maintain connection to linked list using temp
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}
