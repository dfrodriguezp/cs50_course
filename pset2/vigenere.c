#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool isValidKeyword(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return false;
    }
    return true;
}
 

char key(char letter)
{
    if (isupper(letter))
    {
        return (letter - 'A');
    }

    else if (islower(letter))
    {
        return (letter - 'a');
    }
    return 0;
}

int main(int argc, string argv[])
{
    if (argc != 2 || !isValidKeyword(argv[1]))
    {
        printf("Usage ./vigenere keyword\n");
        return 1;
    }

    string keyword = argv[1];
    int key_len = strlen(keyword);
    string input = get_string("plaintext: ");
    string output = input;

    for (int i = 0, j = 0, s = strlen(input); i < s; i++)
    {
        char curr = input[i];
        if (isalpha(curr))
        {
            if (isupper(curr))
            {
                char k = key(keyword[j % key_len]);
                char nxt = (curr + k) % ('Z' + 1);
                j++;
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
                char k = key(keyword[j % key_len]);
                char nxt = (curr + k) % ('z' + 1);
                j++;
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