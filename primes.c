#include <stdio.h>
#include <stdlib.h>

// prototypes

void error(char* msg);

int isPrime(int num);

void print(int* array, size_t size);

void bubble_sort(int* array, size_t size);

// main

int main(int argc, char** argv){
	int *primes = malloc((argc + 1)*sizeof(int));
	int *notPrimes = malloc((argc +1)*sizeof(int));
	size_t i=1, j=0, l=0;

	if(!primes || !notPrimes){
		error("Error wiht memory allocation");
	}

	if(argc < 2){
		error("Error on numbers");
	}

	while(argv[i]){
		if(!atoi(argv[i])){
			error("Error on inputs");
		}

		if(isPrime(atoi(argv[i])) == 1){
			primes[j] = atoi(argv[i]);
			j++;
		}else{
			notPrimes[l] = atoi(argv[i]);
			l++;
		}
		i++;
	}

	bubble_sort(primes, j);
	bubble_sort(notPrimes, l);

	printf("Primes: ");
	print(primes, j);
	printf("Not Primes: ");
	print(notPrimes, l);

	return 0;
}

// function

void error(char* msg){
	perror(msg);
	exit(0);
}

int isPrime(int num){
	size_t i=2;

	while(i <= num/2){
		
		if(num%i == 0){
			return 0;
		}

		i++;
	}

	return 1;
}

void print(int* array, size_t size){
	size_t i=0;

	while(i < size){
		printf("%d ", array[i]);
		i++;
	}

	puts("");

	return;
}

void bubble_sort(int* array, size_t size){
	size_t i, j;
	int tmp;

	for(i = 0; i< size-1; i++){
		for(j = 0; j < size-1; j++){
			if(array[j+1] < array[j]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}

	return;
}
