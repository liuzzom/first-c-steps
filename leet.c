#include <stdio.h>
#define SIZE 64

// function prototypes

void leet(char* strPtr);

// main function

int main(){
	char string[SIZE];

	printf("Enter a string:");
	scanf("%s", string);

	printf("String entered:%s\n", string);

	leet(string);

	printf("Leeted string:%s\n", string);

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