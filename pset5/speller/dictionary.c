// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

node *hashtable[HashTable];  //it will keep in the memory untile unload()

int hashfunction(char word[LENGTH + 1]) //give the hash number of any word
{
    int hash = 0;
    for(int i = 0, j = strlen(word); i < j; i++)
    {
        //printf("%d\n",(int)(word[i]));
        hash += (int)(word[i]);
    }

    return hash % HashTable;
}
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    if(strlen(word)>LENGTH)
    {
        return false;
    }


    int hash = 0;
    char tmp_word[LENGTH + 1];

    for(int i = 0, j = strlen(word); i < j; i++)
    {
        //printf("%d\n",(int)(word[i]));
        tmp_word[i] = tolower(word[i]);
        //printf("------%c\n",tmp_word[i]);
        hash += (int)(tmp_word[i]);
    }

    hash =  hash % HashTable;
    //printf("hash number is %d\n", hash);
    node *ptr = hashtable[hash];
    while(ptr)
    {
        if(strcasecmp(word,ptr->word) == 0)
        {
            return true;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    while(fscanf(file, "%s", word)!= EOF)
    {
        node *new_node = malloc(sizeof(node));


        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            //printf("%s\n", word);
            //printf("%lu\n", strlen(word));
            strcpy(new_node->word, word);
            new_node->next = NULL; //end of my linked list to NULL!!!
            int  bucket = hashfunction(new_node->word);
            if(hashtable[bucket])
            {
                 new_node->next = hashtable[bucket]->next;
                 hashtable[bucket]->next = new_node;
            }
            else
            {
                hashtable[bucket] = new_node;
            }

        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int table_size = 0;
    for (int i = 1; i < HashTable; i++)
    {
        node *ptr = hashtable[i];
        while(ptr)
        {
            table_size += 1;
            ptr = ptr->next;
        }
    }
    return table_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i = 0; i < HashTable; i++)
    {
        node *ptr = hashtable[i];
        while(ptr!=NULL)
        {
            node *tmp = ptr->next;
            free(ptr);
            ptr = tmp;
        }
    }
    return true;
}
