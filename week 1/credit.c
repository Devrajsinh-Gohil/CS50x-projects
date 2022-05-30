#include <cs50.h>
#include <math.h>
#include <stdio.h>

int find_len(long num);
int first_2_digits(long cnum, int cardl);
int valid_card(long cnum);

int main(void)
{
    long cnum = 0;
    // prompting user for credit card number
    do
    {
        cnum = get_long("Number: ");
    }
    while (cnum < 1);

    // getting the length of credit card number.
    int cardl = find_len(cnum);
    // validating the length of card
    if (cardl == 13 || cardl == 15 || cardl == 16)
    {
        if (valid_card(cnum))
        {
            int first_digits = first_2_digits(cnum, cardl);
            // checkng if card is if is VISA card
            if (first_digits / 10 == 4)
            {
                printf("VISA\n");
            }
            // checkng if card is MASTERCARD card
            else if (first_digits == 51 || first_digits == 52 || first_digits == 53 || first_digits == 54 || first_digits == 55)
            {
                printf("MASTERCARD\n");
            }
            // else is American Express card
            else if (first_digits == 34 || first_digits == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// function to find lenght of the card number.
int find_len(long cnum)
{
    int l;
    for (l = 0 ; cnum > 0 ; l++)
    {
        cnum /= 10;
    }
    return l;
}

// function to find first 2 digits of card number.
int first_2_digits(long cnum, int cardl)
{
    int digit = cnum / pow(10, (cardl - 2));
    return digit;
}

// validating checksum
int valid_card(long cnum)
{
    int counter = 1;
    int sum1 = 0, sum2 = 0;
    while (cnum > 0)
    {
        if (counter % 2 == 0)
        {
            int num = 2 * (cnum % 10);
            // for seprating all the digits individually
            while (num > 0)
            {
                sum1 += num % 10;
                num /= 10;
            }
        }
        else
        {
            sum2 += cnum % 10;
        }
        cnum /= 10;
        counter++;
    }
    int sum = sum1 + sum2;
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}