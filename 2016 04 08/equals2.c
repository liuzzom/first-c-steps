#include <stdio.h>
#include <stdlib.h>

//Definizioni//

#define True 1
#define False 0

//Prototipo//
size_t 
string_length(char s[]);

int
string_equals(char s[], char s2[]);

//Funzioni//

size_t
string_length(char s[]){
	size_t length;
	length=0;
	while(s[length]!='\0'){
			length++;
		}
	return length;
}

int
string_equals(char s[], char s2[]){
	size_t i;
	
	while( (s[i]==s2[i]) && (s[i]!='\0' && s2[i]!='\0') ){
		i++;
	}
	
	return (s[i]=='\0' && s2[i]=='\0');
}
		

//Main//

int
main(){
	char s[];
	char s2[];
	printf("Inserire prima stringa:");
	scanf("%9s", s);
	primtf("Inserire seconda stringa:");
	scanf("%9s", s2);
	printf("%s equals %s %i\n", s, s2, string_equals(s, s2));
		
	return 0;
}
