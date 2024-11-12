/* C Program to create a file containing 300 to 500 random numbers entries using loop*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    file = fopen("random_numbers.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    srand(time(0));
    int n = rand() % 201 + 300;
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d\n", rand());
    }
    fclose(file);
    return 0;
}