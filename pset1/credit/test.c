# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    long long  n;

   n = 6103211990713;

   long long digs;
   long long tmp = n;
   long long dig = 0;

    while(tmp!= 0)
    {
        tmp = tmp / 10;
        dig = dig + 1;
    }

     for (int i = 1; i <= dig; i++)
    {
        digs = n/pow(10,i-1);
        digs = digs%10;
         printf("%lld\n",digs);
    }


}