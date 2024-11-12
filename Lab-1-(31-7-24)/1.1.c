/* Ques-1.1 :  WAP to find out the second smallest and second largest element stored in an array of n integers. */
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int temp;
    for (int i = 0; i < n; i++) {               //Sorting Array in Ascending order
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Second smallest: %d\n",arr[1]);
    printf("Second largest: %d\n",arr[n - 2]);
    return 0;
}