#include "vector.h"

#include <stdio.h>

void TestVectorCreateDestroy();
void TestVectorCreate();
void TestVectorSizeAndCapacity(dyn_vector_t *vector);
void TestVectorResizeCapacity(dyn_vector_t *vector);
void TestPushBack(dyn_vector_t *vector);

int main()
{
	TestVectorCreateDestroy();
	TestVectorCreate();
	
	return 0;
}

void TestVectorCreateDestroy()
{
	dyn_vector_t *vector = VectorCreate(20, 4);
	VectorDestroy(vector);
}

void TestVectorCreate()
{
	dyn_vector_t *vector = VectorCreate(20, 4);
	TestVectorSizeAndCapacity(vector);
	TestVectorResizeCapacity(vector);
	TestPushBack(vector);
}

void TestVectorSizeAndCapacity(dyn_vector_t *vector)
{
	printf("size: %lu\n", VectorSize(vector));
	printf("capacity: %lu\n", VectorCapacity(vector));
}

void TestVectorResizeCapacity(dyn_vector_t *vector)
{	
	printf("new capacity success 0 else 1: %d\n", VectorResizeCapacity(vector, 40));
	TestVectorSizeAndCapacity(vector);
}

void TestPushBack(dyn_vector_t *vector)
{
	int x = 5, y = 10, i = 0;
	
	for(i = 0; i < 5; ++i)
	{
		printf("push success 0 else 1: %d\n", VectorPushBack(vector, &x));
	}
	printf("push success 0 else 1: %d\n", VectorPushBack(vector, &y));
	printf("The value in the 0 index is %d\n", *(int *)VectorAccessAt(vector, 0));
	printf("The value in the 4 index is %d\n", *(int *)VectorAccessAt(vector, 4));
	printf("The value in the 5 index is %d\n", *(int *)VectorAccessAt(vector, 5));
	TestVectorSizeAndCapacity(vector);
	VectorShrink(vector);
	printf("after shrink function\n");
	TestVectorSizeAndCapacity(vector);
	VectorPopBack(vector);
	printf("after pop function\n");
	TestVectorSizeAndCapacity(vector);
	VectorDestroy(vector);
}
