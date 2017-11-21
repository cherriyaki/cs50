#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long card, foroddsum, wolastdig;
    int odddigsum, evenprodsum, totalsum;

    // get credit card number ;)
    do
    {
        printf("Your credit card number, please: ");
        card = get_long_long();
    }
    while ( card < 0 );

    // add every other digit from last digit together
    for (foroddsum = card, odddigsum = 0; foroddsum > 0; foroddsum /= 100)
    {
        odddigsum += foroddsum % 10;
    }

    // take every other digit from second last multiplied by 2, add the DIGITS together
    for (wolastdig = card / 10, evenprodsum = 0; wolastdig > 0; wolastdig /= 100)
    {
        if ( (wolastdig % 10) * 2 > 9 )
        {
            evenprodsum += ((wolastdig % 10) * 2) / 10;
            evenprodsum += ((wolastdig % 10) * 2) % 10;
        }
        else
        {
            evenprodsum += ((wolastdig % 10) * 2);
        }
    }

    // add both sums together
    totalsum = odddigsum + evenprodsum;

    // check validity of card then check card type
    if ( totalsum % 10 == 0 )
    {
        if ( (card >= 340000000000000 && card < 350000000000000 ) || (card >= 370000000000000
                && card < 380000000000000) )
        {
            printf("AMEX\n");
        }
        else if ( (card >= 5100000000000000) && (card < 5600000000000000) )
        {
            printf("MASTERCARD\n");
        }
        else if ( (card >= 4000000000000 && card < 5000000000000) || (card >= 4000000000000000
                  && card < 5000000000000000))
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}