/*Ques-4 : Take 1 integer as input, count the frequency of each digit in the number*/

#include<stdio.h>

int count_frequency(int a);

int main()
{
    printf("Enter a Number : ");
    int a;
    scanf("%d",&a);
    printf("The frequency of each digit in the number is : \n");
    count_frequency(a);
}

int count_frequency(int a)
{
    int ref[10]={0},temp;
    while(a!=0)
    {
        temp=a%10;
        ref[temp]++;
        a/=10;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d : %d\n",i,ref[i]);
    }
}