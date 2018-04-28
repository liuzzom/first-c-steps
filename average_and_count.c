#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#define SIZE 16

int main(){
	pid_t pid;
	
	// pipe creation
	int pipe_fds[2];
	pipe(pipe_fds);
	char* buffer = malloc(SIZE*sizeof(char));

	// create a new process
	pid = fork();

	if(pid == 0){
		//child process
		close(pipe_fds[0]);
		int numbers[10];
		int i, M, total = 0;
		float m;

		// random number generation
		srand(time(NULL));
		for(i = 0; i < 10; i++){
			numbers[i] = rand()%10;
			printf("%d\t", numbers[i]);
			total += numbers[i];
		}
		printf("\ntotal:%d\n", total);
		m = (float)total/10;
		M = m;
		printf("m:%.2f M:%d\n", m, M);

		// send a the int average to parent process
		memset(buffer, 0, SIZE);
		sprintf(buffer, "%d", M);
		write(pipe_fds[1], buffer, SIZE-1);

	}else{
		//parent process
		close(pipe_fds[1]);
		int n, i;
    	read(pipe_fds[0], buffer, SIZE);
    	n=atoi(buffer);
    	for(i=0; i<n; i++){
      	printf("Ciao %d\n", i+1);
    	}
	}
}