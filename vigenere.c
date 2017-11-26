#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// take in command line arguments
int main(int argc, string argv[])
{
    // make sure there are 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //create array to store indices of keyword alphabets
    int k[strlen(argv[1])];

    // make sure every character in keyword is alphabetical
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        else
        {
            if (isupper(argv[1][i]))
            {
                k[i] = argv[1][i] - 'A';
            }
            else if (islower(argv[1][i]))
            {
                k[i] = argv[1][i] - 'a';
            }
        }
    }

    // prompt user for plaintext
    printf("plaintext: ");
    string p = get_string();

    // print ciphertext
    printf("ciphertext: ");

    // iterate through each character in plaintext
    for (int j = 0, l = strlen(p), m = 0; j < l; j++)
    {
        if (isalpha(p[j]))
        {
            int n = m % strlen(argv[1]);

            if (isupper(p[j]))
                {
                    int oindex = p[j] - 'A';
                    int nindex = (oindex + k[n]) % 26;
                    char c = nindex + 'A';
                    printf("%c", c);
                }

            else if (islower(p[j]))
                {
                    int oindex = p[j] - 'a';
                    int nindex = (oindex + k[n]) % 26;
                    char c = nindex + 'a';
                    printf("%c", c);
                }

            m++;
        }

        else
        printf("%c", p[j]);
    }

    //last step
    printf("\n");
    return 0;
}