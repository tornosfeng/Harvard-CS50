# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    long long  n;
    int dig = 0; //judge the digital number of n
    do
    {
        n = get_long_long("Number:");
    }
    while (n < 0);

    long long tmp;
    tmp = n;

    while (tmp != 0)
    {
        tmp = tmp / 10;
        dig = dig + 1;
    }
    //printf("digs = %d\n",dig);

    int card_alg = 0;

    for (int i = 1; i <= dig; i++)
    {
        long long digs;
        digs = n / pow(10, i - 1);
        digs = digs % 10;

        if (i % 2 == 0)
        {
            card_alg = card_alg + (digs * 2) / 10 + (digs * 2) % 10;
        }
        else
        {
            card_alg = card_alg + digs;
        }
    }
    //printf("%d\n",card_alg);

    int flag = 0;
    if (card_alg % 10 == 0)
    {
        //printf("n / pow(10 , dig-2) = %d\n",(int)(n / pow(10 , dig-2)));

        if ((dig == 15) & ((int)(n / pow(10, dig - 2)) == 34 || (int)(n / pow(10, dig - 2)) == 37))
        {
            printf("AMEX\n");
            flag = 1;
        }
        else if ((dig == 16) & ((int)(n / pow(10, dig - 2)) == 51 || (int)(n / pow(10, dig - 2)) == 52 || (int)(n / pow(10, dig - 2)) == 53|| (int)(n / pow(10, dig - 2)) == 54 || (int)(n / pow(10, dig - 2)) == 55))
        {
            printf("MASTERCARD\n");
            flag = 2;
        }
        else if ((dig == 16 || dig == 13) & ((int)(n / pow(10, dig - 1)) == 4))
        {
            printf("VISA\n");
            flag = 3;
        }
        else
        {
            printf("INVALID\n");
            flag = 4;
        }

    }
    else
    {
        printf("INVALID\n");
        flag = 5;
    }
    //printf("flag = %d\n",flag);

}