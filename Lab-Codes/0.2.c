/*Ques-2 : Take input of 3 numbers and find max among 3 numbers.*/

#include<stdio.h>

int find_max3(int a[])
{
    int max=a[0];
    for(int i=1;i<3;i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}

int main()
{
    printf("Enter 3 Numbers : ");
    int a[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d",a+i);
    }
    printf("MAx of three : %d",find_max3(a));
    return 0;
}