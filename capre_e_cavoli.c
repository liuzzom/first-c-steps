#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void regole();

void mossa(bool* personaggi);

void status(bool* personaggi);

int controllo(bool* personaggi);

int main(int argc, char** argv){
	bool personaggi[4] = {false, false, false, false};
	// personaggi[0] = Contadino; personaggi[1] = Lupo
	// personaggi[2] = Capra ; personaggi[3] = Cavolo

	regole();

	do{
		mossa(personaggi);
		status(personaggi);
	}while(controllo(personaggi) == 0);

}

void regole(){

	puts("L'obettivo del gioco e' quello di portare Lupo, Capra e Cavolo dall'altro lato della riva di un fiume");
	puts("La barca puo' trasportare solo una cosa insieme al contadino");
	puts("Non si puo' lasciare il Lupo insieme alla Capra, ne' la Capra insieme al Cavolo");

	return;
}

void mossa(bool* personaggi){
	int scelta;

	puts("Seleziona un personaggio da mettere sulla barca insieme al contadino");
	puts("1-Lupo");
	puts("2-Capra");
	puts("3-Cavolo");
	puts("4_Nessuno");
	
	scanf("%d", &scelta);

	switch(scelta){
		case 1:{
			puts("Hai scelto il Lupo");
			if(personaggi[0] == personaggi[1] && personaggi[0] == false){
				personaggi[0] = true;
				personaggi[1] = true;
			}else if(personaggi[0] == personaggi[1] && personaggi[0] == true){
				personaggi[0] = false;
				personaggi[1] = false;
			}else{
				puts("Mossa non consentita. Si muove solo il Contadino");
				if(personaggi[0] == false){
					personaggi[0] = true;
				}else{
					personaggi[0] = false;
				}
			}
			break;
		}
		case 2:{
			puts("Hai scelto la Capra");
			if(personaggi[0] == personaggi[2] && personaggi[0] == false){
				personaggi[0] = true;
				personaggi[2] = true;
			}else if(personaggi[0] == personaggi[2] && personaggi[0] == true){
				personaggi[0] = false;
				personaggi[2] = false;
			}else{
				puts("Mossa non consentita. Si muove solo il Contadino");
				if(personaggi[0] == false){
					personaggi[0] = true;
				}else{
					personaggi[0] = false;
				}
			}
			break;
		}
		case 3:{
			puts("Hai scelto il Cavolo");
			if(personaggi[0] == personaggi[3] && personaggi[0] == false){
				personaggi[0] = true;
				personaggi[3] = true;
			}else if(personaggi[0] == personaggi[3] && personaggi[0] == true){
				personaggi[0] = false;
				personaggi[3] = false;
			}else{
				puts("Mossa non consentita. Si muove solo il Contadino");
				if(personaggi[0] == false){
					personaggi[0] = true;
				}else{
					personaggi[0] = false;
				}
			}
			break;
		}
		case 4:{
			puts("Si muove solo il Contadino");
			if(personaggi[0] == false){
				personaggi[0] = true;
			}else{
				personaggi[0] = false;
			}
		}
		default:{
			if(scelta != 4){
				puts("Scelta non valida");
			}
			break;
		}
	}
}

void status(bool* personaggi){
	size_t i;

	for(i=0; i<4; i++){
		printf("personaggio[%d]:%d\n", i, personaggi[i]);
	}

}

int controllo(bool* personaggi){

	if(personaggi[1] == personaggi[2] && personaggi[2] != personaggi[0]){
		puts("Hai Perso! Riprova");
		return-1;
	}
	if(personaggi[2] == personaggi[3] && personaggi[2] != personaggi[0]){
		puts("Hai Perso! Riprova");
		return-1;		
	}else if(personaggi[0] == true && personaggi[1] == true  && personaggi[2] == true && personaggi[3] == true){
		puts("Hai Vinto!");
		return 1;
	}else{
		return 0;
	}

}
	// personaggi[0] = Contadino; personaggi[1] = Lupo
	// personaggi[2] = Capra ; personaggi[3] = Cavolo