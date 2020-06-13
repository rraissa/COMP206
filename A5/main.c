#include <stdio.h>
#include <stdlib.h>
#include "list.h"

extern struct NODE *head;
extern void newList();
extern int addNode(int value);
extern void prettyPrint();

void main(){

// Variable declaration
int n;

printf("\nEnter a number: \n");
if(scanf("%d", &n)==1);	// Take user input, if it's an integer, do nothing
else{	// If input is not an integer, print error message
	printf("Error: input is not a number.\n");
	exit(1);
}

// Make list
newList();

while(n>0){
	addNode(n); // Calling addNode() function from list.c
	printf("\nEnter a number: \n");
        if(scanf("%d", &n)==1);
	else{	// If user input is not a number, print error message
		printf("\nError: input is not a number.\n");
        	exit(2);
		}
	}

// Terminate loop if n<0
while(n<0){
	printf("\nNegative number entered.\n");
	break;
	}

// Terminate loop if n=0
while(n==0){
	printf("\nZero is not a positive number.\n");
	break;
	}

printf("\n");

// Print list
prettyPrint();

}

