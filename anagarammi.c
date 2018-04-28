#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

// functions prototypes

void string_print(char parola[], size_t misura); // stampa una stringa

void string_perm(char parola[], size_t start , size_t misura); // genera le possibili operazioni di una stringa

void string_left_swap(char parola[], size_t start , size_t misura);

// main

int main(int argc, char const **argv){
	char parola[MAX];

	// inserimento della parola
	printf("Inserire una parola(max %d caratteri):", MAX);
	scanf("%s", parola);
	// misura la lunghezza della parola
	size_t misura=strlen(parola);

	string_perm(parola, 0, misura);

	return 0;
}


// functions

void string_print(char parola[], size_t misura){
	size_t i;

	for(i=0; i<misura; i++){
		printf("%c", parola[i]);
	}
	printf("\n");
}

void string_perm(char parola[], size_t start , size_t misura){
	size_t i;

	if(start<misura){
		for(i=start; i<misura; i++){
			string_perm(parola, start+1, misura);
			string_left_swap(parola, start, misura);
		}
	}else{
		string_print(parola, misura);
	}
}

void string_left_swap(char parola[], size_t start , size_t misura){
	size_t i;
	char temp;

	if(misura>1){
		temp=parola[start];
		for(i=start; i<misura-1; i++){
			parola[i]=parola[i+1];
		}
		parola[i]=temp;
	}
}
