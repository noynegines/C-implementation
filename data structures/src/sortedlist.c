/*
Dev - Noy
Reviewer- Idan 
date - 12/09/12
*/

#include <stdlib.h> /*malloc & free*/
#include <assert.h>

#include "dlist.h"
#include "sortedlist.h"

struct sorted_list_struct
{
    dlist_t *dlist;
    compare_t cmp_func;
};

static sorted_list_iter_t FindLargerHandler(sorted_list_iter_t from, sorted_list_iter_t to, sorted_list_iter_t where, compare_t cmp_func);


sorted_list_t *SortedListCreate(compare_t cmp_func)
{
	sorted_list_t *new_list = NULL;
	assert(NULL != cmp_func);
	
	new_list = (sorted_list_t*)malloc(sizeof(sorted_list_t));
	if(NULL == new_list)
	{
		return NULL;
	}
	
	new_list->dlist = DListCreate();
	if(NULL == new_list->dlist)
	{
		free(new_list);
		new_list = NULL;
	}
	new_list->cmp_func = cmp_func;
	
	return new_list;
}


void SortedListDestroy(sorted_list_t *list)
{
	assert(NULL != list);
	
	DListDestroy(list->dlist);
	list->dlist = NULL;
	
	free(list);
	list = NULL;
}





sorted_list_iter_t SortedListInsert(sorted_list_t *list, const void *data)
{
	dlist_iter_t new_iter = {NULL};
	sorted_list_iter_t new_node = {0};
	
	assert(NULL != list);
	
	new_iter = DListBegin(list->dlist);
	
	while(0 == DListIsIterEqual(DListEnd(list->dlist), new_iter))
	{
		if(0 >= list->cmp_func(data, DListGetData(new_iter)))
		{
			break;
		}
		new_iter = DListIterNext(new_iter);
	}
	
	new_iter = DListInsertBefore(list->dlist, new_iter, data);
	new_node.dlist_iter = new_iter;
	
	#ifndef NDEBUG
		new_node.list = list;
	#endif 		
	
	return new_node;
}




sorted_list_iter_t SortedListRemove(sorted_list_iter_t iter)
{
	iter.dlist_iter = DListRemove(iter.dlist_iter);
	
	return iter;
}

sorted_list_iter_t SortedListFind(sorted_list_iter_t from, sorted_list_iter_t to, const void *data, sorted_list_t *list)
{
	sorted_list_iter_t new_iter = {0};
	
	assert(NULL != list);
	
	#ifndef NDEBUG
		assert(from.list == to.list);
	#endif 		
	
	new_iter.dlist_iter = DListFind(from.dlist_iter, to.dlist_iter,(void *)data, *(from.list->cmp_func));
	
	#ifndef NDEBUG
		new_iter.list = from.list;
	#endif  
	
	return new_iter;
}

sorted_list_iter_t SortedListFindCustom(sorted_list_iter_t from, sorted_list_iter_t to, const void *data, sorted_list_match_t *is_match)
{
	sorted_list_iter_t new_iter = {0};
	#ifndef NDEBUG
		assert(from.list == to.list);
	#endif
	
	new_iter.dlist_iter = DListFind(from.dlist_iter, to.dlist_iter, data, *is_match);
	
	#ifndef NDEBUG
		new_iter.list = from.list;
	#endif
	
	return new_iter; 
}

void *SortedListGetData(sorted_list_iter_t iterator)
{
	return DListGetData(iterator.dlist_iter);
}

sorted_list_iter_t SortedListBegin(const sorted_list_t *list)
{
	sorted_list_iter_t new_iter = {0};
	
	assert(NULL != list);
	
	new_iter.dlist_iter = DListBegin(list->dlist);
	
	#ifndef NDEBUG
		new_iter.list = (sorted_list_t *)list;
    #endif
    
    return new_iter;
}

sorted_list_iter_t SortedListEnd(const sorted_list_t *list)
{
	sorted_list_iter_t new_iter = {0};
	
	assert(NULL != list);
	
	new_iter.dlist_iter = DListEnd(list->dlist);
	
	#ifndef NDEBUG
		new_iter.list = (sorted_list_t *)list;
    #endif
    
    return new_iter;
}

sorted_list_iter_t SortedListIterNext(sorted_list_iter_t iterator)
{
	iterator.dlist_iter = DListIterNext(iterator.dlist_iter);
	
	return iterator;
}

sorted_list_iter_t SortedListIterPrev(sorted_list_iter_t iterator)
{
	iterator.dlist_iter = DListIterPrev(iterator.dlist_iter);
	
	return iterator;
}

int SortedListIsEmpty(const sorted_list_t *list)
{
	assert(NULL != list);
	
	return DListIsEmpty(list->dlist);
}

sorted_list_ret_val_t SortedListIsIterEqual(sorted_list_iter_t lhs, sorted_list_iter_t rhs)
{
	return DListIsIterEqual(lhs.dlist_iter, rhs.dlist_iter);
}

sorted_list_ret_val_t SortedListForEach(sorted_list_iter_t from, sorted_list_iter_t to, sorted_list_action_t action_function, void *param)
{
	#ifndef NDEBUG
		assert(from.list == to.list);
	#endif
	
	return DListForEach(from.dlist_iter, to.dlist_iter, action_function, param);
}

void *SortedListPopFront(sorted_list_t *list)
{
	assert(NULL != list);
	
	return DListPopFront(list->dlist);
}

void *SortedListPopBack(sorted_list_t *list)
{
	assert(NULL != list);
	
	return DListPopBack(list->dlist);
}

void SortedListMerge(sorted_list_t *dest, sorted_list_t *src)
{
	sorted_list_iter_t from = {NULL};
	sorted_list_iter_t to = {NULL};
	sorted_list_iter_t where = {NULL};
	
	assert(NULL != dest);
	assert(NULL != src);
	
	from = SortedListBegin(src);
	where = SortedListBegin(dest);
	
	while(!SortedListIsEmpty(src))
	{
		where = FindLargerHandler(where, SortedListEnd(dest), from, dest->cmp_func);
		if(SUCCESS == SortedListIsIterEqual(where, SortedListEnd(dest)))
		{
			DListSplice(where.dlist_iter, from.dlist_iter, SortedListEnd(src).dlist_iter);
			break;
		}
		
		to = FindLargerHandler(from, SortedListEnd(src), from, dest->cmp_func);
		DListSplice(where.dlist_iter, from.dlist_iter, to.dlist_iter);
		from.dlist_iter = to.dlist_iter;
	}
}


static sorted_list_iter_t FindLargerHandler(sorted_list_iter_t from, sorted_list_iter_t to, sorted_list_iter_t where, compare_t cmp_func)
{
	while(FAILURE == SortedListIsIterEqual(from, to))
	{
		if(0 < cmp_func(DListGetData(from.dlist_iter), DListGetData(where.dlist_iter)))
		{
			break; 
		}
		
		from = SortedListIterNext(from);
	}
	
	return from;
}


size_t SortedListSize(const sorted_list_t *list)
{
    assert(NULL != list);
    return DListSize(list->dlist);
}


