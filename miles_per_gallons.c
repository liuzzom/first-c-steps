#include <stdio.h>

int main(){
	int miles, gallons;
	float result;

	do{
		printf("Insert the miles driven, or a negative number to exit:");
		scanf("%d", &miles);
		if(miles>=0){
			printf("Insert the gallons used:");
			scanf("%d", &gallons);
			printf("car fuel efficiency: %.2f miles per gallon\n", (float)miles/gallons);
		}
	}while(miles>=0);


	return 0;
}