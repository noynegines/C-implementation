#include <stdlib.h> /*malloc & free*/
#include <assert.h> /* assert */

#include "pq.h"

struct pq
{
    sorted_list_t *list;
};

pq_t *PQCreate(pq_priority_t priority_func)
{
	pq_t *queue = NULL;
	
	assert(NULL != priority_func);
	
	queue = (pq_t*)malloc(sizeof(pq_t));
	if(NULL == queue)
	{
		return NULL;
	}
	
	queue->list = SortedListCreate(priority_func);
	if(NULL == queue->list)
	{
		free(queue);
		queue = NULL;
	}
	
	return queue;
}

void PQDestroy(pq_t *queue)
{
	assert(NULL != queue);
	assert(NULL != queue->list);
	
	SortedListDestroy(queue->list);
	queue->list = NULL;
	
	free(queue);
	queue = NULL;
}


void *PQErase(pq_t *queue, pq_is_match_t match_func, const void *param)
{
	sorted_list_iter_t member = {0};
	void* data = NULL;
	
	assert(NULL != queue);
	assert(NULL != queue->list);
	assert(NULL != match_func);
	assert(NULL != param);
	
	member = SortedListFindCustom(SortedListBegin(queue->list), SortedListEnd(queue->list), param, &match_func);
	if(1 == SortedListIsIterEqual(SortedListEnd(queue->list), member))
	{
		return NULL;
	}
	
	data = SortedListGetData(member);
	SortedListRemove(member);
	
	return data;
}

void PQClear(pq_t *queue)
{
	sorted_list_iter_t iter = {0};
	sorted_list_iter_t end = {0};
	
	assert(NULL != queue);
	assert(NULL != queue->list);
	
	iter = SortedListBegin(queue->list);
	end = SortedListEnd(queue->list);
	
	while(0 == SortedListIsIterEqual(iter, end))
	{
		iter = SortedListRemove(iter);
	}
}

pq_ret_val_t PQEnqueue(pq_t *queue, void *data)
{
	sorted_list_iter_t iter = {0};
	assert(NULL != queue);
	assert(NULL != queue->list);
	assert(NULL != data);
	
	iter = SortedListInsert(queue->list, data);
	if(1 == SortedListIsIterEqual(iter, SortedListEnd(queue->list)))
	{
		return FAILURE;
	}
	
	return SUCCESS;
}

void *PQDequeue(pq_t *queue)
{	
	assert(NULL != queue);
	assert(NULL != queue->list);
	
	return SortedListPopFront(queue->list);
}

void *PQPeek(const pq_t *queue)
{
	assert(NULL != queue);
	assert(NULL != queue->list);

	return SortedListGetData(SortedListBegin(queue->list));	
}

int PQIsEmpty(const pq_t *queue)
{
	assert(NULL != queue);
	assert(NULL != queue->list);

	return SortedListIsEmpty(queue->list);
}

size_t PQSize(const pq_t *queue)
{
	assert(NULL != queue);
	assert(NULL != queue->list);
	
	return SortedListSize(queue->list);
}


