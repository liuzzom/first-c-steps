#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#define SIZE 10

struct params{
	size_t startPos, endPos;
	int *numbers;
};

typedef struct params params;

void* sum_function(void* args){
	params* pp = (params*) args;
	int i;
	int* partialSum = (int*) malloc(sizeof(int));

	*partialSum = 0;
	for(i = pp->startPos; i < pp->endPos; i++){
		*partialSum += pp->numbers[i];
	}

	return (void*) partialSum;
}

int main(){
	int array[SIZE], numThread, step, sum = 0, i, *tmp;
	srand(time(NULL));

	printf("Numero di thread da utilizzare:");
	scanf("%d", &numThread);

	// random generation
	for(i = 0; i < SIZE; i++){
		array[i] = rand()%10+1;
		printf("%d ", array[i]);
	}
	puts("");
	step = SIZE/numThread;

	// verify if the number of array elements is divisible by the number of threads
	if(SIZE%numThread == 0){
		pthread_t* threads_ids = malloc(numThread*sizeof(pthread_t));
		params* threads_args = malloc(numThread*sizeof(params));
		//threads args inizialization and threads creation
		for(i = 0; i < numThread; i++){
			threads_args[i].numbers = array;
			threads_args[i].startPos = step*i;
			threads_args[i].endPos = step*(i+1);
			pthread_create(&threads_ids[i], NULL, &sum_function, &threads_args[i]);
		}
		//waiting for threads conclusion and add up the partial sums
		for(i = 0; i < numThread; i++){
			pthread_join(threads_ids[i], (void**) &tmp);
			sum += *tmp;
		}

		printf("Sum:%d\n", sum);
	}else{
		pthread_t* threads_ids = malloc((numThread+1)*sizeof(pthread_t));
		params* threads_args = malloc((numThread+1)*sizeof(params));
		//threads args inizialization and threads creation
		for(i = 0; i < numThread; i++){
			threads_args[i].numbers = array;
			threads_args[i].startPos = step*i;
			threads_args[i].endPos = step*(i+1);
			pthread_create(&threads_ids[i], NULL, &sum_function, &threads_args[i]);
		}
		threads_args[numThread].numbers = array;
		threads_args[numThread].startPos = SIZE-(SIZE%numThread);
		threads_args[numThread].endPos = SIZE;
		pthread_create(&threads_ids[numThread], NULL, &sum_function, &threads_args[numThread]);
		//waiting for threads conclusion and add up the partial sums
		for(i = 0; i < numThread; i++){
			pthread_join(threads_ids[i], (void**) &tmp);
			sum += *tmp;
		}
		pthread_join(threads_ids[numThread], (void**) &tmp);
		sum += *tmp;

		printf("Sum:%d\n", sum);
	}

	return 0;
}
