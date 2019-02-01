#include <stdio.h>

int main(void)
{
    const int size = 5;
    int array[size] = {34, 2, 9, 90, 3};

    for (int i = 1; i < size; i++)
    {
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}