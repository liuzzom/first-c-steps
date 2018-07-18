#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

int
main(){
	char string1[MAX], string2[MAX];

	printf("Inserire una stringa:");
	scanf("%29s", &string1);

	printf("Stringa Inserita:%s\n", string1);
	printf("Stringa Copiata:%s\n", strcpy(string2, string1));

	printf("Inserire stringa per il concatenamento:");
	scanf("%29s", &string2);
	printf("Stringa Concatenata:%s\n", strcat(string1, string2));

return 0;
}
