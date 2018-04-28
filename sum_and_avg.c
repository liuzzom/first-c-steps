#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#define SIZE 5

struct params{
	int *numbers;
	int sum;
	float average;
};

void* sum(void* args){
	struct params* pp = (struct params*) args;
	int i;

	pp->sum = 0;

	for(i = 0; i < SIZE; i++){
		pp->sum += pp->numbers[i];
	}

	return NULL; 
}

void* average(void* args){
	struct params* pp = (struct params*) args;
	int sum = 0, i;

	for(i = 0; i < SIZE; i++){
		sum += pp->numbers[i];
	}
	pp->average = (float)sum/SIZE;
}

int main(){
	pthread_t thread1_id, thread2_id;
	struct params threads_args;
	int i, array[SIZE];

	srand(time(NULL));

	for(i = 0; i < SIZE; i++){
		array[i] = (rand()%10)+1;
		printf("%d\t", array[i]);
	}
	puts("");
	threads_args.numbers = array;

	pthread_create(&thread1_id, NULL, &sum, &threads_args);
	pthread_create(&thread2_id, NULL, &average, &threads_args);
	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);

	printf("Sum:%d Average:%.2f\n", threads_args.sum, threads_args.average);

	return 0;
}