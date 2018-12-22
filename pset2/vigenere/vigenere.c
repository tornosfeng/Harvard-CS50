#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k");
        return 1;
    }

    string key = argv[1];
    int len_key = strlen(key);

    for(int i = 0; i < len_key; i++)
    {
        if(isalpha(key[i])== false)
        {
            printf("%c  sage: ./vigenere k!",key[i]);
            return 1;
        }
    }

    string pt,ct;
    pt = get_string("plaintext:");
    ct = pt;

    int j = 0;


    for(int i = 0, n = strlen(pt); i < n; i++)
    {
        int key_num;
        if (islower(key[(j % len_key)]))
        {
            key_num = key[(j % len_key)] - 'a';
        }
        else
        {
            key_num = key[(j % len_key)] - 'A';
        }

        if (islower(pt[i]))
        {

            if (pt[i] + key_num> 'z')
            {
                ct[i] = pt[i] + key_num -26;
            }
            else
            {
                ct[i] = pt[i] + key_num;
            }
            j++;
        }
        else if (isupper(pt[i]))
        {
            if (pt[i] + key_num  > 'Z')
            {
                ct[i] = pt[i] + key_num - 26;
            }
            else
            {
                ct[i] = pt[i] +key_num;
            }
            j++;
        }
        else
        {
            ct[i] = pt[i];
        }


    }

    printf("ciphertext: %s\n", ct);
}