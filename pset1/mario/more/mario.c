//output a more comfortable pyramid
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 0 || n > 23);

    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j <= n - i)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }

            }

            printf("  ");

            for (int j = 1; j <= n; j++)
            {
                if (j <= i)
                {
                    printf("#");
                }

            }
            printf("\n");
        }
    }
}