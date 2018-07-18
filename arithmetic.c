#include <stdio.h>

int main(){
	int integer1, integer2, integer3;

	printf("Enter the first integer:");
	scanf("%d", &integer1);
	printf("Enter the second integer:");
	scanf("%d", &integer2);
	printf("Enter the third integer:");
	scanf("%d", &integer3);

	printf("%d %d %d\n", integer1, integer2, integer3);
	
	printf("Sum is %d\n", integer1+integer2+integer3);

	printf("Average is %.2f\n", (float)(integer1+integer2+integer3)/3.0);

	if(integer1<=integer2 && integer1<=integer3){
		printf("Min value is %d\n", integer1);
	}else if(integer2<=integer3 && integer2<=integer1){
		printf("Min value is %d\n", integer2);
	}else if(integer3<=integer1 && integer3<=integer2){
		printf("Min value is %d\n", integer3);
	}

	if(integer1>=integer2 && integer1>=integer3){
		printf("Max value is %d\n", integer1);
	}else if(integer2>=integer3 && integer2>=integer1){
		printf("Max value is %d\n", integer2);
	}else if(integer3>=integer1 && integer3>=integer2){
		printf("Max value is %d\n", integer3);
	}

	return 0;
}