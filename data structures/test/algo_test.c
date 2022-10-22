#include <stdio.h>

#include "algo.h"

void printArray(int arr[], int size);

int main()
{
    int arr1[] = { 64, 34, 25, 12, 22, 11, 90 };
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {12, 11, 13, 5, 6};
    int data[] = {9, 4, 10, 8, 2, 4};
    int radix[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n5 = sizeof(radix) / sizeof(radix[0]);
    int n1= sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(data) / sizeof(data[0]);
    BubbleSort(arr1, n1);
    printf("Sorted array: \n");
    printArray(arr1, n1);
    
    SelectionSort(arr2, n2);
    printf("Sorted array: \n");
    printArray(arr2, n2);
    
    InsertionSort(arr3, n3);
    printf("Sorted array: \n");
    printArray(arr3, n3);
    
    printf("try\n");
    CountingSort(data, n4);
    printf("Sorted array: \n");
    printArray(data, n4);
    
    CountingSort(radix, n5);
    printf("Sorted array: \n");
    printArray(radix, n5);
    
    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
