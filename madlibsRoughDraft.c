//Matthew Lewis main and userFunction
#include <stdio.h>
#define STORAGE "storage1.txt"
#define MADLIBS "madlib1.txt" //This code is structured to run madlib1.txt
#define MAXROWS 10
#define MAXCOLUMNS 30
#define FILEMAXHEIGHT 100 // Used as rows in the 
#define FILEMAXLENGTH 100 //Useful to find out if the madlibs file is 'awaiting' user input
#define FILECHARLENGTH 59
#define FILELINENUM 21
void initalizeFile();
void userIn(int rows, int columns, char userArray[][columns]);
int main(){
	char userArray1[MAXROWS][MAXCOLUMNS];
	userIn(MAXROWS, MAXCOLUMNS, userArray1);
	FILE* madlibfptr; 
	madLibFptr = fopen(MADLIB,"r"); //Opening Initalization function
	if(fptr == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	fclose(madlibFptr);
	madlibFptr = fopen(MADLIBS, "r"); 
	if(madLibFptr == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	fclose(fptr1); 
	fptr2 = fopen(MADLIBS, "r");
	if(madLibFptr == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	fclose(madlibFptr); 
	return 0; 
}
void initalizeFile(){
	remove(STORAGE);
}

void read(FILE* fin, char userArray[rows][columns]){
	int x, y, z;
	int count = 0;
	char a, b;
	char string[100];
	for (y = 1; y <= 22; y++){
		fscanf(fin, "%c\n", &a);
		if (a == 'A' || a == 'V' || a == 'N'){
			userIn(MAXCOLUMNS, userArray, a, count);
			count++;
		}
		else {
			fgets(string, 100, fin);
		}
	}
}

void userIn( int columns, char userArray[][columns], int text, int count){
	switch(text){
		case 'A':
			printf("Enter an adjective: "); 
			scanf("%s", userArray[count];
			break;
		case 'N':
			printf("Enter a noun: "); 
			scanf("%s", userArray[count];
			break;
		case 'V':
			printf("Enter a verb: "); 
			scanf("%s", userArray[count];
			break;
	}
}

