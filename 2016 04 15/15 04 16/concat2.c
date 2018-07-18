#include <stdio.h>
#include <stdlib.h>

//Prototipi//

void
string_concat(const char s1[], const char s2[], char sc[]);

//Funzioni//

void
string_concat(const char s1[], const char s2[], char sc[]){
	size_t i,j;
	i=0;
	j=0;
	
	while(s1[i]!='\0'){
		sc[i]=s1[i];
		i++;
	}
	while(s2[j]!='\0'){
		sc[i]=s2[j];
		i++;
		j++;
	}
	sc[i]='\0';
}

//Main//

int
main(){
	char s1[30];
	char s2[30];
	char sc[60];

	printf("Inserire prima stringa:");
	scanf("%29s", s1);
	printf("Inserire seconda stringa:");
	scanf("%29s", s2);
	
	string_concat(s1, s2, sc);
	printf("%s\n", sc);

return 0;
}
