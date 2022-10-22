#include <stdio.h>

#include "queue.h"

void TestEnqueue();
void TestAppend();

int main()
{
	TestEnqueue();
	TestAppend();
	
	return 0;
}

void TestEnqueue()
{
	queue_t *queue = NULL;
	queue = QCreate();
	printf("is empty? %d\n", QIsEmpty(queue));
	printf("adding 4:%s\n" , 0 == Enqueue(queue, (void *)4)? "test passed" : "failed");
	printf("adding 3:%s\n" , 0 == Enqueue(queue, (void *)3)? "test passed" : "failed");
	printf("peek data - should be 4,: %s\n", QPeek(queue) == (void *)4? "test passed" : "failed");
	printf("adding 2:%s\n" , 0 == Enqueue(queue, (void *)2)? "test passed" : "failed");
	printf("adding 1:%s\n" , 0 == Enqueue(queue, (void *)1)? "test passed" : "failed");
	printf("size of queue - should be 4: %lu \n", QSize(queue));
	printf("deleting 2 elements:\n");
	Dequeue(queue);
	Dequeue(queue);
	printf("size of queue - should be 2: %lu \n", QSize(queue));
	printf("is empty? %d\n", QIsEmpty(queue));
	printf("peek data - should be 2: %s\n", QPeek(queue) == (void *)2? "test passed" : "failed");
	
	QDestroy(queue);
}

void TestAppend()
{
	queue_t *queue = NULL;
	queue_t *queue2 = NULL;
	queue = QCreate();
	queue2 = QCreate();
	
	Enqueue(queue, (void *)4);
	Enqueue(queue, (void *)4);
	Enqueue(queue, (void *)4);
	
	Enqueue(queue2, (void *)4);
	Enqueue(queue2, (void *)4);
	Enqueue(queue2, (void *)4);
	
	printf("size of queue before append - should be 3: %lu \n", QSize(queue));
	printf("size of queue2 before append - should be 3: %lu \n", QSize(queue2));
	
	QAppend(queue, queue2);
	printf("size of queue after append - should be 6: %lu \n", QSize(queue));
	printf("size of queue2 after append - should be 0: %lu \n", QSize(queue2));
	
	QDestroy(queue);
	QDestroy(queue2);
}

