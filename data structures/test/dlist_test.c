/*#include <stdio.h>

#include "dlist.h"

void TestCreateDestroy();
void TestInsert();
int IsMatch(const void *data1, void *data2);
void TestFind();


int main()
{
	TestCreateDestroy();
	TestInsert();
	TestFind();
		
		
	return 0;
}


void TestCreateDestroy()
{
	dlist_t *list = NULL;
	size_t failure = 0;

	printf("*****************************\n");
	printf("testing create destroy functions:\n");
	printf("*****************************\n\n");
	
	list = DListCreate();
	
	if(1 != DListIsEmpty(list))
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	DListDestroy(list);
	
	printf("Test create destroy: %s with %lu failures \n\n", (failure > 0) ? "failed" : "passed", failure);
}

void TestInsert()
{
	dlist_t *list = NULL;
	size_t failure = 0;
	int x = 4;
	char a = 'a';

	printf("*****************************\n");
	printf("testing insert function:\n");
	printf("*****************************\n\n");
	
	list = DListCreate();
	DListInsertBefore(list,DListEnd(list), (int*)&x);
	if(0 != DListIsEmpty(list))
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if((void *)&x != DListGetData(DListBegin(list)))
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	DListInsertBefore(list,DListBegin(list), (char*)&a);
	if((void *)&a != DListGetData(DListBegin(list)))
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	
	DListDestroy(list);
		
	printf("Test Insert: %s with %lu failures \n\n", (failure > 0) ? "failed" : "passed", failure);
}

int IsMatch(const void *data1, void *data2)
{
	return(*(int *)data1 == *(int *)data2);
}

void TestFind()
{
	dlist_t *list = NULL;
	size_t failure = 0;
	int x = 4;
	char a = 'a';
	size_t b = 5;

	printf("*****************************\n");
	printf("testing Find function:\n");
	printf("*****************************\n\n");
	
	list = DListCreate();
	DListInsertBefore(list,DListEnd(list), (int*)&x);
	DListInsertBefore(list,DListEnd(list), (char*)&a);
	DListInsertBefore(list,DListEnd(list), (size_t*)&b);
	if(0 != DListIsEmpty(list))
	{
		printf("Test line %d failed\n", __LINE__);
		++failure;
	}
	if(DListIsIterEqual(DListFind(DListBegin(list), DListEnd(list), &a, IsMatch), DListBegin(list)))
	{
		printf("Test line %d failed\n", __LINE__);
		printf("size: %lu\n", DListSize(list));
		++failure;
	}
	DListRemove(DListBegin(list));
	printf("size: %lu\n", DListSize(list));
	
	
	
	DListDestroy(list);
		
	printf("Test Find: %s with %lu failures \n\n", (failure > 0) ? "failed" : "passed", failure);
}*/

#include <stdio.h>

#include "dlist.h"


void DListCreateDListDestroyTest(void);
void DListInsertBeforeTest(void);
void DListIterPrevNextTest(void);
void DListPopPushFrontBackTest(void);
void DListFindTest(void);
void DListSpliceTest(void);

static int MatchHandler(const void *data_list, void *data_param);

int main()
{
	DListCreateDListDestroyTest();
	DListInsertBeforeTest();
	DListIterPrevNextTest();
	DListPopPushFrontBackTest();
	DListFindTest();
	/*DListSpliceTest();*/
	return 0;
}


void DListCreateDListDestroyTest(void)
{
	int success = 0;
	dlist_t *list = DListCreate();
	1 != DListIsEmpty(list) ? printf("error in DListIsEmpty") : ++success;
	DListDestroy(list);
}

