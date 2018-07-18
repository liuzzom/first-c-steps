#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int
main(){
	float a,b,c,D,X1,X2,X;	
	printf("Inserire l'equazione di primo o secondo grado");
	printf("\nInserire Coefficente a:");
	scanf("%f",&a);
	
	printf("nserire Coefficente b:");
	scanf("%f",&b);
	
	printf("Inserire Coefficente c:");
	scanf("%f",&c);
	
	D=(b*b)-4*(a*c);
	X1=((-b)+sqrt(D))/(2*a);
	X2=((-b)-sqrt(D))/(2*a);
	X=-(b/c);
	
	if(a!=0){
		if(D>=0){
		printf("D=%3f\n",D);
		printf("X1=%3f\n", X1);
		printf("X2=%3f\n", X2);
		} else{
		printf("D è Negativo:D=%3f\n",D);
	}
	} else{
		printf("L'equazione è di primo grado\n");
		printf("X=%3f\n", X);
	}
return 0;
}
