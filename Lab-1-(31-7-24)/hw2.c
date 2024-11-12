/*
1. Take a string as input and count frequency of each alphabet.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int freq[26] = {0};
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            freq[tolower(str[i]) - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            printf("Frequency of %c: %d\n", i + 'a', freq[i]);
        }
    }
    return 0;
}
