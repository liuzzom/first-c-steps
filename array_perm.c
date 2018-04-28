#include <stdio.h>
#include <stdlib.h>

void
array_print(int array[], size_t size){
	size_t i;

	for(i=0; i<size; i++){
		printf("%i ", array[i]);
	}
	printf("\n");
}

void
array_rotate_left(int array[], size_t size, size_t start){
	size_t i;
	int temp;

	//printf("array_rotate_left size:%zd, start:%zd\n", size, start);

	if(size>1){
		temp=array[start];
		for(i=start; i<size-1; i++){
			array[i]=array[i+1];
		}
		array[i]=temp;
	}
}

void
array_perm(int array[], size_t size, size_t start){
	size_t i;

	//printf("array_perm size:%zd, start:%zd\n", size, start);

	if(start<size){
		for(i=start; i<size; i++){
			array_perm(array, size, start+1);
			array_rotate_left(array, size, start);
		}
	}else{
		array_print(array, size);
	}
}

int
main(){
	int array[]={1,2,3,4};
	size_t size;

	size=sizeof(array)/sizeof(int);
//	array_print(array, size);
//	array_rotate_left(array, size, 0);
//	array_print(array, size);
	array_perm(array, size, 0);

	return 0;
}
