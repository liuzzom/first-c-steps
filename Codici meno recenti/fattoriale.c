#include <stdio.h>
#include <stdlib.h>

main(){
	int n,n1,fatt;
	printf("inserire numero:\n");
	scanf("%i",&n);
	n1=n;	
	fatt=1;
	while(n>0){
		fatt=fatt*n;
		n--;
		}
	printf("%i!=%i\n", n1,fatt);
	return 0;
}