void DListInsertBeforeTest(void)
{
	dlist_t *list = DListCreate();
	dlist_iter_t iter = DListEnd(list);
	dlist_iter_t iter1 = {NULL};
	size_t a = 5;
	size_t b = 8;
	size_t c = 10;
	size_t d = 2;
	void *data =(void *)&a;
	int success = 0;
	
	1 != DListIsEmpty(list) ? printf("error in DListIsEmpty") : ++success;
	0 != DListSize(list) ? printf("error in DListSize") : ++success;
		
	iter1 = DListInsertBefore(list, iter, data);
	1 != DListSize(list) ? printf("error in DListSize") : ++success;
		
	5 != *(int *)DListGetData(iter1) ? printf("error in GetData") : ++success;
	
	0 != DListIsEmpty(list) ? printf("error in DListIsEmpty") : ++success;

	iter1 =DListInsertBefore(list, DListEnd(list), (void *)&b);
	2 != DListSize(list) ? printf("error in DListSize") : ++success;
	
	8 != *(int *)DListGetData(iter1) ? printf("error in GetData") : ++success;

	iter1 =DListInsertBefore(list, DListEnd(list), (void *)&c);
	10 != *(int *)DListGetData(iter1) ? printf("error in GetData") : ++success;
	
	DListSetData(iter1, (void *)&d);
	2 != *(int *)DListGetData(iter1) ? printf("error in SetData") : ++success;
	3 != DListSize(list) ? printf("error in DListSize") : ++success;
	
	iter1 = DListRemove(iter1);
	2 != DListSize(list) ? printf("error in DListSize+DListRemove") : ++success;
	
	iter1 = DListRemove(DListIterPrev(iter1));
	DListRemove(DListIterPrev(iter1));
	
	0 != DListSize(list) ? printf("error in DListSize+DListRemove") : ++success;
	1 != DListIsEmpty(list) ? printf("error in DListIsEmpty") : ++success;
	
	DListDestroy(list);
}

void DListIterPrevNextTest(void)
{
	dlist_t *list = DListCreate();
	dlist_iter_t iter = DListEnd(list);
	dlist_iter_t iter1 = {NULL};
	size_t a = 5;
	size_t b = 8;
	int success = 0;
	iter1 = DListInsertBefore(list, iter, (void *)&a);
	5 != *(int *)DListGetData(iter1) ? printf("error in GetData") : ++success;
	
	/*5 != *(int *)DListGetData(DListIterPrev(iter1)) ? printf("error in DListIterPrev") : ++success;*/

	iter1 = DListInsertBefore(list, iter, (void *)&b);
	5 != *(int *)DListGetData(DListIterPrev(iter1)) ? printf("error in DListIterPrev") : ++success;
	/*8 != *(int *)DListGetData(DListIterNext(iter1)) ? printf("error in DListIterNext") : ++success;*/
	DListDestroy(list);
}

void DListPopPushFrontBackTest(void)
{
	dlist_t *list = DListCreate();
	dlist_iter_t iter = {NULL};
	int success = 0;
	size_t a = 5;
	size_t b = 8;
	size_t c = 10;
	size_t d = 2;
	iter = DListPushFront(list, (void *)&a);
	/*pushfront check*/
	5 != *(int *)DListGetData(iter) ? printf("error in PushFront") : ++success;
	iter = DListPushFront(list, (void *)&b);
	iter = DListPushFront(list, (void *)&c);
	iter = DListPushFront(list, (void *)&d);
	2 != *(int *)DListGetData(iter) ? printf("error in PushFront") : ++success;
	/*popfront check*/
	2 != *(int *)DListPopFront(list) ? printf("error in PopFront") : ++success;
	10 != *(int *)DListPopFront(list) ? printf("error in PopFront") : ++success;
	8 != *(int *)DListPopFront(list) ? printf("error in PopFront") : ++success;
	5 != *(int *)DListPopFront(list) ? printf("error in PopFront") : ++success;
	
	1 != DListIsEmpty(list) ? printf("error in DListIsEmpty") : ++success;
	/*list is empty-> pushback test*/
	
	iter = DListPushBack(list, (void *)&a);
	5 != *(int *)DListGetData(iter) ? printf("error in PushBack") : ++success;
	iter = DListPushBack(list, (void *)&b);
	iter = DListPushBack(list, (void *)&c);
	iter = DListPushBack(list, (void *)&d);
	2 != *(int *)DListGetData(iter) ? printf("error in PushBack") : ++success;
	/*popback check*/
	2 != *(int *)DListPopBack(list) ? printf("error in PopBack") : ++success;
	10 != *(int *)DListPopBack(list) ? printf("error in PopBack") : ++success;
	8 != *(int *)DListPopBack(list) ? printf("error in PopBack") : ++success;
	5 != *(int *)DListPopBack(list) ? printf("error in PopBack") : ++success;
	
	1 != DListIsEmpty(list) ? printf("error in DListIsEmpty") : ++success;
	DListDestroy(list);
}

