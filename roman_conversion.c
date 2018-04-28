#include <stdio.h>
#include <stdlib.h>
#define SIZE 32

//prototypes

void print(char* strPtr);

// main
int main(int argc, char** argv){
	unsigned int number, index=0, i=0;
	char* convertedNumber = malloc(SIZE * sizeof(char));

	if(argc != 2 || atoi(argv[1]) <= 0){
		perror("Error on number");
		exit(1);
	}

	number = atoi(argv[1]);

	if(number > 0){
		
		while(number >= 1000){
			//puts("1000");
			convertedNumber[index] = 'M';
			index++;
			number -= 1000;
		}

		while(number >= 500){
			//puts("500");
			convertedNumber[index] = 'D';
			index++;
			number -= 500;
		}

		while(number >= 100){
			//puts("100");
			convertedNumber[index] = 'C';
			index++;
			number -= 100;
		}

		while(number >= 50){
			//puts("50");
			convertedNumber[index] = 'L';
			index++;
			number -= 50;
		}

		while(number >= 10){
			//puts("10");
			convertedNumber[index] = 'X';
			index++;
			number -= 10;
		}

		while(number >= 5){
			//puts("5");
			convertedNumber[index] = 'V';
			index++;
			number -= 5;
		}

		while(number >= 1){
			//puts("1");
			convertedNumber[index] = 'I';
			index++;
			number -= 1;
		}
	}

	print(convertedNumber);

	return 0;
}

// function

void print(char* strPtr){

	while(*strPtr != '\0'){
		printf("%c", *strPtr);
		*strPtr++;
	}

	printf("\n");
}