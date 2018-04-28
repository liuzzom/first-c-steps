#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 16

int main(void){
	pid_t pid;
	int pipe_fds[2];
	pipe(pipe_fds);
	char *buffer = malloc(SIZE * sizeof(char));

	pid = fork();

	if(pid <0){
		perror("Fork gone wrong...");
	} else if(pid == 0){
		//child process
		close(pipe_fds[0]);
		int i, m = 0;
		srand(time(NULL));
		for(i = 0; i < 10; i++){
			m += rand()%10;
			printf("%d\t", m);
		}
		puts("");
		m /= 10;
		printf("send %d\n", m);
		//send m to parent process
		memset(buffer, 0, SIZE);
		sprintf(buffer, "%d", m);
		write(pipe_fds[1], buffer, SIZE-1);
	}else{
		//parent process
		close(pipe_fds[1]);
		int i, n;
		read(pipe_fds[0], buffer, SIZE);
		n = atoi(buffer);
		printf("receveid %d\n", n);

		for(i = 0; i < n; i++){
			//create a child process that execute the echo Hello command
			pid = fork();
			if(pid == 0){
				execl("/bin/echo", "echo", "Hello", (char*)0);
			}else{
				wait(NULL);
			}
		}
	}
	return 0;
}
