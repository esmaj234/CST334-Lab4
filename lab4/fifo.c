// CST 334 Lab 4 â€“ FIFO Page Replacement Simulation File I/O Template

/* Name: Erin Smajdek
* Date: 2023-07-20
* Title: Lab4 
* Description: This program computes FIFO page replacement when a user inputs a file that lists page numbers 
and sets the cache size
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "queue.h"

typedef struct {//to 
    int pageno;
} ref_page;

struct queue *q;

int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache / page frame passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults

    q = queue_create(); // initialize the queue


    for (i = 0; i < C_SIZE; i++){//initialise cache array, where all spaces are open
        cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); {

        for(i = 0; i < C_SIZE; i++) {

            if (queue_length(q) <= C_SIZE) { // if the queue is shorter or equal to the cache size

                if (queue_find(q, page_num) != NULL) {  // if the page is already found in the queue
                    break;

                } else {
                    enqueue(q, page_num);
                    printf("%d",page_num);
                    printf("\n");
                    totalFaults++;
                }

            } else {
                // if page is in the queue
                if (queue_find(q, page_num) != NULL) { 
                    break;
                } else {
                    dequeue(q);
                    enqueue(q, page_num);
                    printf("%d",page_num);
                    printf("\n");
                    totalFaults++;
                }
            }
        }
    }
    }
    printf("\n");
    printf("\n");
    printf("Total Page Faults: %d", totalFaults);

    return 0;

}