/*
Owner: Noy
Reviewer: Michael       
Date: 
Subject: Singly linked list
*/


#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

#include "slist.h" /* header file */

#define UNUSED(x) (void)(x)

struct node_struct
{
    void *data;
    slist_node_t *next;
};


struct slist_struct
{
    slist_node_t *head;
    slist_node_t *tail;
};

static int CountHelper(void *data, void *count);

slist_t *SListCreate(void)
{
	slist_t *list = NULL;
	slist_node_t *dummy = NULL;
	
	list = (slist_t *)malloc(sizeof(slist_t));
	if(NULL == list)
	{
		return NULL;
	}
	
	dummy = (slist_node_t *)malloc(sizeof(slist_node_t));
	if(NULL == dummy)
	{
		free(list);
		list = NULL;
		return NULL;
	}
	
	dummy->data = (void *)list;
	dummy->next = NULL;
	list->head = dummy;
	list->tail = dummy;
	
	return list;
}

void SListDestroy(slist_t *list)
{
	slist_node_t *temp = NULL;
	
	assert(NULL != list);
	
	while(NULL != list->head)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
		temp = NULL;
	}
	
	free(list);
	list = NULL;
}


slist_iter_t SListInsertBefore(slist_iter_t where, const void *data)
{
	slist_node_t *new_node = NULL;
	
	assert(NULL != where);
	assert(NULL != data);
	
	new_node = (slist_node_t *)malloc(sizeof(slist_node_t));
	if(NULL == new_node)
	{
		return NULL;
	}
	
	
	new_node->data = where->data;
	new_node->next = where->next;
	where->data = (void*)data;
	where->next = new_node;
	
	if(NULL == new_node->next)
	{
		((slist_t *)(new_node -> data))->tail = new_node;	
	}

	return where;
	
}


slist_iter_t SListRemove(slist_iter_t iterator)
{
	slist_node_t *next_node = NULL;
	slist_t *list = NULL;
	
	assert(NULL != iterator);
	
	next_node = iterator->next;
	
	if(NULL == next_node)
	{
		return iterator;
	}
	
	iterator->data = next_node->data;
	iterator->next = next_node->next;
	free(next_node);

	
	list = (slist_t *)iterator->data;
	
	if(NULL == iterator->next)
	{
		list->tail = iterator;
	}
	
	return iterator;
}


slist_iter_t SListFind(slist_iter_t from, slist_iter_t to, const void *data, match_function_t match_function)
{
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != data);
	assert(NULL != match_function);
	
	while(from != to)
	{
		if(match_function(from->data, (void*)data))
		{
			return from;
		}
		from = from->next;
	}
	return to;
	
}


void *SListGetData(slist_iter_t iterator)
{
	assert(NULL != iterator);
	
	return iterator->data;
}

void SListSetData(slist_iter_t iterator, const void *data)
{
	assert(NULL != iterator);
	
	iterator->data = (void *)data;
}


slist_iter_t SListBegin(const slist_t *list)
{
	assert(NULL != list);
	
	return list->head;
}

slist_iter_t SListEnd(const slist_t *list)
{
	assert(NULL != list);
	return list->tail;
}


size_t SListCount(const slist_t *list)
{
	size_t count = 0;
	
	assert(NULL != list);
	
	if(SListIsEmpty(list))
	{
		return 0;
	}

	SListForEach(list->head, list->tail, CountHelper, &count);
	/*while(NULL != SListIterNext(next_node))
	{
		++count;
		next_node = SListIterNext(next_node);
	}*/
	
	return count;
}

slist_ret_val_t SListIsIterEqual(slist_iter_t iterator1, slist_iter_t iterator2)
{
	assert(NULL != iterator1);
	assert(NULL != iterator2);
	
	if(iterator1 == iterator2)
	{
		return SUCCESS;
	}
	
	return FAILURE;
}


slist_iter_t SListIterNext(slist_iter_t iterator)
{
	assert(NULL != iterator);
	return iterator->next;
}


slist_ret_val_t SListForEach(slist_iter_t from, slist_iter_t to, operation_function_t operation_function, void *param)
{
	assert(NULL != from);
	assert(NULL != to);
	assert(NULL != param);
	assert(NULL != operation_function);
	
	while(from != to)
	{
		if(FAILURE == operation_function(from->data, param))
		{
			return FAILURE;
		}
		from = from->next;
	}
	return SUCCESS;
}

int SListIsEmpty(const slist_t *list)
{
	assert(NULL != list);
	
	return list->head->next == NULL; 
}

slist_t *SListAppend(slist_t *dest, slist_t *src)
{
	assert(NULL != dest);
	assert(NULL != src);

	
	dest->tail->data = src->head->data;
	dest->tail->next = src->head->next;
	src->head->next = NULL;
	dest->tail = src->tail;
    src->tail = src->head;
    
	return dest;
	
}
 
/******************************************************************
*************************Utility Function**************************/   

static int CountHelper(void *data, void *count)
{
    assert(NULL != data);
    assert(NULL != count);
    
    UNUSED(data);
    ++*(size_t *)count;
    
    return 0;
}



