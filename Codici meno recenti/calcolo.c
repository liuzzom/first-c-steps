#include <stdio.h>
#include <stdlib.h>

int
main(){
	int n1,n2,ris;
	char op;
	printf("inerire operazione:");
	scanf("%i%c%i", &n1,&op,&n2);
	switch(op){
		case '+':{
			ris=n1+n2;
			break;
		}
		case '-':{
			ris=n1-n2;
			break;
		}
		case '*':{
			ris=n1*n2;
			break;
		}
		case '/':{
			ris=n1/n1;
			break;
		}
		default:{
			printf("operatore %c sconosciuto\n", op);
			break;
		}
	}	
				
	printf("%i%c%i=%i\n", n1,op,n2,ris);
	return 0;
}
