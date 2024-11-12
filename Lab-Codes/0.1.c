/*Ques-1 : Write a Program to Count no. of digits in a number*/

#include <stdio.h>

int count_no_of_digit(int a);

int main()
{
    printf("Enter the Number : ");
    int a;
    scanf("%d",&a);
    printf("The number of digits in the number is : %d",count_no_of_digit(a));
    return 0;
}

int count_no_of_digit(int a)
{
    int count =0;
    while(a!=0)
    {
        a/=10;
        count++;
    }
    return count;
}