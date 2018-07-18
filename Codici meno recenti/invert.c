#include <stdio.h>
#include <stdlib.h>

int
main(){
	int n,n1;
	printf("inserire n:\n");
	scanf("%i", &n);
	printf("n:%i\n",n);
	
	do{
		printf("%i", n%10);
		n=n/10;
	}while (n!=0);
	printf( "\n");
	return 0;
}
