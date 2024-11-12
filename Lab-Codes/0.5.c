/*Ques-1 Homework : Write a program to find the sum of the digits repetitively until single digit.*/

#include<stdio.h>

int digit_sum(int n);
int recursive_sum(int n);

int main()
{
    printf("Enter a number: ");
    int n;
    scanf("%d",&n);
    printf("The sum of digits of %d is : %d\n",n,digit_sum(n));
    printf("Recursive Sum of %d is : %d ",n,recursive_sum(n));
}

int digit_sum(int n)
{
    if(n==0)
        return 0;
    else
    {
        return n%10 + digit_sum(n/10);
    }
}

int recursive_sum(int n)
{
    int temp=digit_sum(n);
    if(temp<10)
        return temp;
    else
        return recursive_sum(temp);
}