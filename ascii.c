#include <stdio.h>

int main(){
	char character='A';

	while(character<='Z'){
		printf("%c %d\n", character, character);
		character++;
	}

	return 0;

}