/*
2.1 Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers to binary numbers using recursion. 
Note# Read the value of ‘n’
Display the decimal numbers and their equivalent binary numbers. 
Output: Content of the first ‘n’ decimal and their equivalent binary numbers
*/

#include <stdio.h>

void decToBinary(int n);

int main()
{
    int n;
    printf("Enter the number of decimal numbers : ");
    scanf("%d", &n);
    printf("Enter the decimal numbers : \n");
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        printf("Decimal : %d\tBinary : ", num);
        decToBinary(num);
        printf("\n");
    }
    return 0;
}

void decToBinary(int n)
{
    if (n == 0)
    {
        return;
    }
    decToBinary(n / 2);
    printf("%d", n % 2);
}