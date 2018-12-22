#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    char str[256];//定义字符串
    char passw1[6],passw2[6],passw3[6],passw4[6],passw5[6];
    int i;
    string n, cryptn;
    char salt[3];

    n = argv[1];

    for (int j = 0; j < 2; j++)
    {
        salt[j] = argv[1][j];
    }
    salt[2] = '\0';



    //printf("%s,  %s", salt, n);

    for (i = 0; i < 52; i++)
    {
        if(i < 26)
        {
           str[i] = 'a' + i;//字符a-z的ASCII是连续的
        }

        else
        {
           str[i] = 'A' + i -26;//字符a-z的ASCII是连续的
        }

    }


    str[i] = '\0';//字符串是以'\0'作为结束标志


    int a, b, c, d, e;
    int len = strlen(str);
    for (a = 0; a < len; a++)
    {
        passw1[0] = str[a];
        passw1[1] = '\0';//字符串是以'\0'作为结束标志
        if (n == crypt(passw1, salt))
        {
            printf("%s\n", passw1);
            return 0;
        }
    }

    for (a = 0; a < len; a++)
    {
        for (b = 0; b < len; b++)
        {
            passw2[0] = str[a];
            passw2[1] = str[b];
            passw2[2] = '\0';//字符串是以'\0'作为结束标志
            //printf("crypt2....%s\n", crypt(passw2, salt));
            if(strcmp(n , crypt(passw2, salt)) ==0)
            {
                printf("%s\n", passw2);
                return 0;
            }
        }
    }
    for (a = 0; a < len; a++)
    {
        for (b = 0; b < len; b++)
        {
            for (c = 0; c < len; c++)
            {
                passw3[0] = str[a];
                passw3[1] = str[b];
                passw3[2] = str[c];
                passw3[3] = '\0';//字符串是以'\0'作为结束标志
                cryptn = crypt(passw3, salt);

                //printf("%s...crypt3....%s\n", passw3, cryptn);
                if(strcmp(n , crypt(passw3, salt)) == 0)
                {
                    printf("%s\n", passw3);
                    return 0;
                }
            }
        }
    }

    for (a = 0; a < len; a++)
    {
        for(b = 0; b < len; b++)
        {
            for(c = 0; c < len; c++)
            {
                for(d = 0; d < len; d++)
                {
                    passw4[0] = str[a];
                    passw4[1] = str[b];
                    passw4[2] = str[c];
                    passw4[3] = str[d];
                    passw4[4] = '\0';//字符串是以'\0'作为结束标志

                    cryptn = crypt(passw4, salt);
                    printf("%s...crypt4....%s\n", passw4, cryptn);
                    if(strcmp(n , cryptn) == 0)
                    {
                        printf("%s\n", passw4);
                        return 0;
                    }
                }
            }
        }
    }

    for (a = 0; a < len; a++)
    {
        for(b = 0; b < len; b++)
        {
            for(c = 0; c < len; c++)
            {
                for(d = 0; d < len; d++)
                {
                    for(e = 0; e < len; e++)
                    {
                        passw5[0] = str[a];
                        passw5[1] = str[b];
                        passw5[2] = str[c];
                        passw5[3] = str[d];
                        passw5[4] = str[e];
                        passw5[5] = '\0';//字符串是以'\0'作为结束标志

                        cryptn = crypt(passw5, salt);
                        printf("%s...crypt5....%s\n", passw5, cryptn);
                        if(strcmp(n , cryptn) == 0)
                        {
                            printf("%s\n", passw5);
                            return 0;
                        }
                    }
                }
            }
        }
    }




}