#include <stdlib.h> /* malloc & free */
#include <assert.h> /* assert*/
#include <string.h> /* memcpy*/

#include "vector.h"

#define GROWTH_FACTOR (2)
#define PADDING 1

struct dyn_vector
{
	size_t vector_size;
	size_t vector_capacity;
	size_t element_size;
	void *base_ptr;
};

static int IsFull(const dyn_vector_t *vector);


dyn_vector_t *VectorCreate(size_t vector_capacity, size_t element_size)
{
	dyn_vector_t *vector = (dyn_vector_t *)malloc(sizeof(dyn_vector_t));
	
	if(NULL == vector)
	{
		return NULL;
	}
	
	vector->vector_size = 0;
	vector->vector_capacity = vector_capacity + PADDING;
	vector->element_size = element_size;
	vector->base_ptr = malloc(element_size * vector_capacity);
	if(NULL == vector->base_ptr)
	{
		free(vector);
		vector = NULL;
	}
	
	return vector;
}


void VectorDestroy(dyn_vector_t *vector)
{
	assert(NULL != vector);
	
	free(vector->base_ptr);
	vector->base_ptr = NULL;
	free(vector);
	vector = NULL;
}


vector_ret_value_t VectorResizeCapacity(dyn_vector_t *vector, size_t vector_capacity)
{
	void *new_vector_size = NULL;
	
	assert(NULL != vector);
	
	new_vector_size = realloc(vector->base_ptr, (vector->element_size) * vector_capacity);
	
    if (NULL == new_vector_size)
    {
		return FAILURE;
    }
    
    if(vector_capacity < vector->vector_size)
    {
    	vector->vector_size = vector_capacity;
    }
    
	vector->base_ptr = new_vector_size;
	vector->vector_capacity = vector_capacity;
	
	return SUCCESS;
}

vector_ret_value_t VectorPushBack(dyn_vector_t *vector, const void *value)
{
	int res = SUCCESS;
	assert(NULL != vector);

	if(IsFull(vector))
	{
		res = VectorResizeCapacity(vector, (vector->vector_capacity) * GROWTH_FACTOR);
	}
	
	if(FAILURE != res)
	{
		memcpy(VectorAccessAt(vector, vector->vector_size), value, vector->element_size);
		++(vector->vector_size);
	}
	
	return res;
	
}


void VectorPopBack(dyn_vector_t *vector)
{
	assert(NULL != vector);
	
	--(vector->vector_size);
	VectorShrink(vector);		
}




void *VectorAccessAt(dyn_vector_t *vector, size_t index)
{
	assert(NULL != vector);
	
	return (void *)((size_t)(vector->base_ptr) + (vector->element_size * index));
}


size_t VectorSize(const dyn_vector_t *vector)
{
	assert(NULL != vector);
	
	return vector->vector_size - 1;
}


size_t VectorCapacity(const dyn_vector_t *vector)
{
	assert(NULL != vector);
	
	return vector->vector_capacity - 1;
}


vector_ret_value_t VectorShrink(dyn_vector_t *vector)
{
	assert(NULL != vector);
	
	return VectorResizeCapacity(vector, vector->vector_size);
}

static int IsFull(const dyn_vector_t *vector)
{
	return vector->vector_capacity == vector->vector_size;
}


