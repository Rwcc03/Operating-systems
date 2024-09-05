#include <stdio.h>
#include "queue.h"
/* This method is used to initialize a variable to be tail pointer to a 
process queue. Return a pointer to the tail of an empty process queue; 
i.e. NULL. */
struct queueNode * makeEmptyQueue()
{
    return NULL;
}

/* Return TRUE if the queue whose tail is pointed to by q is empty.
Return FALSE otherwise. */
int emptyQ(struct queueNode *q)
{
    return (q == NULL);
}

/* Insert the queueNode pointed to by p into the queue whose 
tail-pointer is pointed to by q. */
void insertQ(struct queueNode **q, struct queueNode *p)
{
    if (emptyQ(*q))
    {
        /* make p the one and only node in this queue */
        p->next = p;
        *q = p;
        //when queue is empty, just set *q to the new node and circle back
    }
    else
    {
        /*
            insert p at the tail, and it becomes the new tail
            This is a circular queue, so the tail must point to head, i.e.
            (*q)->next must always be the front of the queue 
        */
        p->next = (*q)->next;
        (*q)->next = p;
        *q = p;
        //sets the p struct's next to the current head, then the tail to p
    }
}

/* Remove the first (i.e. head) element from the queue whose 
tail-pointer is pointed to by q. Return NULL if the queue is empty; 
otherwise return the pointer to the removed queueNode. Update the 
queue’s tail pointer if necessary. (Note: since *q is a pointer to the tail,
(*q)->next is the head, if it exists)*/
struct queueNode *removeQ(struct queueNode **q)
{
    if (emptyQ(*q))
    {
        return NULL;
    }
    else
    {
        /* disconnect the head node from the queue, update the tail,
        return the head */
        struct queueNode *tempHead = (*q)->next;
        //temporary head pointer
        if (tempHead == *q){
            *q= NULL;
        }
        else{
        //Disconnects the head and replaces it with head->next
        (*q)->next = tempHead->next;
        }
        return tempHead;
        //returns past head
    }
}

/* Return a pointer to the first queueNode from the queue whose tail is 
pointed to by q. Do not remove this queueNode from the queue. Return NULL 
if the queue is empty. */
struct queueNode *headQ(struct queueNode *q)
{
    if (emptyQ(q)) return NULL;
    else return q->next;
}

