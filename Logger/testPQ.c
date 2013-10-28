
//Test enqueue(), getFront(), and dequeue() functions for priority queue of integers 

//Date is a structure with data fields: month, day: int. (We assume that all the assignments are given in the same calendar year.)
//Assignment is a structure with data fields: 
//courseName: char[], 
//assignmentName: char [], 
//points: int, 
//dueDate: Date. 

#define TEST 1 // before testing please ensure that you have disabled AssignmentLog.c by making disable 1.
#if TEST


#include <stdio.h>
#include <stdlib.h>
#define NAMESIZE 80

/*LIBRARY STRUCTURES*/
typedef struct { // Date structure which 
    int month;
    int day;
    // int year; // we are to assume that assignments are within the same calender year.
} Date, *DateInfo;

typedef struct { // QueueData = individual Assignments to be added to the queue
    char *courseName;
    char *assignmentName;
    int points;
    Date *date;
} Data, *QueueData;

#include "pq.h"

QueueData getData();

int main(int argc, char** argv) {
    Queue Q = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
    Q = initQueue();

    QueueData np = (QueueData) malloc(sizeof (Data)); // allocate space for new item
    np = getData(); // collect data from user
    enqueue(Q, np); // add data to queue    


    // show output of data
    QueueData dequeueData = malloc(sizeof (QueueData));
    dequeueData = dequeue(Q);
    printf("assignmentName: %s\n", dequeueData->assignmentName);
    printf("courseName: %s\n", dequeueData->courseName);
    printf("points: %d\n", dequeueData->points);
    printf("due, day: %d\n", dequeueData->date->day);
    printf("due, month: %d\n", dequeueData->date->month);



    return (EXIT_SUCCESS);
}

// helper functions

QueueData getData() {
    // allocate memory 
    DateInfo di = (DateInfo) malloc(sizeof (Date));    
    QueueData np = (QueueData) malloc(sizeof (Data));
    
    // variables used for data collection
    char *assignmentName;
    char *courseName;
    int points;
    int day;
    int month;
    
    // get user input
    printf("INPUT ASSIGNMENT,\n");
    printf("assignmentName: ");
    scanf ("%[^\n]%*c", assignmentName);
    printf("courseName: ");
    scanf ("%[^\n]%*c", courseName);

    while (1) {
        printf("points: ");
        if (scanf("%d", &points)) {
            break;
        } else {
            /**** Erroneous input, get rid of it and retry! */
            scanf("%*[^\n]");
        }
    }
    while (1) {
        printf("due, day: ");
        if (scanf("%d", &day)) {
            break;
        } else {
            /**** Erroneous input, get rid of it and retry! */
            scanf("%*[^\n]");
        }
    }
    while (1) {
        printf("due, month: ");
        if (scanf("%d", &month)) {
            break;
        } else {
            /**** Erroneous input, get rid of it and retry! */
            scanf("%*[^\n]");
        }
    }

    // assign collected values to their corresponding components in data structure
    di->day = day;
    di->month = month;
    np->assignmentName = assignmentName;
    np->courseName = courseName;
    np->points = points;
    np->date = di;
    
    return np; // return new assingment to be added to the queue
}


#endif