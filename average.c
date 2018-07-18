#include <stdio.h>

int main(){
	
	unsigned int counter=0; // counter of the while loop
	int grade; 
	int total=0;
	float average;

	puts("Welcome");

	while(counter<10){
		printf("Enter a grade(%d/10):", counter+1);
		scanf("%d", &grade);
		total+=grade; // increase the total value by the grade value 
		counter++; // increase counter value by one 
	}

	average=(float)total/10;
	printf("Average is %.2f\n", average);

	return 0;
}
