#include <stdio.h>
#include <cs50.h>


int coinsNumber(float change)
{
    float new_change = change * 100;
    float coins[4] = {25, 10, 5, 1};
    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        while (new_change >= coins[i])
        {
            total++;
            new_change -= coins[i];
        }
    }

    return total;
}


int main()
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    printf("%i\n", coinsNumber(change));
    return 0;
}