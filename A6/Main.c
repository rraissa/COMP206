// Name: FARDON Raïssa
// ID: 260689524

// Partner's name: Marilena Anghelopoulou
// Partner's ID: 260530237


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header.h"
#include <sys/wait.h>

extern void producer();
extern void consumer();

int main(){

	FILE *turn;

	turn=fopen("TURN.txt", "w");
	fputc('0',turn); 	// Initialize TURN to 0 (consumer's turn)	
	fclose(turn);

	int pid = fork();	

	if (pid==0) {
		consumer();	// Execute consumer
	}
	else if (pid > 0) {
		producer();	// Execute producer
	}
	else {
		exit(1);	// Error
	}

	return 0;
}
