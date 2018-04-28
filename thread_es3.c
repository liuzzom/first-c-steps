#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct params{
	char character;
	int times;
};

void* print_char(void* parameters){
	struct params* pp = (struct params*) parameters;
	int i;

	for(i=0; i<pp->times; i++){
		printf("%c\n", pp->character);
		sleep(1);
	}
	return (void*) &(pp->times);
}

int main(){
	pthread_t thread1_id, thread2_id;

	struct params thread1_args;
	struct params thread2_args;

	int* thread1_rvalue;
	int* thread2_rvalue;

	thread1_args.character='A';
	thread1_args.times=10;

	thread2_args.character='B';
	thread2_args.times=20;


	pthread_create(&thread1_id, NULL, &print_char, &thread1_args);
	pthread_create(&thread2_id, NULL, &print_char, &thread2_args);

	pthread_join(thread1_id, (void**) &thread1_rvalue);
	pthread_join(thread2_id, (void**) &thread2_rvalue);

	printf("Thread 1 times:%d\nThread 2 times:%d\n", *thread1_rvalue, *thread2_rvalue);

	return 0;

}