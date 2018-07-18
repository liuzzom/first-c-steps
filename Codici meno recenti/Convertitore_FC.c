#include <stdio.h>
#include <stdlib.h>

/* stampa la tabella Fahrenheit-Celsius
	per fahr = 0,20,40,60,80,100,120,140,160,180,200,220,240,260,260,300	*/

int
main()
{
	printf("Benvenuti al Convertitore Fahrenheit-Celsius\n");
	float fahr, celsius;
	int lower, upper, step;
	lower=0; /* limiite inferiore della tabella */
	upper=300; /* limite superiore */
	step=20; /* incremento */
	fahr=lower;
	while (fahr<=upper)
	{
		celsius=(5.0/9.0)*(fahr-32);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr=fahr+step;
	}
	printf("Inserire temperatura in Celius:");
	scanf("%f",&celsius);
	fahr=(5.0/9.0)*celsius+32;
	printf("%3.0f %6.1f\n", fahr, celsius);
}
