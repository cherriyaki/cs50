#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int i;
    int n;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    for (i = 0; i < height; i++ )
    {
        int space = height - i - 1;
        int hash = i + 1;
        for (n = 0; n < space; n++ )
        {
            printf(" ");
        }
        for (n = 0; n < hash; n++ )
        {
            printf("#");
        }
        for (n = 0; n < 2; n++ )
        {
            printf(" ");
        }
        for (n = 0; n < hash; n++ )
        {
            printf("#");
        }
        printf("\n");
    }
}