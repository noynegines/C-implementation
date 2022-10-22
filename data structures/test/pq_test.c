
#include <stdio.h> 	

#include "pq.h"
#include "tests.h"

void CreateDestroyPeekTest(void);
void PQEnqueueDequeueTest(void);
void PQEraseClearTest(void);
static int PriorityHandler(const void *data_left, const void *data_right);
static int MatchHandler(const void *data_right, const void *param);


int main()
{
	CreateDestroyPeekTest();
	PQEnqueueDequeueTest();
	PQEraseClearTest();
	return 0;
}

static int PriorityHandler(const void *data_left, const void *data_right)
{
	return *(int *)data_left - *(int *)data_right;
}


void CreateDestroyPeekTest(void)
{
	size_t a = 8;
	size_t b = 5;
	size_t c = 12;
	size_t d = 2;
	pq_t *pq = PQCreate(PriorityHandler);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 1);
	TEST("PQSize test", PQSize(pq), 0);
	
	PQEnqueue(pq, (void *)&a);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 0);
	TEST("PQSize test", PQSize(pq), 1);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 8);
	
	PQEnqueue(pq, (void *)&b);
	TEST("PQSize test", PQSize(pq), 2);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 5);
	
	PQEnqueue(pq, (void *)&c);
	TEST("PQSize test", PQSize(pq), 3);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 5);
	
	PQEnqueue(pq, (void *)&d);
	TEST("PQSize test", PQSize(pq), 4);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 2);
	
	PQDestroy(pq);
	PASS;
}

void PQEnqueueDequeueTest(void)
{
	size_t a = 8;
	size_t b = 5;
	size_t c = 12;
	size_t d = 2;
	pq_t *pq = PQCreate(PriorityHandler);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 1);
	TEST("PQSize test", PQSize(pq), 0);
	
	PQEnqueue(pq, (void *)&a);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 0);
	TEST("PQSize test", PQSize(pq), 1);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 8);
	
	PQEnqueue(pq, (void *)&b);
	TEST("PQSize test", PQSize(pq), 2);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 5);
	
	PQEnqueue(pq, (void *)&c);
	TEST("PQSize test", PQSize(pq), 3);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 5);
	
	PQEnqueue(pq, (void *)&d);
	TEST("PQSize test", PQSize(pq), 4);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 2);
	
	TEST("PQDequeue test", *(int *)PQDequeue(pq), 2);
	TEST("PQSize test", PQSize(pq), 3);
	
	TEST("PQDequeue test", *(int *)PQDequeue(pq), 5);
	TEST("PQSize test", PQSize(pq), 2);
		
	TEST("PQDequeue test", *(int *)PQDequeue(pq), 8);
	TEST("PQSize test", PQSize(pq), 1);
	
	TEST("PQDequeue test", *(int *)PQDequeue(pq), 12);
	TEST("PQSize test", PQSize(pq), 0);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 1);	
	
	PQDestroy(pq);
	PASS;
}

static int MatchHandler(const void *data_right, const void *param)
{
	return (0 == *(int *)data_right % *(int *)param);
}


void PQEraseClearTest(void)
{
	size_t a = 8;
	size_t b = 5;
	size_t c = 12;
	size_t d = 2;
	pq_t *pq = PQCreate(PriorityHandler);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 1);
	TEST("PQSize test", PQSize(pq), 0);
	
	PQEnqueue(pq, (void *)&a);
	TEST("PQIsEmpty test", PQIsEmpty(pq), 0);
	TEST("PQSize test", PQSize(pq), 1);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 8);
	
	PQEnqueue(pq, (void *)&b);
	TEST("PQSize test", PQSize(pq), 2);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 5);
	
	PQEnqueue(pq, (void *)&c);
	TEST("PQSize test", PQSize(pq), 3);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 5);
	
	PQEnqueue(pq, (void *)&d);
	TEST("PQSize test", PQSize(pq), 4);
	TEST("PQPeek test" ,*(int *)PQPeek(pq), 2);
	
	TEST("PQErase", *(int *)PQErase(pq, MatchHandler, (void *)&d), 2);
	TEST("PQSize test", PQSize(pq), 3);
	
	PQClear(pq);
	TEST("PQSize test", PQSize(pq), 0);
	
	
	PQDestroy(pq);
	PASS;
}

