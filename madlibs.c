//Authors: Emma Comer, Tristan Pulsipher, Matthew Lewis
//Final Project

#include <stdio.h>

//specific file name macros
#define MADLIB "madlib1.txt"
#define STORAGE "storage.txt"
//these are for 2d or normal arrays 
#define MAXCOL 10 // Number of rows
#define MAXWIDE 20 //Number of Columns 
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
void read(FILE* fin);
//will be called in read() for when the user needs to give a word and will store it in a differnt txt file for later use
void userIn(char uin, FILE* fin);
//will be called to "initialize" every file, basically making sure everything is cleared before the main program actually starts
void init();

int main(){
	//declaring variables
	int bytes;
	char wordStore[MAXWIDE][MAXCOL];
	FILE* storePtr;
	
	//initializing
	init();
	bytes = 0;
	//rest of main function
	
	storePtr = fopen(STORAGE, "w"); 
	userInput(storePtr);
	fclose(storePtr);
	
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

//other possible userIn + read
void userIn(char uin, FILE* fin){
	int x, y, z;
	char a, b, userIn[MAXWIDE];
	
	switch(uin){
		case 'A':
			printf("Give me an adjective: ");
			scanf("%s" userIn);
			printf("\n");
			fprintf(fin, "%s\n" userIn);
		case 'N':
			printf("Give me a noun: ");
			scanf("%s" userIn);
			printf("\n");
			fprintf(fin, "%s\n" userIn);
		case 'V':
			printf("Give me a verb: ");
			scanf("%s" userIn);
			printf("\n");
			fprintf(fin, "%s\n" userIn);
	}
	
}

void read(FILE* fin){
	int x, y, z;
	char a, b, string[MAXWIDE];
	
	for (y = 1; y <= MAXLENGTH; y++){
		for (x = 1; x <= MAXWIDTH; x++){
			if (x % 2 == 0){
				fscanf("%c ", &a);
				userIn(a, fin);
			}
			else {
				fgets(string, MAXWIDE, fin);
			}
		}
	}
	
}


void userIn(FILE* fptr){
	int index1; 
	int index2; 
	char userArray[MAXCOL][MAXWIDE]; 
	for(index1 = 0; index1 < MAXCOL; index1++){ // Used to know what column of the array we are on to print right type of english word
		if(index1 == 0 || index1 == 2 || index1 == 5 || index1 == 7){
			for(index2 = 0; userArray[index2] !='\n'; index2++){
				printf("Please enter an adjective: "); 
				scanf("%s", userArray[index2]); 
				fprintf(fptr,"s", userArray[index2]); 
			}
		}else if(index1 == 1 || index1 == 6){
			for(index2 = 0; userArray[index2] !='\n'; index2++){
				printf("Please enter a noun: ");
				scanf("%s", userArray[index2]); 
				fprintf(fptr,"s", userArray[index2]); 
			}
		}else if(index1 == 3 || index1 == 4 ){
			for(index2 = 0;userArray[index2] !='\n'; index2++){
			printf("Please enter a verb: "); 
			scanf("%s", userArray[index2]);
			fprintf(fptr,"s", userArray[index2]); 
			}
		}
	}
}
char switch(FILE* fptr, char text, char userArray[MAXCOL][MAXWIDTH]){ //Should be opened in another read mode fucntion
//Looking to pass a string into the function
	int index; 
	char userArray[MAXCOL][MAXWIDTH];
	for(index = 0: index < MAXCOL; index++);
	switch(text){ 
		case 'A':
			if(index == 0 || index == 2 || index == 5 \\ index == 7){
				return userArray[index];
			}
		case 'N': 
			if(index == 1 || index == 6){
				return userArray[index];
			}
		case 'V':
			if(index == 3 || index == 4){
				return userArray[index]
			}
	}
}
	
			
	
	
	
	
	
	
