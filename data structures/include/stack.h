#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h> /* size_t */

typedef struct stack_struct stack_t;

typedef enum empty_status
{
    FULL = 0,
    EMPTY = 1
} empty_status_t;   /*ken!!!!! lagaat*/



/*
Description:
Function to push a value into the stack.
params:
	a pointer to stack_t struct, can't be NULL.
	value of the element to be pushed in the stack.
return:
    .
complexity:
    time - O(1).
    space - O(1).
*/
void StackPush(stack_t *stack, void *value);  /*undefined for different element size - user's responsibility*/


/*
Description:
Function to pop a value from the stack.
params:
	a pointer to stack_t struct, can't be NULL.
return:
    .
complexity:
    time - O(1).
    space - O(1).
*/
void StackPop(stack_t *stack);


/*
Description:
    Function to look at the top element from the stack.
params:
	a pointer to stack_t struct, can't be NULL.
return:
	pointer to the top element.
complexity:
    time -  O(1).
    space - 0(1).
*/
void *StackPeek(const stack_t *stack);


/*
Description:
    Function to check if the stack is empty.
params:
	a pointer to stack_t struct, can't be NULL.
return:
	True - 1, False - 0
complexity:
    time - 0(1).
    space - 0(1).
*/
empty_status_t StackIsEmpty(const stack_t *stack);   


/*
Description: Function that returns the amount of ocuupied elements in ths stack. (size <= capacity)

params: 
	a pointer to stack_t struct, can't be NULL.
return:
	the function returns size_t size of ocuppied elements in the stack. 
complexity:
    time - O(1).
    space - O(1).
*/
size_t StackSize(const stack_t *stack);


/*
Description: Finction that returns the cacpacity of the stack. 

params:
	a pointer to stack_t struct, can't be NULL.
return:
	the function returns size_t capacity - amount of elements that the stack can occupy.
complexity:
    time - O(1).
    space - O(1).
*/
size_t StackCapacity(const stack_t *stack);


/*
Description: 
    The function creates a new stack_t struct.
params: 
	the wanted capasity of the new stack.
	the size of the stack elements.
return:
	the function returns a pointer to the stack.
complexity:
    time - 0(1).
    space - 0(1).
*/
stack_t *StackCreate(size_t capacity, size_t element_size);


/*
Description: 
     The function destroys a stack_t struct, meaning free the memory allocation.
params:
	a pointer to stack_t struct, can't be NULL.
return:
	returns SUCCESS/FAIL. 
complexity:
    time - 0(1).
    space - 0(1).
*/
void StackDestroy(stack_t *stack);


#endif /*__STACK_H__*/
