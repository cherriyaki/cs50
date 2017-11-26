#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //user input name, assume containing only alphabets and spaces
    string name = get_string();

    //run through each character in the name. if first character is alphabet, print it. else, print the alphabet after each space.
    for (int n = 0, l = strlen(name); n < l; n++)
    {
        if (n == 0 && name[n] != ' ' && name[n] != '\0')
        {
            printf("%c", toupper(name[n]) );
        }
        else if (name[n] == ' ' && name[n+1] != ' ' && name[n+1] != '\0')
        {
          printf("%c", toupper(name[n+1]) );
        }
    }

    //print new line
    printf("\n");
}