#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_NOME 41
#define MAX_CONTATTI 100

struct contattoSCL
{
	char* nome;
	unsigned int numero;
	struct contattoSCL* successivo;
};

typedef struct contattoSCL nodoRubricaSCL;
typedef nodoRubricaSCL* RubricaSCL;

void getch();
void clear_screen();
void stampaOpzioni();
void aggiungiContatto(RubricaSCL* rubrica, int* contatti);
void inserisciNodo(RubricaSCL rubrica, char* tempNome, unsigned int tempNumero);
void stampaRubrica(RubricaSCL rubrica);
void stampaAusiliaria(RubricaSCL rubrica, int posizione);
int checkRubricaVuota(RubricaSCL rubrica);
void cercaContatto(RubricaSCL rubrica);
void ricercaRicorsiva(char* ricercato, RubricaSCL rubrica);

void clear_screen()
{
	DWORD n, size;
	COORD coord = { 0 };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	size = csbi.dwSize.X*csbi.dwSize.Y;
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
	SetConsoleCursorPosition(h, coord);
}

int main()
{
	int scelta = -1, contatti = 0;
	RubricaSCL rubrica = NULL;
	while (scelta != 0)
	{
		stampaOpzioni();
		scanf("%d", &scelta);
		if ((scelta > 0) && (scelta < 4))
		{
			clear_screen();
		}
		switch (scelta)
		{
		case 1: aggiungiContatto(&rubrica, &contatti); break;
		case 2: cercaContatto(rubrica); break;
		case 3: stampaRubrica(rubrica); getch(); break;
		}
		if ((scelta > 0) && (scelta < 4))
		{
			clear_screen();
		}
	}
	printf("\n");
	return 0;
}

void stampaOpzioni()
{
	printf("Rubrica // Elenco funzioni:\n\n"
		   "1 - Aggiungi contatto\n"
		   "2 - Ricerca per nome\n"
		   "3 - Stampa rubrica\n"
		   "Inserisci 0 per uscire\n\n"
		   "Inserisci un numero: ");
}

void aggiungiContatto(RubricaSCL* rubrica, int* contatti)
{
	if (*contatti == MAX_CONTATTI)
	{
		printf("La rubrica non ha spazio per altri contatti! :'(");
		getch();
		return;
	}
	printf("Inserisci il nome del contatto: ");
	char* tempNome = (char*)malloc(sizeof(char) * MAX_NOME);
	unsigned int tempNumero;
	scanf("%s", tempNome);
	printf("Inserisci il numero da salvare: ");
	scanf("%u", &tempNumero);
	if (*rubrica == NULL)
	{
		*rubrica = (RubricaSCL)malloc(sizeof(nodoRubricaSCL));
		(*rubrica)->nome = tempNome;
		(*rubrica)->numero = tempNumero;
		(*rubrica)->successivo = NULL;
	}
	else
	{
		inserisciNodo(*rubrica, tempNome, tempNumero);
	}
	(*contatti)++;
}

void inserisciNodo(RubricaSCL rubrica, char* tempNome, unsigned int tempNumero)
{
	if (rubrica->successivo == NULL)
	{
		nodoRubricaSCL* nuovo = (nodoRubricaSCL*)malloc(sizeof(nodoRubricaSCL));
		nuovo->nome = tempNome;
		nuovo->numero = tempNumero;
		nuovo->successivo = NULL;
		rubrica->successivo = nuovo;
		return;
	}
	inserisciNodo(rubrica->successivo, tempNome, tempNumero);
}

void stampaRubrica(RubricaSCL rubrica)
{
	if (!checkRubricaVuota(rubrica))
	{
		return;
	}
	stampaAusiliaria(rubrica, 1);
}

int checkRubricaVuota(RubricaSCL rubrica)
{
	if (rubrica == NULL)
	{
		printf("La rubrica non contiene alcun contatto! :(");
		getch();
		return 0;
	}
	return 1;
}

void stampaAusiliaria(RubricaSCL rubrica, int posizione)
{
	printf("%d\nNome: %s\nNumero: %u\n\n", posizione, rubrica->nome, rubrica->numero);
	if (rubrica->successivo != NULL)
	{
		stampaAusiliaria(rubrica->successivo, posizione + 1);
	}
}

void cercaContatto(RubricaSCL rubrica)
{
	if (!checkRubricaVuota(rubrica))
	{
		return;
	}
	char* ricerca = (char*)malloc(sizeof(char) * MAX_NOME);
	printf("Inserisci il contatto da cercare: ");
	scanf("%s", ricerca);
	ricercaRicorsiva(ricerca, rubrica);
}

void ricercaRicorsiva(char* ricercato, RubricaSCL rubrica)
{
	if (strcmp(rubrica->nome, ricercato) == 0)
	{
		printf("Numero del contatto: %d", rubrica->numero);
		getch();
		return;
	}
	if (rubrica->successivo == NULL)
	{
		printf("Il contatto non si trova nella rubrica");
		getch();
		return;
	}
	ricercaRicorsiva(ricercato, rubrica->successivo);
}