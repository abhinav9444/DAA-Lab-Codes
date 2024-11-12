/*
1.3 Write a program to read ‘n’ integers that must contain some duplicate values and store them into an array. 
Perform the following operations on the array.
a)Find out the total number of duplicate elements.
b)Find out the most repeating element in the array.
*/
#include <stdio.h>      
int main()
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
    printf("Total number of duplicate elements: %d\n", count);
    int max_count = 0, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            curr_count++;
        }
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
    printf("Most repeating element(Mode): %d\n", res);
    return 0;
}