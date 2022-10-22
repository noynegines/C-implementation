#ifndef __ALGO_H__
#define __ALGO_H__

#include <stddef.h> /*size_t*/
#include "cstmdef.h"

typedef enum ret_val ret_val_t;

/*
    parameters:
        arr - a valid pointer to array to sort
        arr_size - size of array
    complexity:
        time: best      O(n)
              average   O(n^2)
              worst     O(n^2)
        space O(1)
*/
void BubbleSort(int *arr, size_t arr_size);

/*
    parameters:
        arr - a valid pointer to array to sort
        arr_size - size of array
    complexity:
        time: best      O(n)
              average   O(n^2)
              worst     O(n^2)
        space O(1)
*/
void InsertionSort(int *arr, size_t arr_size);

/*
    parameters:
        arr - a valid pointer to array to sort
        arr_size - size of array
    complexity:
        time: best      O(n^2)
              average   O(n^2)
              worst     O(n^2)
        space O(1)
*/
void SelectionSort(int *arr, size_t arr_size);

/*
    parameters:
        arr - a valid pointer to array to sort
        arr_size - size of array
    complexity:
        k - key's range
        time: best      O(n + k)
              average   O(n + k)
              worst     O(n + k)
        space O(k)
    return:
        SUCCESS
        FAILURE
*/
ret_val_t CountingSort(int *arr, size_t arr_size);

/*
    parameters:
        arr - a valid pointer to array to sort
        arr_size - size of array
        bit_num - number of bits that represent an element in the arr 
    complexity:
        time: best      O(n * k)
              average   O(n * k)
              worst     O(n * k)
        space O(k)
    return:
        SUCCESS
        FAILURE
*/
ret_val_t RadixSort(int *arr, size_t arr_size, size_t bit_num);

#endif /*__ALGO_H__*/

