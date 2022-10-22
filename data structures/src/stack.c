#include <assert.h> /* assert */
#include <stdlib.h> /*malloc(), free()*/

#include "stack.h"


struct stack_struct 
{
    size_t capacity;
    size_t element_size;
    size_t stack_size;
    char *base_ptr;     
};


#define S_START (stack->base_ptr)
#define TOP (S_START + (stack->stack_size * stack->element_size))
#define SIZE_LEFT (stack->capacity - (stack->stack_size * stack->element_size))


void StackPush(stack_t *stack, void *value)
{
	char *ptr_val = NULL;
	size_t size = 0;
	char *ptr_top = NULL;
	
	assert(NULL != stack);
	assert(stack->capacity > stack->stack_size);
	
	ptr_val = (char *)&value;
	size = stack->element_size;
	ptr_top = S_START + (stack->stack_size * stack->element_size);
	
	if(0 != SIZE_LEFT)
	{
		while(0 != size) /*O(1)*/
		{
			*ptr_top = *ptr_val;
			++ptr_top;
			++ptr_val;
			--size;
		}
		++(stack -> stack_size);
	}
}

void StackPop(stack_t *stack)  /*O(1)*/
{
	
	assert(NULL != stack);
	assert(0 != stack->stack_size);
	
	--(stack -> stack_size);
}

empty_status_t StackIsEmpty(const stack_t *stack) /*O(1)*/
{
	assert(NULL != stack);
	
	if(0 == stack->stack_size)
	{
		return EMPTY;
	}
	 
	return FULL;
}

size_t StackSize(const stack_t *stack) /*O(1)*/
{
	assert(NULL != stack);
	
	return stack->stack_size;
}

size_t StackCapacity(const stack_t *stack) /*O(1)*/
{
	assert(NULL != stack);
	
	return stack->capacity;
}

void *StackPeek(const stack_t *stack) /*O(1)*/
{
	void *ptr_top = NULL;

	assert(NULL != stack);
	assert(0 != stack->stack_size);
	
	/*if(StackIsEmpty(stack) == EMPTY)
	{
		return NULL;
	}*/
	
	ptr_top = (void*)(S_START + (((stack->stack_size) - 1) * (stack->element_size)));
		
	return ptr_top;
}

void StackDestroy(stack_t *stack) /*O(1)*/
{
	assert(NULL != stack);
	
	free(stack);
	stack = NULL;
}

stack_t *StackCreate(size_t capacity, size_t element_size) /*O(1)*/
{
	stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t) + (capacity * element_size));
	
	if(NULL == new_stack)
	{
		return NULL;
	}
	
	new_stack->capacity = capacity;
	new_stack->element_size = element_size;
	new_stack->stack_size = 0;
	new_stack->base_ptr = (char*)new_stack + sizeof(stack_t);
    
	return new_stack;
}
