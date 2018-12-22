#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    string pt, ct;
    pt = get_string("plaintext:");
    ct = pt;
    int k = atoi(argv[1]) % 26;

    for(int i = 0, n = strlen(pt); i < n; i++)
    {
        if (pt[i] >= 'a' && pt[i] <= 'z')
        {
            if (pt[i] + k > 'z')
                {
                    ct[i] = pt[i] + k -26;
                }
            else
                {
                    ct[i] = pt[i] + k;
                }
        }

        else if (pt[i] >= 'A' && pt[i] <= 'Z')
        {
            if (pt[i] + k > 'Z')
                {
                    ct[i] = pt[i] + k -26;
                }
            else
                {
                    ct[i] = pt[i] + k;
                }
        }
        else
        {
            ct[i] = pt[i];
        }
    }

    printf("ciphertext: %s\n", ct);
}
