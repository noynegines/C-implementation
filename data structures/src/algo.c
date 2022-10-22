/*
* Programmer: Noy Azut
* Project: algo
* Status: 
* Reviewed By: Eden
*/

#include <assert.h> /* assert */
#include <limits.h> /* INT MAX */
#include <stdlib.h> /*malloc & calloc*/

#include "algo.h"

#define ALL_SET (~0)

static void Swap(int *num1, int *num2);
static void FindMinMax(int *arr, size_t arr_size, int *min, int *max, unsigned int mask);
static void InitCountArr(int *arr, int *count_arr, size_t count_arr_size, int min, unsigned int mask);
static void SetCountArr(int *count_arr, size_t count_arr_size);
static void InitSortedArray(int *sorted_array, size_t arr_size, int *arr, int *count_arr, int min, unsigned int mask);
static void CopyArr(int *arr, int *sorted_array, size_t arr_size);
static ret_val_t SortCurrentArr(int *arr, size_t arr_size, unsigned int mask);
static unsigned int CreateMask(size_t bit_num);


void BubbleSort(int *arr, size_t arr_size)
{
	size_t i = 0;
	size_t j = 0;
	size_t is_sorted = 0;
	
	assert(NULL != arr);
	
	for(i = 0; i < arr_size - 1; ++i)
	{
		for(j = 0; j < arr_size - i - 1; ++j)
		{
			if(arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j+1]);
				is_sorted = 1;
			}
		}
		
		if(0 == is_sorted)
		{
			break;
		}
	}
}

static void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void SelectionSort(int *arr, size_t arr_size)
{
	size_t min = 0;
	size_t i = 0, j = 0;
	
	assert(NULL != arr);

	
	for(i = 0; i < arr_size; ++i)
	{
		min = i;
		for(j = i; j < arr_size; ++j)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		Swap(&arr[min], &arr[i]);
	}	
}

void InsertionSort(int *arr, size_t arr_size)
{
	size_t i = 0;
	int j = 0;
	int key = 0;
	
	assert(NULL != arr);
	
	for(i = 1; i < arr_size; ++i)
	{
		key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key)
		{
			Swap(&arr[j + 1], &arr[j]);
			--j;
		}
	}
}

ret_val_t CountingSort(int *arr, size_t arr_size)
{
	assert(NULL != arr);
	
	return SortCurrentArr(arr, arr_size, ALL_SET);
	
}

ret_val_t RadixSort(int *arr, size_t arr_size, size_t bit_num)
{
	unsigned int mask = 0;
	ret_val_t status = SUCCESS;
	
	assert(NULL != arr);
	
	mask = CreateMask(bit_num);
	
	while(0 != mask)
	{
		status = SortCurrentArr(arr, arr_size, mask);
		if(FAILURE == status)
		{
			break;
		} 
		mask <<= bit_num;
	}
	
	return status;

}

static ret_val_t SortCurrentArr(int *arr, size_t arr_size, unsigned int mask)
{
	int max = 0;
	int min = INT_MAX;
	int *count_arr = NULL;
	size_t count_arr_size = 0;
	int *sorted_array = NULL;
	
	assert(NULL != arr);
	
	FindMinMax(arr, arr_size, &min, &max, mask);
	
	count_arr_size = max - min + 1;
	count_arr = (int *)calloc(count_arr_size, sizeof(int));
	if(NULL == count_arr)
	{
		return FAILURE;
	}
	
	InitCountArr(arr, count_arr, arr_size, min, mask);
	SetCountArr(count_arr, count_arr_size);
	
	sorted_array = (int *)malloc(sizeof(int) * arr_size);
	if(NULL == sorted_array)
	{
		free(count_arr);
		count_arr = NULL;
		
		return FAILURE;
	}
	
	InitSortedArray(sorted_array, arr_size, arr, count_arr, min, mask);
	CopyArr(arr, sorted_array, arr_size);
	
	
	free(sorted_array);
	sorted_array = NULL;
	
	free(count_arr);
	count_arr = NULL;
	
	return SUCCESS;	
}
static void FindMinMax(int *arr, size_t arr_size, int *min, int *max, unsigned int mask)
{
	size_t i = 0;
	
	assert(NULL != arr);
	assert(NULL != min);
	assert(NULL != max);
	
	for(i = 0; i < arr_size; ++i)
	{
		if(*min > (arr[i] & mask))
		{
			*min = (arr[i] & mask);
		}
		if(*max < (arr[i] & mask))
		{
			*max = (arr[i] & mask);
		}
	}
}

static void InitCountArr(int *arr, int *count_arr, size_t arr_size, int min, unsigned int mask)
{
	size_t i = 0;
	
	assert(NULL != arr);
	assert(NULL != count_arr);
	
	for(i = 0; i < arr_size; ++i)
	{
		++count_arr[(arr[i] - min) & mask];
	}
}

static void SetCountArr(int *count_arr, size_t count_arr_size)
{
	size_t i =0;
	
	assert(NULL != count_arr);
	 	
	for(i = 1; i < count_arr_size; ++i)
	{
		count_arr[i] += count_arr[i - 1]; 
	}
}

static void InitSortedArray(int *sorted_array, size_t arr_size, int *arr, int *count_arr, int min, unsigned int mask)
{
	size_t i = 0;
	
	assert(NULL != sorted_array);
	assert(NULL != arr);
	
	for(i = 0; i < arr_size; ++i)
	{
		sorted_array[count_arr[(arr[i] & mask) - min] - 1] = arr[i];
		--count_arr[arr[i] - min];  
	}
}

static void CopyArr(int *arr, int *sorted_array, size_t arr_size)
{
	size_t i = 0;
	
	assert(NULL != arr);
	assert(NULL != sorted_array);
	
	for(i = 0; i < arr_size; ++i)
	{
		*arr = *sorted_array;
		++arr;
		++sorted_array;
	}
}

static unsigned int CreateMask(size_t bit_num)
{
	size_t i = 1;
	unsigned int mask = 1;
	unsigned int ret_val = 1;
	
	for(i = 1; i < bit_num; ++i)
	{
		ret_val <<= 1;
		ret_val = ret_val | mask;
	}
	return ret_val;
	
}


