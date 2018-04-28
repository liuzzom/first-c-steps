#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;

	pid = fork();

	if(pid == 0){
		//child process
		printf("Child process executes ls command...\n");
		execl("/bin/ls", "ls", "-1", "--color", (char*)0);
	}else{
		//parent process
		printf("Parent process wait child process...\n");
		wait(NULL);
		printf("Parent process end...\n");
	}
}