/*
3.1 Aim of the program: Write a menu driven program to sort list of array elements using Merge Sort technique and calculate 
the execution time only to sort the elements.Count the number of comparisons. 
Note# 
● To calculate execution time, assume that single program is under execution in the CPU.                         
● Number of elements in each input file should vary from 300 to 500 entries. 
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., 
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., 
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, 

Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {      // Merge function to merge two sub-arrays
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {       // Merge Sort function
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void generateAscendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void generateDescendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("\n");
}

int main() {
    int n, choice;
    printf("Enter the number of elements (300-500): ");
    scanf("%d", &n);
    if (n < 300 || n > 500) {
        printf("Invalid input. Number of elements should be between 300 and 500.\n");
        return 1;
    }
    int arr[n];
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            generateAscendingArray(arr, n);
            break;
        case 2:
            generateDescendingArray(arr, n);
            break;
        case 3:
            generateRandomArray(arr, n);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid option\n");
            return 1;
    }
    printf("\nBefore Sorting:\n\n");
    printArray(arr, n);
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeSort(arr, 0, n - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    printf("\nAfter Sorting:\n\n");
    printArray(arr, n);
    printf("\nNumber of Comparisons: %d\n", comparisons);
    printf("\nExecution Time: %lld nanoseconds\n", elapsed_ns);
    return 0;
}
