#include <stdio.h>
#include "slist.h"

void PrintList(slist_t *list);

int main()
{
	slist_t *list = NULL;	
	slist_iter_t iterator = NULL;
	slist_t *list2 = NULL;
	
	printf("creating the list:\n\n");
    list = SListCreate();
    iterator = SListBegin(list);
    printf("head address: %p\n", (void *)iterator);
    iterator = SListEnd(list);
    printf("tail address: %p\n", (void *)iterator);
    printf("is the list empty? -  should be 1 for dummy %d\n", SListIsEmpty(list));

    printf("\n***********inserting elements test*********\n\n");

    iterator = SListInsertBefore(iterator, (void *)8);
    printf("inserting number 8:\n");
    printf("iterator value - should be equal to 8: %p\n", (void *)(SListGetData(iterator)));
    printf("head address: %p\n", (void *)SListBegin(list));
    printf("dummy address:%p\n", (void *)SListEnd(list));
    printf("is the list empty? %d\n", SListIsEmpty(list));
    printf("number of elements in the list %ld\n", SListCount(list));
    printf("\n***********printint the list*********\n\n");
    PrintList(list);


    iterator = SListInsertBefore(iterator, (void *)5);
    printf("inserting 5 to the list\n");
    printf("iterator value - should be equal to 5: %p\n", (void *)(SListGetData(iterator)));
    printf("head address: %p\n", (void *)SListBegin(list));
    printf("dummy addres: %p\n", (void *)SListEnd(list));
    printf("is the list empty? %d\n", SListIsEmpty(list));
    printf("number of elements in the list %ld\n", SListCount(list));
    printf("head value - should be equal to 5: %p\n", (void *)(SListGetData(SListBegin(list))));
    printf("\n***********printint the list*********\n\n");
    PrintList(list);

    iterator = SListIterNext(SListBegin(list));
    iterator = SListInsertBefore(iterator, (void *)3);
    printf("inserting 3 to the middle of the list\n");
    printf("iterator address %p\n", (void *)iterator);
    printf("list address %p\n", (void *)list);
    printf("number of elements in the list %ld\n", SListCount(list));
    printf("\n***********printint the list*********\n\n");
    PrintList(list);

    printf("********Deleting first element*********\n");
    SListRemove(SListBegin(list));
    PrintList(list);
    
    
    printf("********creating list2*********\n");
    list2 = SListCreate();
    iterator = SListEnd(list2);
    iterator = SListInsertBefore(iterator, (void *)8);
    iterator = SListInsertBefore(iterator, (void *)7);
    iterator = SListInsertBefore(iterator, (void *)6);
    printf("number of elements in list2: %ld\n", SListCount(list2));
    
    list = SListAppend(list, list2);
    iterator = SListBegin(list);
    printf("number of elements in list after append list2: %ld\n", SListCount(list));
    printf("number of elements in list2 after the append: %ld\n", SListCount(list2));

    SListDestroy(list);
    SListDestroy(list2);

    return 0;
}

void PrintList(slist_t *list)
{
    slist_iter_t iterator = SListBegin(list);
    size_t count = 1;
    while(NULL != SListIterNext(iterator))
    {
        printf("The #%ld element is: %p\n", count, (void *)SListGetData(iterator));
        iterator = SListIterNext(iterator);
        ++count;
    }
    printf("\ndone\n\n\n");
}
