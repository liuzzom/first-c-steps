#include <stdio.h>
#include <stdlib.h>

void
print_message(void){
	printf("Hello world!\n");
}

void
print_message_times(int times){
	int i;
	
	for(i=0;i<times; i++){
		printf("Hello world!\n");
	}
}

int
main(){
	int times;
	
	printf("Quante volte vuoi stmpare il messaggio?: ");
	scanf("%i", &times);
	print_message_times(times);

return 0;
}
