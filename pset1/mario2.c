#include <stdio.h>
#include <cs50.h>

int main()
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 0 || h > 23);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h-(i+1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i+1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
