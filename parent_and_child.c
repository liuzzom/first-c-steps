#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;

	printf("[Padre] PID:%d\n", (int)getpid());

	pid = fork();

	if(pid == 0){
		//child process
		printf("[Figlio] PID:%d\n", (int)getppid());
		sleep(3);
		printf("[Figlio] Ho dormito e adesso termino\n");
	}else{
		wait(NULL);
		printf("[Padre] Figlio PID:%d ha finito e termino anch'io\n", pid);
	}
	return 0;
}