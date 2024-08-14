/*3. take one sentence as input and store each word in array and display the 4th element (word)*/

#include<stdio.h>
#include<string.h>

int main()
{
    printf("Enter a sentence : ");
    char sentence[100];
    fgets(sentence, sizeof(sentence), stdin);

    char words[20][20];
    int wordCount = 0;

    char* token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    if (wordCount >= 4) {
        printf("4th word: %s\n", words[3]);
    } else {
        printf("Not enough words in the sentence.\n");
    }

    return 0;
}