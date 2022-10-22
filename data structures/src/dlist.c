/*
Dev - Noy
Reviewer- Amit 
date - 12/09/12
*/

#include <stdlib.h> /* malloc & free */
#include <assert.h> /* assert */

#include "dlist.h" /* header file */

#define UNUSED(x) (void)(x)

struct node_struct
{
    void *data;
    dlist_node_t *next;
    dlist_node_t *prev;
};

struct dlist_struct
{
    dlist_node_t head;
    dlist_node_t tail;
};

static int CountHelper(void *data, void *count);

dlist_t *DListCreate(void)
{
	dlist_t *list = NULL;
	
	list = (dlist_t *)malloc(sizeof(dlist_t));
	if(NULL == list)
	{
		return NULL;
	}
	
	list->head.next = &(list->tail);
	list->head.prev = NULL;
	list->head.data = NULL;
	
	list->tail.next = NULL;
	list->tail.prev = &(list->head);
	list->tail.data = NULL;
	
	return list;
}


void DListDestroy(dlist_t *list)
{
    dlist_iter_t iter = DListBegin(list);
    assert(NULL != list);

    while(!DListIsIterEqual(iter, DListEnd(list)))
    {
        iter = DListRemove(iter);
    }

    free(list);
    list = NULL;

}



dlist_iter_t DListIterPrev(dlist_iter_t iterator)
{
	dlist_iter_t new_iter = {NULL};
	
	assert(NULL != iterator.node);
	
	new_iter.node = iterator.node->prev;
	
	return new_iter;
}

dlist_iter_t DListIterNext(dlist_iter_t iterator)
{
	dlist_iter_t new_iter = {NULL};
	
	assert(NULL != iterator.node);
	
	new_iter.node = iterator.node->next;
	
	return new_iter;
}


dlist_iter_t DListBegin(const dlist_t *list)
{
	dlist_iter_t new_iter = {NULL};
	
	assert(NULL != list);
	
	new_iter.node = list->head.next;
	
	return new_iter;
}




dlist_iter_t DListEnd(const dlist_t *list)
{
	dlist_iter_t new_iter = {NULL};
	
	assert(NULL != list);
	
	new_iter.node = &(((dlist_t *)list)->tail);
		
	return new_iter;
}

void *DListGetData(dlist_iter_t iterator)
{
	assert(NULL != iterator.node);
	
	return iterator.node->data;
}

void DListSetData(dlist_iter_t iterator, const void *data)
{
	assert(NULL != iterator.node);
	
	iterator.node->data = (void *)data;
}

int DListIsEmpty(const dlist_t *list)
{
	assert(NULL != list);
	
	return (list->head.next == &(list->tail));
}

dlist_ret_val_t DListIsIterEqual(dlist_iter_t iterator1, dlist_iter_t iterator2)
{
	assert(NULL != iterator1.node);
	assert(NULL != iterator2.node);
	
	return iterator1.node == iterator2.node;
}

dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to, const void *data, is_match_t match_function)
{

	assert(NULL != match_function);
	assert(NULL != data);
	assert(NULL != from.node);
	assert(NULL != to.node);
	
	while(0 == DListIsIterEqual(from, to))
	{
		if(1 == match_function(DListGetData(from), (void*)data))
		{
			return from;
		}
		from = DListIterNext(from);
	}
	return to;
}

dlist_iter_t DListRemove(dlist_iter_t iterator)
{
	dlist_node_t *previous_node = NULL;
	dlist_node_t *next_node = NULL;
	
	assert(NULL != iterator.node);
	
	previous_node = iterator.node->prev;
	next_node = iterator.node->next;
	
	if(NULL == iterator.node->data)
	{
		return iterator;
	}
	
	previous_node->next = next_node;
	next_node->prev = previous_node;
	
	free(iterator.node);
	iterator.node = NULL;
	
	
	return *(dlist_iter_t *)&next_node;
}




dlist_iter_t DListInsertBefore(dlist_t *list, dlist_iter_t where, const void *data)
{
	dlist_node_t *new_node = NULL;
	
	assert(NULL != list);
	assert(NULL != where.node);
	
	new_node = (dlist_node_t *)malloc(sizeof(dlist_node_t));
	if(NULL == new_node)
	{
		where.node = (void *)&(list->tail);
		return 	where;
	}
	
	new_node->data = (void *)data;
	new_node->prev = where.node->prev;
	new_node->next = where.node;

	(where.node->prev)->next = new_node;
	where.node->prev = new_node;
	
	return *(dlist_iter_t *)&(new_node);
	
}

dlist_ret_val_t DListForEach(dlist_iter_t from, dlist_iter_t to, dlist_action_t action_function, void *param)
{
	assert(NULL != from.node);
	assert(NULL != to.node);
	assert(NULL != action_function);	
			
	while(!DListIsIterEqual(from, to))
	{
		if(1 == action_function(DListGetData(from), param))
		{
			return 1;
		}
		from = DListIterNext(from);
	}
	return 0;
}

void *DListPopFront(dlist_t *list)
{
	void *data = NULL;
	
	assert(NULL != list);
	assert(0 == DListIsEmpty(list));
	
	data = DListGetData(DListBegin(list));
	DListRemove(DListBegin(list));
	
	return data;
}

void *DListPopBack(dlist_t *list)
{
	void *data = NULL;
	
	assert(NULL != list);
	assert(0 == DListIsEmpty(list));
	
	data = DListGetData(DListIterPrev(DListEnd(list)));
	DListRemove(DListIterPrev(DListEnd(list)));
	
	return data;
}

dlist_iter_t DListPushBack(dlist_t *list, const void *data)
{
	assert(NULL != list);
	assert(NULL != data);
	
	return DListInsertBefore(list, DListEnd(list) , data);
}

dlist_iter_t DListPushFront(dlist_t *list, const void *data)
{
	assert(NULL != list);
	
	return DListInsertBefore(list, DListBegin(list), data);
}

size_t DListMultiFind(dlist_iter_t from, dlist_iter_t to, void *param, is_match_t match_function, dlist_t *dest_list)
{
	size_t count = 0;
	
	assert(NULL != dest_list);
	assert(NULL != from.node);
	assert(NULL != to.node);
	assert(NULL != match_function);
	
	while(FAILURE == DListIsIterEqual(from, to))
	{
		if(1 == match_function(DListGetData(from), param))
		{
			++count;
			DListPushBack(dest_list, param);
		}
		from = DListIterNext(from);
	}
	
	return count;
}

dlist_iter_t DListSplice(dlist_iter_t where, dlist_iter_t from, dlist_iter_t to)
{
	dlist_iter_t last_node = {NULL};
	
	assert(NULL != from.node);
	assert(NULL != to.node);
	assert(NULL != where.node);
	
	last_node.node = to.node->prev;
	from.node->prev->next = to.node;
	to.node->prev = from.node->prev;
	last_node.node->next = where.node;
	where.node->prev->next = from.node;
	from.node->prev = where.node->prev;
	where.node->prev = last_node.node;
	
	return where;
}

size_t DListSize(const dlist_t *list)
{
	size_t count = 0;
	assert(NULL != list);

	DListForEach(DListBegin(list), DListEnd(list), CountHelper, &count);
	
	return count;
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