static int MatchHandler(const void *data_list, void *data_param)
{
	return(*(int *)data_list == *(int *)data_param);
}

void DListFindTest(void)
{
	dlist_t *list = DListCreate();
	dlist_t *dest_list = DListCreate();
	int success = 0;
	size_t a = 1;
	size_t b = 8;
	size_t c = 10;
	size_t d = 2;
	size_t e = 2;
	size_t f = 2;
	size_t g = 2;
	size_t h = 1;
	DListInsertBefore(list, DListEnd(list), (void *)&a);
	DListInsertBefore(list, DListEnd(list), (void *)&b);
	DListInsertBefore(list, DListEnd(list), (void *)&c);
	DListInsertBefore(list, DListEnd(list), (void *)&d);
	DListInsertBefore(list, DListEnd(list), (void *)&e);
	DListInsertBefore(list, DListEnd(list), (void *)&f);
	DListInsertBefore(list, DListEnd(list), (void *)&g);
	DListInsertBefore(list, DListEnd(list), (void *)&h);
	
	
	(SUCCESS != DListIsIterEqual(DListFind(DListBegin(list), DListEnd(list), (void *)&a, MatchHandler),DListBegin(list))) ? printf("error in DListFind1") : ++success;
	
	(SUCCESS != DListIsIterEqual(DListFind(DListBegin(list), DListEnd(list), (void *)&b, MatchHandler),DListIterNext(DListBegin(list)))) ? printf("error in DListFind2") : ++success;
		
	
	4 != DListMultiFind(DListBegin(list), DListEnd(list), (void *)&d, MatchHandler, dest_list) ? printf("error in DListMultiFind1") : ++success;
	
	2 != DListMultiFind(DListBegin(list), DListEnd(list), (void *)&a, MatchHandler, dest_list) ? printf("error in DListMultiFind2") : ++success;
	
	
	DListDestroy(list);
	DListDestroy(dest_list);
}

void DListSpliceTest(void)
{
	dlist_t *list_a = DListCreate();
	dlist_t *list_b = DListCreate();
	int success = 0;
	size_t a = 1;
	size_t b = 8;
	size_t c = 10;
	size_t d = 2;
	size_t e = 9;
	size_t f = 78;
	size_t g = 32;
	size_t h = 5;
	
	DListPushBack(list_a, (void *)&a);
	DListPushBack(list_a, (void *)&b);
	DListPushBack(list_a, (void *)&c);
	DListPushBack(list_a, (void *)&d);
	
	4 != DListSize(list_a) ? printf("error in DListSize") : ++success;
	
	DListPushBack(list_b, (void *)&e);
	DListPushBack(list_b, (void *)&f);
	DListPushBack(list_b, (void *)&g);
	DListPushBack(list_b, (void *)&h);
	
	4 != DListSize(list_b) ? printf("error in DListSize") : ++success;
	
	5 != *(int *)DListGetData(DListSplice(DListIterNext(DListBegin(list_a)), DListBegin(list_b), DListEnd(list_b))) ? printf("error in DListSplice") : ++success;
	
	8 != DListSize(list_a) ? printf("error in DListSplice") : ++success;
	
	DListDestroy(list_a);
	DListDestroy(list_b);
}

