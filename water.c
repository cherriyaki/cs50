#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes;
    int bottles;
    printf("Minutes: ");
    do
    {
        minutes = get_int();
    } while(minutes < 0);
    bottles = minutes*12;
    printf("Bottles: %d\n", bottles);
}