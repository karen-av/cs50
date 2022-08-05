/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

typedef struct node
{
    char s[2];
    bool is_word;
    struct node * next[27];
} node; node *head;


// maximum length for a word / максимальная длинна слова
// например (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

bool search(node *h, char *s);
int createTrie (node *h);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H
