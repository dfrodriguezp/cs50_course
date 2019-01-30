#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);

    string input = get_string("plaintext: ");
    string output = input;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char curr = input[i];
        if (isalpha(curr))
        {
            if (isupper(curr))
            {
                char nxt = (curr + k) % ('Z' + 1);
                if (nxt < 'A')
                {
                    output[i] = nxt + 'A';
                }
                else
                {
                    output[i] = nxt;
                }
            }

            else if (islower(curr))
            {
                char nxt = (curr + k) % ('z' + 1);
                if (nxt < 'a')
                {
                    output[i] = nxt + 'a';
                }
                else
                {
                    output[i] = nxt;
                }
            }
        }

        else
        {
            output[i] = curr;
        }
    }

    printf("ciphertext: %s\n", output);
    return 0;
}