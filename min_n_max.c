#include <stdio.h>

int main(){
	int integer1, integer2, integer3;

	printf("Enter three numbers:");
	scanf("%d %d %d", &integer1, &integer2, &integer3);

	if(integer1<=integer2 && integer1<=integer3){
		printf("Minimum number is %d\n", integer1);
	}else if(integer2<=integer3 && integer2<=integer1){
		printf("Minimum number is %d\n", integer2);

	}else{
		printf("Minimum number is %d\n", integer3);
	}

	if(integer1>=integer2 && integer1>=integer3){
		printf("Maximum number is %d\n", integer1);
	}else if(integer2>=integer3 && integer2>=integer1){
		printf("Maximum number is %d\n", integer2);
	}else{
		printf("Maximum number is %d\n", integer3);
	}

	return 0;
}