// Cash
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // get user input => how much change is owed
    float change;
    do
    {
        change = get_float("How much change is owed?\n");
    }
    while(change < 0);

    // return how much change is required
    float coins = round(change*100);
    // while(coins > 100)
    // {
    //     coins = coins - 100;
    // }

    // printf("%f", coins);
    // printf("\n");

    int count = 0;
    while(coins >= 25)
    {
        coins = coins - 25;
        count++;
        // printf("QUARTER\n");
        // printf("Coins: %f, Count: %d\n", coins, count);
    }

    while(coins >= 10)
    {
        coins = coins - 10;
        count++;
        // printf("DIME\n");
        // printf("Coins: %f, Count: %d\n", coins, count);
    }
    // printf("Right before nickel");
    while(coins >= 5)
    {
        coins = coins - 5;
        count++;
        // printf("NICKEL\n");
        // printf("Coins: %f, Count: %d\n", coins, count);
    }

    while(coins >= 1)
    {
        coins = coins - 1;
        count++;
        // printf("PENNY\n");
        // printf("Coins: %f, Count: %d\n", coins, count);
    }
    printf("%d\n", count);
}