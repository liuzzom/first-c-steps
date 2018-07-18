#include <stdio.h>
#include <stdlib.h>

/* Protos
 *
 */ 

void 
insert(int array[], size_t number_of_elements, int value);
size_t
search(int array[], size_t number_of_elements, int value);
void
array_right_shift(int array[], size_t number_of_elements, size_t position);
void
array_print(int array[], size_t number_of_elements);

/* Functions
 *
 */

void 
insert(int array[], size_t number_of_elements, int value){
	size_t position;

	position=search(array, number_of_elements, value);
	array_right_shift(array, number_of_elements, position);
	array[position]=value;
}

size_t
search(int array[], size_t number_of_elements, int value){
	size_t i;	
	
	if(number_of_elements<=1){
		return 0;
	}
	for(i=0; i<number_of_elements; i++){
		if(array[i]>value){
			return i;
		}
	}	
	return number_of_elements-1;
}

void
array_right_shift(int array[], size_t number_of_elements, size_t position){
	size_t i;	
	
	for(i=number_of_elements-1; i>position ; i--){
		array[i]=array[i-1];
	}
}

void
array_print(int array[], size_t number_of_elements){
	size_t i;
	
	for(i=0;i<number_of_elements;i++){
		printf("%i ", array[i]);
	}
printf("\n");
}

int
main(){
	int values[]={1,3,5};
	size_t len;

	len=sizeof(values)/sizeof(int);

	array_print(values, len);
	insert(values, len, 2);
	array_print(values, len);
	
	return 0;
}
