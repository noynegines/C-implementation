/******************************************************************************
* Programmer: Noy
* Project: queue
* Reviewd By: Idan
* File: queue
* Date: 05/09/22
*/

#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free*/

#include "slist.h" /*header of slist*/
#include "queue.h"


struct queue
{
    slist_t *list;
};

queue_t *QCreate(void)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	if(NULL != queue)
	{
		queue->list = SListCreate();
		if(NULL != queue->list)
		{
			return queue;
		}
		free(queue->list);
	}
	return NULL;
}

void QDestroy(queue_t *queue)
{
	assert (NULL != queue);
	
	SListDestroy(queue->list);
	free(queue);
	queue = NULL;
}

int Enqueue(queue_t *queue, void *data)
{
	assert(NULL != queue);
	assert(NULL != data);
	
	if(NULL == SListInsertBefore(SListEnd(queue->list), data))
	{
		return FAILURE;
	}
	
	return SUCCESS;
}

void Dequeue(queue_t *queue)
{
	assert(NULL != queue);
	
	SListRemove(SListBegin(queue->list));

}

int QIsEmpty(const queue_t *queue)
{
	assert(NULL != queue);
	
	return SListIsEmpty(queue->list);
}

void *QPeek(const queue_t *queue)
{
	assert(NULL != queue);
	
	return SListGetData(SListBegin(queue->list));
}

size_t QSize(const queue_t *queue)
{
	assert(NULL != queue);
	
	return SListCount(queue->list);
}

queue_t *QAppend(queue_t *dest, queue_t *src)
{
	assert(NULL != dest);
	assert(NULL != src);
	
	return (queue_t *)SListAppend(dest->list, src->list);
}
