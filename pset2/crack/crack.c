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
    char passw[6];
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

        passw[0] = str[a];
        passw[1] = '\0';//字符串是以'\0'作为结束标志
        passw[2] = '\0';//字符串是以'\0'作为结束标志
        passw[3] = '\0';//字符串是以'\0'作为结束标志
        passw[4] = '\0';//字符串是以'\0'作为结束标志
        passw[5] = '\0';//字符串是以'\0'作为结束标志
        printf("processing......\%%l\n", a/(len*1.0));
        if (n == crypt(passw, salt))
        {
            printf("key is %s\n", passw);
            return 0;
        }


        for (b = 0; b < len; b++)
        {
            passw[1] = str[b];
            passw[2] = '\0';//字符串是以'\0'作为结束标志
            //printf("crypt2....%s\n", crypt(passw2, salt));
            if(strcmp(n , crypt(passw, salt)) ==0)
            {
                printf("key is %s\n", passw);
                return 0;
            }

           for (c = 0; c < len; c++)
            {
                passw[2] = str[c];
                passw[3] = '\0';//字符串是以'\0'作为结束标志
                cryptn = crypt(passw, salt);

                if(strcmp(n , crypt(passw, salt)) == 0)
                {
                    printf("key is %s\n", passw);
                    return 0;
                }

                for(d = 0; d < len; d++)
                {

                    passw[3] = str[d];
                    passw[4] = '\0';//字符串是以'\0'作为结束标志

                    cryptn = crypt(passw, salt);
                    //printf("%s...crypt4....%s\n", passw4, cryptn);
                    if(strcmp(n , cryptn) == 0)
                    {
                        printf("key is %s\n", passw);
                        return 0;
                    }

                    for(e = 0; e < len; e++)
                    {

                        passw[4] = str[e];
                        passw[5] = '\0';//字符串是以'\0'作为结束标志

                        cryptn = crypt(passw, salt);
                        //printf("%s...crypt5....%s\n", passw5, cryptn);
                        if(strcmp(n , cryptn) == 0)
                        {
                            printf("key is %s\n", passw);
                            return 0;
                        }
                    }
                }
            }

        }

    }

}