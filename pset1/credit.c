#include <stdio.h>
#include <cs50.h>
#include <string.h>

int digitsSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}


void card(long number)
{
    char str[16];
    sprintf(str, "%ld", number);
    int sum = 0;
    int other_sum = 0;
    int s = 0;
    while (number > 0)
    {
        if (s % 2 == 0)
        {
            sum += (number % 10);
        }
        else
        {
            other_sum += digitsSum((number % 10) * 2);
        }
        s++;
        number /= 10;
    }

    int total_sum = sum + other_sum;

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (str[0] == '4')
        {
            printf("VISA\n");

        }
        else if (str[0] == '5' && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5'))
        {
            printf("MASTERCARD\n");

        }
        else if (str[0] == '3' && (str[1] == '4' || str[1] == '7'))
        {
            printf("AMEX\n");

        }
    }
}

bool hasInvalidDigit(long number)
{
    char str[16];
    sprintf(str, "%ld", number);
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (str[i] < 48 || str[i] > 57)
            return true;
    }
    return false;
}


int main()
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (hasInvalidDigit(number));

    card(number);
    return 0;
}

