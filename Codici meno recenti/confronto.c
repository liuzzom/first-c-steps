#include <stdio.h>
#include <stdlib.h>

int
main(){
	int n,n1;
	printf("inserire primo numero:");
	scanf("%i",&n);
	printf("inserire secondo numero:");
	scanf("%i",&n1);

	if(n>n1){
		printf("%i>%i\n",n,n1);
	}else if(n==n1){
		printf("%i=%i\n",n,n1);
	}else{
		printf("%i<%i\n",n,n1);
	}
return 0;
}
