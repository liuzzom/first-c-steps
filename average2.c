#include <stdio.h>

int main(){
	unsigned int counter=0;
	int total=0;
	int grade

	puts("Welcome");

	do{
		printf("Please enter a grade, or a negative number to exit:");
		scanf("%d", &grade);
		if(grade>=0){
			total+=grade;
			counter++;
		}
	}while(grade>=0);

	if(counter!=0){
		printf("Average is %.2f\n", (float)total/counter);
	}else{
		puts("No grades were entered");
	}

	return 0;
}