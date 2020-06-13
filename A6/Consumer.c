#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header.h"
#include <string.h>

// Forked consumer function
void consumer(){

	char t='\0';
	char c='\0';
	FILE *turn,*data;

	int temp;

	while(1){
		temp=1;

		while(1){
			turn = fopen("TURN.txt", "r");
		
			if(turn == NULL){
				printf("Error with TURN.txt file");
				exit;
			}
	
			t = fgetc(turn);
			fclose(turn);
				
			if(t=='1'){	// check if turn 
				break;
			}
		}

		data = fopen("DATA.txt","r");	// extract char from DATA.txt
		c = fgetc(data);
		if(data == NULL){
                                printf("Error with DATA.txt file");
                                exit;
                        }
		fclose(data);

		if(c == EOF){
			break;
			// putc(c,stdout);
			// printf("%c",c);
		}

		printf("%c",c);

		turn = fopen("TURN.txt","w+");
		fprintf(turn, "%d", 0);	// Change turn to producer
		
		if(turn == NULL){
                                printf("Error with TURN.txt file");
                                exit;
                        }

		fclose(turn);
		
	}
}
