#include <stdio.h>
#include <stdlib.h>

int
main(){
	int i,n,sum=0;
	printf("%p\n",&n);
	printf("Inserire n=");
	scanf("%i",&n);
	while(i<=n){
	sum+=i++;
	}
	printf("sum: %i\n", sum);
	return 0;
	}
