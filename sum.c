#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int sum=0, index=0;

	if(argc<2){
		perror("Error: Any number was entered");
		exit(1);
	}

	while(argv[index]){
		sum += atoi(argv[index]);
		index++;
	}

	printf("Sum is %d\n", sum);

	return 0;
}
