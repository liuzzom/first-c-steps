#include <stdio.h>
#include <stdlib.h>

void
print_message_times(int times){
	
	for(;times>0; times--){
		printf("[%02i] Hello world!\n", times);
	}
	printf("times: %i\n", times);
}

int
main(){
	int times;
	
	printf("Quante volte vuoi stmpare il messaggio?: ");
	scanf("%i", &times);
	print_message_times(times);
	
	printf("times: %i\n", times);

return 0;
}
