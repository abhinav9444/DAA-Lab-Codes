/*
Ques-2.3: Write a program in C to find GCD of two numbers using recursion. Read all pair of numbers print the result.
Give the contents of the input as  console input
Contents of the output as 
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    while (1)
    {
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)  // To break loop Enter both number as 0
        {
            break;
        }
        printf("The GCD of %d and %d is %d\n", a, b, gcd(a, b));
    }
    return 0;
}

