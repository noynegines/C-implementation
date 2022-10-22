#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stddef.h>    /* size_t  */

typedef struct queue queue_t;


/*
    Description: function that creates a new Queue.
    params: void
        none.
    return:
        pointer to the new Queue struct.
        On error returns NULL.
    complexity:
    time - O(1).
    space - O(1).
*/
queue_t *QCreate(void);


/*
    Description: function that deletes a given Queue.
    params:
        queue - pointer to Queue.
    return: void
       
    complexity:
    time - O(n).
    space - O(1).
*/
void QDestroy(queue_t *queue);

/*
    Description: function that inserts data to the end of the queue.
    params:
        queue - a pointer to the queue. cant be NULL
        data - the data to be inserted into the queue.
    return:
    returns 0 if succeed
    returns 1 if faild
       
    complexity:
    time - O(1).
    space - O(1).
*/
int Enqueue(queue_t *queue, void *data);

/*
    the queue must not be empty
    Description: function that removes an element from the head of the queue.
    params:
        queue - a pointer to the queue. cant be NULL or enmpty
    return:
       void
    complexity:
    time - O(1).
    space - O(1).
*/
void Dequeue(queue_t *queue);

/*  
    Description: function checks if the queue is empty.
    params:
        queue - a pointer to the queue. cant be NULL
    return:
       1 if true.
       0 if false.
    complexity:
    time - O(1).
    space - O(1).
*/
int QIsEmpty(const queue_t *queue);

/*
    Description: function that return the next element to be dequeued.
    params:
        queue - a pointer to the queue. cant be NULL
    return:
        result - the next element to be dequeued
    complexity:
    time - O(1).
    space - O(1).
*/
void *QPeek(const queue_t *queue);

/*
    Description: function that returns the number of elements in the queue.
    params:
        queue - a pointer to the queue. cant be NULL or empty
    return:
        result - the size of the queue.
    complexity:
    time - O(n).
    space - O(1).
*/
size_t QSize(const queue_t *queue);

/*
    Description: function that appends src queue to dest.
    params:
        dest - a pointer to queue. cant be NULL
        src - a pointer to queue that will be append to dest. after append src will stay valid. cant be NULL
    return:
        result - a pointer to the dest.
    complexity:
    time - O(1).
    space - O(1).
*/

queue_t *QAppend(queue_t *dest, queue_t *src);


#endif /* __QUEUE_H__  */
