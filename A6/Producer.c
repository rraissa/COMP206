#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Header.h"
#include <string.h>

void producer(){
	
	char c,t;
	FILE *turn,*data;

	FILE *source = fopen("mydata.txt","rt");	// open text file for reading 
	if(source == NULL){
		printf("Error with mydata.txt file");
		exit;
	}	
	
	do{				// while not at end of mydata.txt
		while(1){			// checking for its turn 
        		turn = fopen("TURN.txt","r");
		
			if(turn == NULL){
				printf("Error with TURN.txt file");
				exit;
			}
		
			t = fgetc(turn);
			fclose(turn); 
			if(t == '0') {
				break;
			}
		}

		c = fgetc(source);

		data = fopen("DATA.txt","w");	
		fprintf(data,"%c",c);

		if(data == NULL){
			printf("Error with DATA.txt file");
			exit;
		}		

		fclose(data);

		turn = fopen("TURN.txt","w");	// Change turn to consumer 
		fprintf(turn, "%c", '1');
		if(turn == NULL){
                                printf("Error with TURN.txt file");
                                exit;
                        }
		fclose(turn);
	} while(c!=EOF);

	fclose(source);
}
