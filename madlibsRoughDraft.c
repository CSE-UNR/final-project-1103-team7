#include <stdio.h>
#define STORAGE "storage1.txt"
#define MADLIBS "madlib2.txt"
#define MAXROWS 8
#define MAXCOLUMNS 30
#define FILEMAXHEIGHT 100 // Used as rows in the 
#define FILEMAXLENGTH 100 //Useful to find out if the madlibs file is 'awaiting' user input
#define FILECHARLENGTH 59
#define FILELINENUM 17 
void initalizeFile();
void userIn(int rows, int columns, char userArray[][columns]);
void inputStorage(FILE* fptr, int rows, int columns, char userArray[][columns]);
void displayMadlibs(FILE* fptr,int rows, int cols, char userArray[][cols]);
char* switchCharacters(int adjIndex, int nounIndex, int verbIndex, char placeholder, char userArray[][MAXCOLUMNS]);
int main(){
	char userArray1[MAXROWS][MAXCOLUMNS];
	userIn(MAXROWS, MAXCOLUMNS, userArray1);
	FILE* fptr; 
	FILE* fptr1; 
	FILE* fptr2;
	initalizeFile(); 
	fptr = fopen(STORAGE,"w"); //Opening Initalization function
	if(fptr == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	fclose(fptr);
	fptr1 = fopen(STORAGE, "w"); 
	if(fptr1 == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	inputStorage(fptr1, MAXROWS, MAXCOLUMNS, userArray1);
	fclose(fptr1); 
	fptr2 = fopen(MADLIBS, "r");
	if(fptr2 == NULL){
		printf("File couldn't open correctly\n"); 
		return 0;
	}
	displayMadlibs(fptr2, MAXROWS, MAXCOLUMNS, userArray1);
	fclose(fptr2); 
	return 0; 
}
void initalizeFile(){
	remove(STORAGE);
}
void userIn(int rows, int columns, char userArray[rows][columns]){
	int index1; 
	for(index1 = 0; index1 < rows; index1++){ // Used to know what column of the array we are on to print right type of english word
		if(index1 == 0 || index1 == 2 || index1 == 5 || index1 == 7){
			printf("Please enter an adjective: "); 
		}else if(index1 == 1 || index1 == 6){
			printf("Please enter a noun: ");
		}else if(index1 == 3 || index1 == 4 ){
			printf("Please enter a verb: "); 
		}
		scanf("%s", userArray[index1]); 
	}
}
