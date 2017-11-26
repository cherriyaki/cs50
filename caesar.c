#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main( int argc, string argv[] )
{
    // make sure command line inputs 2 arguments only
    if ( argc != 2)
    {
       printf( "Usage: ./caesar k\n");
       return 1;
    }

    // convert string in element 2 of argv to int
    int k = atoi(argv[1]);

    // get string from user
    printf("plaintext: ");
    string text = get_string();

    // print ciphertext
    printf("ciphertext: ");

    // iterate over each character in text
    for ( int n = 0, l = strlen(text); n < l; n++ )
    {
        char oldchar = text[n];

        //encipher uppercase characters
        if (isupper(oldchar))
        {
            int oindex = oldchar - 65;
            char nindex = (oindex + k) % 26;
            char newchar = nindex + 65;
            printf("%c", newchar);
        }

        //encipher lowercase characters
        else if (islower(oldchar))
        {
            int oindex = oldchar - 97;
            char nindex = (oindex + k) % 26;
            char newchar = nindex + 97;
            printf("%c", newchar);
        }

        //print non-alphabetical characters as is
        else
        {
            printf("%c", oldchar);
        }
    }

    // final step
    printf("\n");
    return 0;
}