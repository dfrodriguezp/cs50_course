#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[8] = {56, 21, 21, 54, 3, 8, 21, 32};
    int index;

    for (int j = 0; j < 8; j++)
    {
        int min = array[j];
        for (int i = j; i < 8; i++)
        {
            if (array[i] <= min)
            {
                min = array[i];
                index = i;
            }
        }
        array[index] = array[j];
        array[j] = min;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}