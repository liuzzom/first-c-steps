#include <stdio.h>
#include <stdlib.h>

int
main(){
	int n;
	printf("inserire n:");
	scanf("%i", &n);
	printf("n=%i\n",n);
	
	if(n>0){
		printf("%i è positivo\n",n);
	}else if(n==0){
		printf("%i è zero\n",n);
	}else {
		printf("%i è negativo\n",n);
	}
return 0;
}
