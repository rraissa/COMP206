#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Global variable:
struct NODE *head;

// True/False for Success/Failure

typedef int bool;
#define true 0
#define false 1

// Functions:
// Initializes head to NULL
void newList(){
	head = NULL;
}

// Adding new node
int addNode(int value){
	struct NODE *new = (struct NODE*) malloc(sizeof(struct NODE));
	new->data=value; // Insert value in new node
	new->next=head; 
	head=new;	// New node becomes head

	if(head==NULL) return false;	// Return false for failure

	else return true;	 // Return true for success

}

// Print list
void prettyPrint(){	
	struct NODE *ptr=head; // starting with head
        //printf("\n[head] =>");
        while(ptr != NULL){
                printf(" %d => ", ptr->data);
                ptr=ptr->next; // moving to next node
	}
	
	printf(" [NULL]\n");
}

