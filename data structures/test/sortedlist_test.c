/******************************************************************************
* Programmer: Yasmin Adar
* Project: sortedlist
* File: sortedlist testing
* Date: 08-09-2022 10:05:19
******************************************************************************/

/*****************************************************************************/
/********************************** HEADERS **********************************/
#include <stdio.h> 		    /* printf  size_t                           */
#include <string.h>         /* string function and mem function         */

#include "sortedlist.h"
#include "tests.h"  /* Used for unit testing utilities and macros */

/*   INER FUNCTIONS DECLARATIONS  */

static int CompareHelper(const void *lhs, const void *rhs);
void TestCreateDestroy(void);
void TestInsert(void);
void TestMerge1(void);
void TestMerge2(void);

/*   MAIN FUNCTION   */

int main(void)
{
    size_t errors = 0;
    TestCreateDestroy();
    TestInsert();
    TestMerge1();
    TestMerge2();

    printf("*********\nSummary of all tests - %ld Errors\n", errors);
    return 0;
}

/*   INER FUNCTIONS IMPLEMENTATION    */

static int CompareHelper(const void *lhs, const void *rhs)
{
    return *(int *)lhs - *(int *)rhs;
}

void TestCreateDestroy(void)
{
    sorted_list_t *list= SortedListCreate(CompareHelper);
    int x = 4;
    
    printf("\n\nStarting TestCreateDestroy:\n**********\n");
    TEST("is empty test", SortedListIsEmpty(list), 1);

    SortedListInsert(list, (void *)&x);
  
    TEST("is empty test", SortedListIsEmpty(list), 0);

    PASS;

    SortedListDestroy(list);
}

void TestInsert(void)
{

    sorted_list_t *list= SortedListCreate(CompareHelper);
    int x = 4;
    int y = 2;
    int z = 8;
    int w = 7;
    int f = 0;

    printf("\n\nStarting TestInsert:\n**********\n");
    
    SortedListInsert(list, (void *)&x);
    SortedListInsert(list, (void *)&y);
    SortedListInsert(list, (void *)&z);
    SortedListInsert(list, (void *)&w);
    SortedListInsert(list, (void *)&f);

    TEST("Pop Front", *(int *)SortedListPopFront(list), 0);
    TEST("Pop Front", *(int *)SortedListPopFront(list), 2);
    TEST("Pop Front", *(int *)SortedListPopFront(list), 4);
    TEST("Pop Front", *(int *)SortedListPopFront(list), 7);
    TEST("Pop Front", *(int *)SortedListPopFront(list), 8);

    PASS;
    
    SortedListDestroy(list);
}

void TestMerge1(void)
{
    size_t index = 0;
    int i = 0;

    sorted_list_t *list1= SortedListCreate(CompareHelper);
    sorted_list_t *list2= SortedListCreate(CompareHelper);
    int arr1[] = {3,1,2,9,7,10};
    int arr2[] = {4,6,12,11,5,8,13};


    printf("\n\nStarting TestMerge1:\n**********\n");


    for(index = 0; index < 6; ++index)
    {
        SortedListInsert(list1, (void *)&arr1[index]);
    }

    for(index = 0; index < 7; ++index)
    {
        SortedListInsert(list2, (void *)&arr2[index]);
    }

    SortedListMerge(list1, list2);

    TEST("Merge test", SortedListSize(list1), 13);
    TEST("Merge test", SortedListIsEmpty(list1), 0);
    
    TEST("Merge test", SortedListSize(list2), 0);
    TEST("Merge test", SortedListIsEmpty(list2), 1);
    


	for(i = 1; i < 14; ++i)
	{
		TEST("Merge test", *(int *)SortedListPopFront(list1), i);
	}

    PASS;

    SortedListDestroy(list1);
    SortedListDestroy(list2);
}

void TestMerge2(void)
{
    size_t index = 0;
    int i = 0;

    sorted_list_t *list1= SortedListCreate(CompareHelper);
    sorted_list_t *list2= SortedListCreate(CompareHelper);
    int arr1[] = {3, 2, 6};
    int arr2[] = {4, 1, 5};


    printf("\n\nStarting TestMerge2:\n**********\n");


    for(index = 0; index < 3; ++index)
    {
        SortedListInsert(list1, (void *)&arr1[index]);
    }

    for(index = 0; index < 3; ++index)
    {
        SortedListInsert(list2, (void *)&arr2[index]);
    }

    SortedListMerge(list1, list2);

    TEST("Merge test", SortedListSize(list1), 6);
    TEST("Merge test", SortedListIsEmpty(list1), 0);
    
    TEST("Merge test", SortedListSize(list2), 0);
    TEST("Merge test", SortedListIsEmpty(list2), 1);
    


	for(i = 1; i < 7; ++i)
	{
		TEST("Merge test", *(int *)SortedListPopFront(list1), i);
	}

    PASS;

    SortedListDestroy(list1);
    SortedListDestroy(list2);
}




