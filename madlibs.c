//Matthew Lewis Tristian Pulsipher Emma Comer 
//Final Project
//12.7.24
#include <stdio.h>
#define STORAGE "storage1.txt"
#define MADLIBS "madlib1.txt" //This code is structured to run madlib1.txt
#define MAXROWS 10
#define MAXCOLUMNS 30
#define FILEMAXHEIGHT 100 // Used as rows in the 
#define FILEMAXLENGTH 100 //Useful to find out if the madlibs file is 'awaiting' user input
#define FILECHARLENGTH 70
#define FILELINENUM 25
void userIn(int columns, char userArray[MAXROWS][MAXCOLUMNS], int text, int count);
void display(char userArray[MAXROWS][MAXCOLUMNS], FILE* fptr);
void reads(FILE* fin, char userArray[MAXROWS][MAXCOLUMNS]);
int characterCheck(char letter);
void endProgram(char* endReponse);
int main(){
	char e; 
	do{
	char userArray1[MAXROWS][MAXCOLUMNS];
	FILE* madlibfptr; 
	madlibfptr = fopen(MADLIBS,"r"); //Opening madlib for read function
	if(madlibfptr == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	printf("Enter your words for madlibs!\n");
	reads(madlibfptr, userArray1);
	fclose(madlibfptr);
	madlibfptr = fopen(MADLIBS, "r"); 
	if(madlibfptr == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	display(userArray1, madlibfptr);
	fclose(madlibfptr); 
	endProgram(&e);
	}while(e == 'Y' || e == 'y');
	return 0; 
}
void reads(FILE* fin, char userArray[MAXROWS][MAXCOLUMNS]){
	int x, y, z;
	int count = 0;
	char a, b;
	char string[100];
	for (y = 1; y <= 22; y++){
		fscanf(fin, "%c\n", &a);
		if (characterCheck(a)){
			userIn(MAXCOLUMNS, userArray, a, count);
			count++;
		}
		else {
			fgets(string, 100, fin);
		}
	}
	printf("\n");
}

void userIn(int columns, char userArray[MAXROWS][MAXCOLUMNS], int text, int count){
	switch(text){
		case 'A':
			printf("Enter an adjective: "); 
			scanf("%s", userArray[count]);
			break;
		case 'N':
			printf("Enter a noun: "); 
			scanf("%s", userArray[count]);
			break;
		case 'V':
			printf("Enter a verb: "); 
			scanf("%s", userArray[count]);
			break;
	}
}
void display(char userArray[MAXROWS][MAXCOLUMNS], FILE* fptr){
	char y, x;
	char a, string[100];
	int count = 0;
	for(y = 1; y <= FILELINENUM; y++){
		for (x = 1; x <= FILECHARLENGTH; x++){
			fscanf(fptr, "%c", &a);
			if (characterCheck(a)){
				printf(" %s", userArray[count]);
				count++;
			}
			else {
				if (a != '\n'){
					printf("%c", a);
				}
				else if (a == '\n'){
					printf(" ");
				}
			}
		}
	}
	printf("\n");
}
int characterCheck(char letter){ //Created as this check of letters was used twice 1 in read function and 1 in display function
	return letter == 'A' || letter == 'V' || letter == 'N';  
}
void endProgram(char* endResponse){ // I used pass by address to return global copy of the users end response to bottom of main function
	printf("Play again? Y or N\n");
	scanf(" %c", endResponse); 
}
	
