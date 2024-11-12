/*
1. Take a string as input and count how many alphabets, digits , other characters are present in that string.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int alphabets = 0, digits = 0, others = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            alphabets++;
        }
        else if (isdigit(str[i]))
        {
            digits++;
        }
        else
        {
            others++;
        }
    }
    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Others: %d\n", others);
    return 0;
}

