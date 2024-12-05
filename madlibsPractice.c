//Matthew Lewis, Emma Comer, Tristian Pulsipher
// Final Project Shit
#include <stdio.h>
#define STORAGE "storage1.txt"
#define MADLIBS "madlibs2.txt"
#define MAXROWS 10
#define MAXCOLUMNS 20
#define FILEMAXHEIGHT 100 // Used as rows in the 
#define FILEMAXLENGTH 100 //Useful to find out if the madlibs file is 'awaiting' user input
#define FILECHARLENGTH 59
#define FILELINENUM 17 
void initalizeFile();
void userIn(int rows, int columns, char userArray[][columns]);
void inputStorage(FILE* fptr, int rows, int columns, char userArray[][columns]);
void displayMadlibs(FILE* fptr,int rows, int cols, char userArray[][cols]);
char* switchCharacters(int rows, int cols, int rows1, int cols1, char userArray[][cols],char codeArray[][cols1]);
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
		printf("%s\n", userArray[index1]); //Debugging Statements
	}
}
void inputStorage(FILE* fptr, int rows, int columns, char userArray[][columns]){
	int index1;
	for(index1 = 0; index1 < rows; index1++){
		fprintf(fptr,"%s", userArray[index1]);
		fprintf(fptr,"\n");
	}
}
void displayMadlibs(FILE* fptr,int rows, int cols, char userArray[][cols]){
	char textArray[FILELINENUM][FILEMAXLENGTH];
	int index1; 
	int index2; 
	for(index1 = 0; index1 < FILELINENUM; index1++){
			if(fgets(textArray[index1],FILEMAXLENGTH,fptr) == NULL){
				break;
			}
				for(index2 = 0;textArray[index1][index2] != '\0'; index2++){
					if(textArray[index1][index2] == 'A' || textArray[index1][index2] == 'V' || textArray[index1][index2] == 'N'){
						printf("Found placeholder '%c'.\n", textArray[index1][index2]); // Debugging output
						printf("%s", switchCharacters(rows, cols, index1, index2, userArray, textArray)); 
					}else{
						printf("%c", textArray[index1][index2]); 
					}
					
				}
	}
}
	
char* switchCharacters(int rows, int cols, int rows1, int cols1, char userArray[][cols],char codeArray[][cols1]){
    static int adjIndex = 0; // Tracks adjectives
    static int nounIndex = 0; // Tracks nouns
    static int verbIndex = 0; // Tracks verbs

    char placeholder = codeArray[rows1][cols1]; // Current placeholder character

    switch (placeholder) {
        case 'A': // Adjective
            if (adjIndex < rows) {
                return userArray[adjIndex++]; // Return current adjective and increment
            }
            break;

        case 'N': // Noun
            if (nounIndex < rows) {
                return userArray[nounIndex++]; // Return current noun and increment
            }
            break;

        case 'V': // Verb
            if (verbIndex < rows) {
                return userArray[verbIndex++]; // Return current verb and increment
            }
            break;
    }

    return ""; // Default return if no match
}

