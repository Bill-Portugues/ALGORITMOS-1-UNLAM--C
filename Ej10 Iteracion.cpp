//Ejercicio 10 - Estructura de Repeticion
// Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#define  Desc 0.1
#define TopeDesc 1000

main()
{
int NroFac,Q,QFac=0;
float  Puni,ImpFac,SumImpFac=0;


printf("Ingrese el numero de factura: ");
scanf("%d",&NroFac);

do
{

	printf("/n/tIngrese el precio unitario: ");
	scanf("%f",&Puni);

	printf("/n/tIngrese la cantidad vendida: ");
	scanf("%d",&Q);


	ImpFac=Puni*Q;
	if (ImpFac>TopeDesc)
		ImpFac *= (1-Desc);

	SumImpFac += ImpFac;
	QFac++;

	printf("/n/t Importe de Factura: %.2f /n/t Recaudacion del negocio %.2f /n/t Cantidad de Facturas hasta ahora: %d",ImpFac, SumImpFac,QFac );

	printf("Ingrese el numero de factura: ");
	scanf("%d",&NroFac);


}while(NroFac!=0);

printf("\n\t SALIO DEL PROGRAMA" );
getch(); /*Pausa*/
}
