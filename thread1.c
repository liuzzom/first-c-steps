#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//prototypes

void* print_msg(void* unused);

// main

int main(){
	pthread_t thread_id;

	pthread_create(&thread_id, NULL, &print_msg, NULL);

	while(1){
		printf("Main Thread:%d\n", (int)pthread_self());
		sleep(1);
	}

	return 0;
}

// function

void* print_msg(void* unused){
	while(1){
		printf("Created Thread:%d\n", (int)pthread_self());
		sleep(1);
	}
	return NULL;
}
