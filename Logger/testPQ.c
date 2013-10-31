
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
    Date *date; // date is a pointer to date structure which has the date information.
} Data, *QueueData;

#include "pq.h"

QueueData getData();

int main(int argc, char** argv) {
    Queue Q = (Queue) malloc(sizeof (QueueType)); // allocate base size of queue;
    Q = initQueue();

    QueueData np = (QueueData) malloc(sizeof (Data)); // Allocate space for new assignment.
    np = getData(); // Collect data from user
    enqueue(Q, np); // Add data to queue.   


    // Output the Assignment Data.
    QueueData dequeueData = malloc(sizeof (QueueData)); // For storing data of dequeued element.
    dequeueData = dequeue(Q); // Remove an assignment from the queue and save its contents.
    printf("Assignment Name: %s\n", dequeueData->assignmentName); // Name
    printf("Course Name: %s\n", dequeueData->courseName); // Course
    printf("Possible Points: %d\n", dequeueData->points); // Score
    printf("Day Due: %d\n", dequeueData->date->day); // Day
    printf("Month Due: %d\n", dequeueData->date->month); // Month



    return (EXIT_SUCCESS);
}

// helper functions

QueueData getData() {
    // Allocate memory for our new assignment information.
    DateInfo di = (DateInfo) malloc(sizeof (Date)); // Create structure containing date information   
    QueueData np = (QueueData) malloc(sizeof (Data)); // Create a node pointer for assignment data
    
    // Variables used for giving data to assignment.
    char *assignmentName;
    char *courseName;
    int points;
    int day;
    int month;
    
    /*
       Note: %[^\n]%*c is being used instead of the gets function to get a string from user.     
     */
    
    // Get user input for name of assignment and course.
    printf("INPUT ASSIGNMENT,\n");
    printf("Assignment Name: ");
    scanf("%[^\n]%*c", assignmentName);
    printf("Course Name: ");
    scanf("%[^\n]%*c", courseName);

    while (1) {
        printf("Possible Points: ");
        if (scanf("%d", &points)) {
            break; // Leave the while loop if an integer was entered.
        } else {
            // Otherwise, the user entered something erroneous. Continue asking for score input.
            scanf("%*[^\n]");
        }
    }
    while (1) {
        printf("Day Due: ");
        if (scanf("%d", &day)) {
            break; // Leave the while loop if an integer was entered.
        } else {
            // Otherwise, the user entered something erroneous. Continue asking for score input.
            scanf("%*[^\n]");
        }
    }
    while (1) {
        printf("Month Due: ");
        if (scanf("%d", &month)) {
            break; // Leave the while loop if an integer was entered.
        } else {
            // Otherwise, the user entered something erroneous. Continue asking for score input.
            scanf("%*[^\n]");
        }
    }

    // Assign collected values to their corresponding components in data structure
    di->day = day;
    di->month = month;
    np->assignmentName = assignmentName;
    np->courseName = courseName;
    np->points = points;
    np->date = di; // Assign date information to our np pointer.
    
    return np; // Return new assignment to be added to the queue.
}


#endif
