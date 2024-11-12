/*Ques-4 : Take 1 integer as input, count the frequency of each digit in the number*/

#include<stdio.h>

int count_frequency(long int a);

int main()
{
    printf("Enter a Number : ");
    long int a;
    scanf("%ld",&a);
    printf("The frequency of each digit in the number is : \n");
    count_frequency(a);
}

int count_frequency(long int a)
{
    int ref[10]={0};
    int temp;
    while(a!=0)
    {
        temp=a%10;
        ref[temp]++;
        a/=10;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d : %ld\n",i,ref[i]);
    }
}