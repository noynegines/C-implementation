
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>    /* size_t  */

#define GROWTH_FACTOR (2)



typedef struct dyn_vector dyn_vector_t;

typedef enum vector_ret_value
{
    SUCCESS = 0,
    FAILURE = 1
} vector_ret_value_t;

/*
    Description: Allocates memory for dyn_vector_t and for initial data stored in it
    params:
        vector_capacity - initial number of elements
        element_size - size (bytes) of each element
    return:
        pointer to created instance of dyn_vector_t
        or NULL in case of failure
    complexity:
    time - O(1).
    space - O(1).
*/
dyn_vector_t *VectorCreate(size_t vector_capacity, size_t element_size);

/*
    Description: Frees the memory occupied by referenced vector
    params:
        pointer to instance of dyn_vector_t
    return:
	    
    complexity:
    time - 0(1).
    space - 0(1).
*/
void VectorDestroy(dyn_vector_t *vector);

/*
    Description: Changes the capacity of vector passed by reference. If vector_size before
    change was greater than new vector_capacity, then the array truncates to the
    new_capacity size. 
    params:
        vector - pointer to the instance being changed.
        vector_capacity - capacity to be setted.
    return:
	    SUCCESS/FAILURE in resizing the vector.
    complexity:
    time - O(n).
    space - O(n).
*/
vector_ret_value_t VectorResizeCapacity(dyn_vector_t *vector, size_t vector_capacity);

/*
Description: Function to push a value into the back of the vector.
    
params: 
        vector - pointer to the instance being changed.
        value - the value of element to be pushed.
return:
	
complexity:
    time - best: O(1). worst: O(n). amortized - O(log(n))
    space - O(1). worst O(n). amortized - O(log(n))
*/

vector_ret_value_t VectorPushBack(dyn_vector_t *vector, const void *value);

/*
Description: Function to pop a value from the back of the stack.
    
params:
	vector - pointer to the instance being changed.
return:
	
complexity:
    time - O(1).
    space - O(1).
*/
void VectorPopBack(dyn_vector_t *vector);

/*
Description:
    function to get access to a specific element in the vector
params:
	a pointer to vector_t struct, can't be NULL.
	index.
return:
	pointer to the element in the vector specified by the index.
complexity:
    time - O(1).
    space - O(1).
*/
void *VectorAccessAt(dyn_vector_t *vector, size_t index);

/*
Description: Function that returns the amount of occupied elements in the vector
    
params:
		a pointer to vector_t struct, can't be NULL.
return:
	the function returns size_t size amount of occupied elements in the vector.
complexity:
    time - O(1).
    space - O(1) .
*/
size_t VectorSize(const dyn_vector_t *vector);

/*
Description: Function that returns the cacpacity of the vector. 

params:
	a pointer to vector_t struct, can't be NULL.
return:
	the function returns size_t capacity - amount of elements that the vector can currently occupy.
complexity:
    time - O(1).
    space - O(1).
*/
size_t VectorCapacity(const dyn_vector_t *vector);

/*
Description:
    
params:
	a pointer to vector_t struct, can't be NULL. 
return:
	SUCCESS/FAILURE in shrinking the vector.
complexity:
    time - O(n).
    space - O(n).buffer
*/
vector_ret_value_t VectorShrink(dyn_vector_t *vector);


#endif          /* __VECTOR_H__  */







