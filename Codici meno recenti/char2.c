#include <stdio.h>

int
main(){
	int a[4]={1,2,3,4};
	char c[5]={'H', 'e', 'l', 'l', 'o'};
	float d[20];
	int z=3;
	int i;
	
	for(i=0; i<4; i++){
		printf("%i ", a[i]);
	}
	printf("\n");
	
	a[0]=4;
	a[1]=7;
	for(i=0; i<5; i++){
		printf("%c", c[i]);
	}
	printf("\n");
	
	return 0;
}

	
