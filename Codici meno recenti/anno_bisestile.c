#include <stdio.h>
#include <stdlib.h>

int
main(){
	int anno, rem_4, rem_100, rem_400;
	
	printf("Inserire anno:");
	scanf("%i", &anno);
	
	rem_4=anno%4;
	rem_100=anno%100;
	rem_400=anno%400;
	
	if( (rem_4==0 && rem_100!=0) || (rem_400==0) ){
		printf("Anno Bisestile.\n");
	}else{
		printf("Anno Comune.\n");
	}
	
	return 0;
}
