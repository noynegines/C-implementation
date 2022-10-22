#ifndef __PQ_H__
#define __PQ_H__

#include "cstmdef.h"
#include "sortedlist.h"

/* typedef sortedl_compare_t pq_compare_t; */
typedef struct pq pq_t;
typedef enum ret_val pq_ret_val_t;


/*******************/

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  *pq_match_t
 *  Description:  Function pointer intended for boolean match functions.
 *      Returns:  1 on match, 0 on non-match
 * =====================================================================================
 */
typedef int (*pq_is_match_t)(const void *data_right, const void *param);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  *pq_compare
 *  Description:  Function pointer intended for member priority comparison.
 *      Returns:  An integer less than, equal to, or greater than zero if data_left is
 *                found, respectively, to be of lower, equal, or higher priority than
 *                data_right.
 * =====================================================================================
 */
typedef int (*pq_priority_t)(const void *data_left, const void *data_right);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQCreate
 *  Description:  Creates a new PQ list.
 *   Parameters:  priority_func - valid pointer to priority comparison function.
 *      Returns:  Pointer to the newly created PQ on success. NULL on failure.
 *   Complexity:  Time - O(1)  Space - O(1)
 * =====================================================================================
 */
pq_t *PQCreate(pq_priority_t priority_func);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQDestroy
 *  Description:  Destroys target PQ list. 
 *   Parameters:  queue - valid pointer to target PQ.
 *      Returns:  void
 *   Complexity:  Time - O(n)  Space - O(1)
 * =====================================================================================
 */
void PQDestroy(pq_t *queue);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQErase
 *  Description:  Removes a member of target PQ, found by given match function and 
 *                parameter. 
 *   Parameters:  queue - valid pointer to target PQ.
 *                match_func - pointer to boolean match function
 *                param - pointer to parameter to pass to the match function
 *      Returns:  Pointer to the data removed from the PQ on success, NULL if not found.
 *   Complexity:  Time - O(n)  Space - O(1)
 * =====================================================================================
 */
void *PQErase(pq_t *queue, pq_is_match_t match_func, const void *param);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQClear
 *  Description:  Empties target PQ.
 *   Parameters:  queue - valid pointer to target PQ
 *      Returns:  void
 *   Complexity:  Time - O(n)  Space - O(1)
 * =====================================================================================
 */
void PQClear(pq_t *queue);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQEnqueue
 *  Description:  Inserts new data as a member in the target PQ in its appropriate
 *                position according to the queue priority. 
 *   Parameters:  queue - valid pointer to target PQ.
 *                data - pointer to source data.
 *      Returns:  0/Success on succesful insertion, 1/Failure on failure to insert
 *   Complexity:  Time - O(n)  Space - O(1)
 * =====================================================================================
 */
pq_ret_val_t PQEnqueue(pq_t *queue, void *data);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQDequeue
 *  Description:  Removes the priority member from target PQ. Undefined for empty PQ.
 *   Parameters:  queue - valid pointer to target PQ
 *      Returns:  Pointer to dequeued data.
 *   Complexity:  Time - O(1)  Space - O(1)
 * =====================================================================================
 */
void *PQDequeue(pq_t *queue);


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  PQPeek
 *  Description:  Return the data contained in the priorty member of the target PQ.
 *                Undefined for empty PQ.
 *   Parameters:  queue - valid pointer to target PQ
 *      Returns:  Pointer to the data in the priority member.
 *   Complexity:  Time - O(1)  Space - O(1)
 * =====================================================================================
 */
void *PQPeek(const pq_t *queue);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQIsEmpty
 *  Description:  Checks whether target PQ is empty. 
 *   Parameters:  queue - valid pointer to target PQ
 *      Returns:  1 if empty, 0 if not empty.
 *   Complexity:  Time - O(1)  Space - O(1)
 * =====================================================================================
 */
int PQIsEmpty(const pq_t *queue);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PQSize
 *  Description:  Counts the valid members in target PQ. 
 *   Parameters:  queue - valid pointer to target PQ
 *      Returns:  Amount of valid members in the target PQ.
 *   Complexity:  Time - O(n)  Space - O(1)
 * =====================================================================================
 */
size_t PQSize(const pq_t *queue);


#endif /* __PQ_H__ */

