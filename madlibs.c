//Authors: Emma Comer, Tristan Pulsipher, Matthew Lewis
//Final Project

#include <stdio.h>

//specific file name macros
#define MADLIB "madlib1.txt"
#define STORAGE "storage.txt"
//these are for 2d arrays 
#define MAXCOL 10
#define MAXWIDE 20
//these are for files
#define MAXWIDTH 100
#define MAXLENGTH 100
//these are for the madlib files
//max file width out of the both of them is 67
//max file length out of the both of them is 22
//other useful stuff to know is when maxfilelength % 2 == 0 there's a user input

//displays chosen file
void display(FILE* fin);
//reads a chosen madlib txt file
char read(FILE* fin);
//will be called in read() for when the user needs to give a word and will store it in a differnt txt file for later use
void userIn(char uin, FILE* fin);
//will be called to "initialize" every file, basically making sure everything is cleared before the main program actually starts
void init();

int main(){
	//declaring variables
	char wordStore[MAXWIDE][MAXCOL];
	FILE* storePtr;
	storePtr = fopen(STORAGE, "w"); 
	userInput(storePtr);
	fclose(storePtr);
	
	//initializing
	init();
	//rest of main function
	
	return 0;
}

//initialization function
void init(){
	FILE* initPtr;
	remove(STORAGE);
	initPtr = fopen(STORAGE, "w");
	fclose(initPtr);
}

//function to display file -T
void display(FILE* fin){
	int x, y, z;
	char a, b;
	
	for (y = 1; y <= MAXLENGTH; y++){
		for (x = 1; x <= MAXWIDTH; x++){
			fscanf(fin, "%c ", &a);
			if (x == MAXWIDTH){
				printf("%c", a);
			}
			else {
				printf("%c ", a);
			}
		}
		printf("\n");
	}
}
void userIn(FILE* fptr){
	int index1; 
	int index2; 
	char userArray[MAXCOL][MAXWIDE]; 
	for(index1 = 0; index1 < MAXCOL; index1++){ // Used to know what column of the array we are on to print right type of english word
		if(index1 == 0 || index1 == 2 || index1 == 5 || index1 == 7){
			for(index2 = 0; index2 < MAXWIDTH ; index2++){
				printf("Please enter an adjective: "); 
				scanf("%s", userArray[index2]); 
				fprintf(fptr,"s", userArray[index2]); 
			}
		}else if(index1 == 1 || index1 == 6){
			for(index2 = 0; index2 < MAXWIDTH ; index2++){
				printf("Please enter a noun: "); 
				scanf("%s", userArray[index2]); 
				fprintf(fptr,"s", userArray[index2]); 
			}
		}else if(index1 == 3 || index1 == 4 ){
			for(index2 = 0; index2 < MAXWIDTH; index2++){
			printf("Please enter a verb: "); 
			scanf("%s", userArray[index2]);
			fprintf(fptr,"s", userArray[index2]); 
			}
		}
	}
}
	
			
	
	
	
	
	
	
