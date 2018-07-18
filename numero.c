#include <stdio.h>

int main(){
	int n;
	
	printf("Io i numeri non li dimentico mai.\nHo un metodo infallibile, si basa sugli anni di Cristo. è una bomba, me l'ha insegnato uno di Salerno\nDimmi un numero:");
	
	do{
		scanf("%d", &n);
		if(n<=33){
			printf("%d? Non si può fare, il numero deve essere superiore a 33. è la regola\n", n);
		}else{
			printf("%d: gli anni di Cristo piu %d. Stampato, e chi se lo dimentica più!\n", n, n-33);
		}
	}while(n>0);

	return 0;
}