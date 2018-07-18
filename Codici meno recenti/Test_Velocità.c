#include <stdio.h>
#include <limits.h>
//Made by Loris Mendola, edited by Mauro Liuzzo//

int main( void )
{
	printf("Made by Loris Mendola, edited by Mauro Liuzzo\n");
	unsigned long long int contatore;
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	unsigned long long int d;
	unsigned long long int e;
	unsigned long long int f;
	unsigned long long int g;
	unsigned long long int h;
	unsigned long long int i;
	unsigned long long int l;
	int ripetizioni;
	unsigned long long int m;
	contatore=0;
	a=100000000;
	b=10000000;
	c=20000000;
	d=30000000;
	e=40000000;
	f=50000000;
	g=60000000;
	h=70000000;
	i=80000000;
	l=90000000;
	m=100000000;

	printf("Inserire numero ripetizioni(max 2): ");
	scanf("%d", &ripetizioni);


	a=a*ripetizioni;
	
	while( ++contatore <= a )
{	
	if( contatore == b )
{
	puts("10.000.000");
}
	if( contatore == c )
{
	puts("20.000.000");
}
	if( contatore == d )
{
	puts("30.000.000");
}
	if( contatore == e )
{
	puts("40.000.000");
}
	if( contatore == f )
{
	puts("50.000.000");
}
	if( contatore == g )
{
	puts("60.000.000");
}
	if( contatore == h )
{
	puts("70.000.000");
}
	if( contatore == i )
{
	puts("80.000.000");
}
	if( contatore == l )
{
	puts("90.000.000");
}
	if( contatore == m+b )
{
	puts("10.000.000");
}
	if( contatore == m+c )
{
	puts("20.000.000");
}
	if( contatore == m+d )
{
	puts("30.000.000");
}
	if( contatore == m+e )
{
	puts("40.000.000");
}
	if( contatore == m+f )
{
	puts("50.000.000");
}
	if( contatore == m+g )
{
	puts("60.000.000");
}
	if( contatore == m+h )
{
	puts("70.000.000");
}
	if( contatore == m+i )
{
	puts("80.000.000");
}
	if( contatore == m+l )
{
	puts("90.000.000");
}
}
	
	puts("Fine programma"); 
}
