/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL) return NULL ;
    q->head = NULL;
    q->tail = NULL ; 
    q->size = 0 ; 

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* if the queue is null, do nothing. */
    if (q == NULL) return  ; 

    /* How about freeing the list elements and the strings? */
    list_ele_t * cur = q->head ;    
    while (cur != NULL) {
        list_ele_t * next = cur->next ; 
        free(cur->value) ; 
        free(cur) ; 
        cur = next ; 
    }

    /* Free queue structure */
    free(q);
}


/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if (q == NULL) return false ; 
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if (newh == NULL) return false ; 
    int slen = strlen(s) ; 
    newh->value = malloc(sizeof(char)*(slen+1)) ; 
    if (newh->value == NULL) 
    {
        free(newh) ; 
        return false ; 
    }
    strncpy(newh->value, s, slen*sizeof(char)) ;  
    newh->value[slen] = '\0' ; 
    
    newh->next = q->head;
    q->head = newh;
    if (q->size == 0) {
        q->tail = q->head ; 
    }
    q->size += 1 ; 
    return true;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (q == NULL) return false ;
    if (q->size == 0) return q_insert_head(q, s) ; 
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *elem = malloc(sizeof(list_ele_t)) ; 
    if (elem == NULL) return false ;

    int slen = strlen(s) ; 
    char * value = malloc(sizeof(char)*(slen+1)) ;
    if (value == NULL) {
        free(elem) ; 
        return false ; 
    }
    strncpy(value, s, slen) ;
    value[slen] = '\0' ;
    elem->value = value ;   
    elem->next = NULL ; 

    // update the tail of the queue.
    // q->tail must not be NULL because the q is not NULL and size > 0.
    q->tail->next = elem ;
    q->tail = elem ; 
    q->size += 1 ; 

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    // return false if queue is NULL or empty
    if (q == NULL || q->size == 0) return false ; 

    // try to copy the string to sp 
    if (sp != NULL && bufsize > 0) {
        int slen = strlen(q->head->value) ; 
        int cpylen = slen>(bufsize-1)? (bufsize-1) : slen ; 
        strncpy(sp, q->head->value, cpylen*sizeof(char)) ; 
        sp[cpylen] = '\0' ;
    }

    // try to free the list element
    free(q->head->value) ; 
    list_ele_t * next = q->head->next ; 
    free(q->head) ; 

    // update the head
    q->head = next;

    // update the tail if this is the last element in queue.
    if (q->size == 0) {
        q->tail = NULL ; 
    } 

    // update the queue size;
    q->size -= 1 ; 
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q != NULL) {
        return q->size ; 
    }
    return 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL || q->size == 0 || q->size == 1) return ; 
    list_ele_t * cur = q->head ;
    list_ele_t * cur_next ; 
    cur_next = cur->next ; 
    cur->next = NULL ; 
    q->tail = cur ; // update the qtail.
    while (cur_next != NULL) {
        list_ele_t * nnext = cur_next -> next ; 
        cur_next->next = cur ; 
        cur = cur_next ; 
        cur_next = nnext ; 
    }
    q->head = cur ; 
}

