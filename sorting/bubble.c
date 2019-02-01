#include <stdio.h>

int main()
{
    const int n = 10;
    int array[n] = {23, 1, 24, 24, 5, 74, 24, 31, 35, 44};
    int counter = 1;

    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int tmp = array[i];
            if (array[i+1] < tmp)
            {
                array[i] = array[i+1];
                array[i+1] = tmp;
                counter++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}