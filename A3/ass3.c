#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

// Variable declaration
int key;
char text[300] = {'\0'};
char encrypted[300] = {'\0'};
char decrypted[300] = {'\0'};
int length;


// Ask for user input
printf("Sentence: ");
fgets(text, 300, stdin);

printf("\n"); // blank line

printf("Key: ");
scanf("%d", &key);

printf("\n"); // blank line


// Print original message
printf("Original message: %s\n", text);


// Get length of string
length = strlen(text);


// Check key range
if (key < 1) {
	printf("Enter key between 1 and 25.\n");
	return 1;
	}

if (key > 25) {
	printf("Enter key between 1 and 25.\n");
	return 1;
}


// Encrypting message
for (int i = 0;i<length; i++) {

	if (text[i] >= 'A' && text[i] <= 'Z') { // if upercase letter
		text[i] = text[i]- 'A'; // convert to integer
		encrypted[i] = (text[i] - key) % 26; // shift left
			if(encrypted[i]<0){ // if negative number, fix it by wrapping
				encrypted[i] = 26 - (-encrypted[i]);
			}

		encrypted[i] = encrypted[i] + 'A'; // re-convert to letter
		}	


	else if (text[i] >= 'a' && text[i] <= 'z') { // if lowercase letter -- same as previously
		text[i] = text[i] - 'a';
		encrypted[i] = (text[i] - key) % 26;
			if(encrypted[i]<0){
                                encrypted[i] = 26 - (-encrypted[i]);
                        }

		encrypted[i] = encrypted[i] + 'a'; 
		}

	else {	// if not a letter, skip over & leave it as it is
		encrypted[i] = text[i];
		}

	}


// Print encrypted message
printf("Encrypted message: %s\n", encrypted);


//Decrypting message
for (int j = 0; j<length; j++) {

	if (encrypted[j] >= 'A' && encrypted[j] <= 'Z') { // if uppercase letter
		encrypted[j] = encrypted[j]- 'A'; // convert to integer
		decrypted[j] = (encrypted[j] + key) % 26; // shift right
		decrypted[j]= decrypted[j]+ 'A'; // re-convert to letter
		}	

	else if (encrypted[j] >= 'a' && encrypted[j] <= 'z') { // if lowercase letter -- same as previously
                encrypted[j] = encrypted[j]- 'a';
                decrypted[j] = (encrypted[j] + key) % 26;
                decrypted[j]= decrypted[j]+ 'a';
                }
	
	else { // if not a letter, skip over & leave it as it is
		decrypted[j] = encrypted[j];
		}

	}


// Print decrypted message
printf("Decrypted message: %s\n", decrypted);


return 0;

}
