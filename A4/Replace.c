#include <stdio.h>
#include <stdlib.h>

//Declaration of functions
void FindRecord(char *filename, char *name, char record[]);
void Replace(char *name, char *newname, char record[]);
void SaveRecord(char *filename, char *name, char record[]);
int compare(char *first, char *second);

int main(){
	// Variable declaration
	char rec[1000], o_name[1000]={'\0'}, n_name[1000]={'\0'};
	char *old_name=o_name, *new_name=n_name, *file="./phonebook.csv";
	
	// Ask user for input
	printf("Input the name to replace: ");
	scanf("%[^\n]%*c", old_name);

	printf("\nInput the replacement name: ");
	scanf("%[^\n]%*c", new_name);

	// Calling function to find specific record
	FindRecord(file, old_name, rec);

	// Calling function to replace the record with the new one
	Replace(old_name, new_name, rec);
	
	// Calling function to save the new record into the file
	SaveRecord(file, old_name, rec);

	return 0;
}


void FindRecord(char *filename, char *name, char record[]){

	// Variable declaration
	FILE *fp = fopen(filename, "r"); // Open file to read it
	char buffer[1000]={'\0'}, *temp=record, n[1000]={'\0'};

	while(fgets(record, 999, fp)!=NULL){	// while there are still records to be read
		sscanf(record, "%[^,]", n);	// get name from record
		if(compare(n, name)==0){	// if name matches
			sscanf(record, "%[^\n]", temp); // store record
			break;
		}
	}
		
	if(fgets(buffer, 999, fp)==NULL && compare(n, name)==-1 /*findSubstring(record, name)==-1*/){ // otherwise if no more records & no match
                 printf("\nName not found. Try again.\n");	// print error messafe
                 exit(0);	// exit program
        }
	

	fclose(fp);	// close file
}



void Replace(char *name, char *newname, char record[]){

	// Variable declaration
	char *buffer=record;
	char *old_name=name, *new_name=newname;
	char *tmp_name, *tmp_buff, *final;

	sscanf(record, "%[^\n]", buffer); // load record into buffer
	
	sscanf(record, "%[^,]", name); // get "old" name from record and store it in name

	sscanf(record, "%[^,]%s", name, buffer); 	// get record without "old" name
	
	tmp_buff=buffer;		// store it into tmp_buff

	// new name replaces old name
	name=new_name;
	sscanf(name, "%[^\n]", newname);
	
	final=new_name;

	// Store entire record with new name in final
	while (*new_name){
		*final=*new_name;
		++new_name;
		++final;
	}


	while(*tmp_buff){
		*final=*tmp_buff;
		++tmp_buff;
		++final;
	}


	sscanf(newname, "%[^\n]", buffer); // since the record was stored in newname, put it back in record
	
	sscanf(buffer, "%[^\n]", newname); // and put the new name back in newname
}
	

void SaveRecord(char *filename, char *name, char record[]){
	
	// Variable declaration
	FILE *new = fopen("./newphonebook.csv", "w"); // New file to write in
	FILE *fp = fopen(filename, "r+");	// Source file to read from

	char *temp=record,  *old_record;
	char buff[1000]={'\0'};
	char n[1000]={'\0'};


	while(fgets(buff, 999, fp) != NULL){	// While it's not the end of the file
		sscanf(buff, "%[^,]", n);	// Get name from source file
		if(compare(name, n)==0){	// If it matches the name the user input
		fprintf(new, "%s\n", temp); 	// Write new record to new file

	}
	else fputs(buff, new);	// Else write the original record to file
		
	}
	
	// Close files
	fclose(fp);
	fclose(new);
		
	remove(filename); // remove original "phonebook.csv"
	rename("newphonebook.csv", "phonebook.csv");	// new file becomes "phonebook.csv"
}


// Function to test if strings are the same (to replace strcmp())  -- http://www.programmingsimplified.com/c-program-compare-two-strings
int compare(char *one, char *two){
		
	while(*one==*two){	// while elements of the two strings are the same
		if(*one=='\0' || *two == '\0')	// if one of the strings is empty, exit function
		break;

	one++;
	two++;
		
	}
	
	if(*one == '\0' && *two == '\0') return 0;	// if end of both strings, return 0
	else return -1;	// else return -1

}
