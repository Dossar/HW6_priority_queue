/* 
 * File:   queue.h
 * Author: mike
 *
 * Created on October 21, 2013, 10:26 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h> 

    typedef struct node {
        QueueData data;
        struct node *next;        
    } Node, *NodePtr;

    typedef struct queueType {
        NodePtr head, tail;
        int size;
    } QueueType, *Queue;

    /*Sets up and initializes the queue*/
    Queue initQueue() {
        Queue qp = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue
        // Since the queue is empty at initialization, the head and tail pointers will be null.
        qp -> head = NULL;
        qp -> tail = NULL;
        qp -> size = 0;
        return qp; // return our new queue
    }

    /*Decides if the queue is empty or not*/
    int isEmpty(Queue Q) {
        return (Q -> head == NULL); // check if head is null
    }

    /*Add a value to the tail of the queue*/
    void enqueue(Queue Q, QueueData d) {
        NodePtr np = (NodePtr) malloc(sizeof (Node)); // allocate needed space for new value
        // add data to this new value
        np -> data = d;
        np -> next = NULL;        

        if (isEmpty(Q)) { // check if queue is empty first
            // if it is empty head and tail are the same, NULL.
            Q -> head = np;
            Q -> tail = np;
        } else {
            
            /*
             
             So are we comparing np to Q->head for adding to the priority queue?
             I thought of some possible if statements, check over these and see if they can be used
             
             if( (np->data->date->month) < (Q->head->data->date->month) )
             // Check to see if month is smaller number than the current head.
             
             if( (np->data->date->day) < (Q->head->data->date->day) )
             // Check to see if day is smaller number than the current head.
              
             if( (np->data->date->day) == (Q->head->data->date->day) )
             // Check to see if both days are the same. 
             
             if( (np->data->points) > (Q->head->data->points) )
             // This if is for when the dates are the exact same.
             
             
             
             */
            
            // otherwise we need to search for where it belongs in the queue
            // priority section here
            // loop through all values in queue comparing the dates first
                // if two have the same date compare their point values
            
            // insert value at this point
            
            Q -> tail -> next = np;
            Q -> tail = np;
        }
        Q->size++;
    }

    /*Remove a value from the head of the queue*/
    QueueData dequeue(Queue Q) {
        if (isEmpty(Q)) { // check if its empty first
            // This is an error case meaning we're trying to remove from an empty queue
            exit(1); // exits the program here (perhaps add error case?)
        }
        QueueData hold = Q -> head -> data; // Hold is storing the data of the head node.
        NodePtr temp = Q -> head; // Create a temporary node for the head.
        Q -> head = Q -> head -> next; // Shift the head position of the queue to the next node
        if (Q -> head == NULL) Q -> tail = NULL; // If head is now null then so is tail
        free(temp); // free associated memory
        Q->size--; // shorten queue size
        return hold; // return our temp data
    }

    /*Returns the value at the head of the queue without removing it*/
    QueueData getFront(Queue Q) {
        if (isEmpty(Q)) { // check if its empty first
            // Queue is empty in this case, can't check the head of an empty queue.
            exit(1); // exits the program here (perhaps add error case?)
        }
        return Q->head->data; // simply return the queue data that is the current head
    }     

#ifdef	__cplusplus
}
#endif

#endif	/* QUEUE_H */

