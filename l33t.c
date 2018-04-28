#include <stdio.h>
#include <stdlib.h>
#define SIZE 64

// function prototypes

void leet(char* strPtr);

// main function

int main(int argc, char** argv){

	char* string;
	int index=1;

	if(argc<2){
		perror("Error: No words entered");
		exit(1);
	}

	while(argv[index]!=NULL){
		string=argv[index];
		leet(string);
		printf("%s ", string);
		index++;
	}

	puts("");

	return 0;
}
	
// functions

void leet(char* strPtr){

	while(*strPtr!='\0'){
		
		switch(*strPtr){
			
			case 'a':
			case 'A':{
				*strPtr='4';
				break;
			}
			
			case 'e':
			case 'E':{
				*strPtr='3';
				break;
			}

			case 'i':
			case 'I':{
				*strPtr='1';
				break;
			}

			case 'o':
			case 'O':{
				*strPtr='0';
				break;
			}

			case 'u':
			case 'U':{
				*strPtr='V';
				break;
			}				
		} // endswitch

		strPtr++;

	} //endwhile

}