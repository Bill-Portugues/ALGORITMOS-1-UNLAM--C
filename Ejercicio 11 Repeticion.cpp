/* Ejercicio 11 - Iteracion*/
// Author: Liucas Serrenho
// Se considera cooperativa como no efectivo

#include <conio.h>
#include <stdio.h>
#define DCoop -0.3
#define DEfect -0.1
#define DTarj 0.12
#define IVA 0.21

int main()
{

	float Efect=0,Tarj=0, Coop=0, Vent, VentTotal ;
	char codigo;
	bool Fin=true,Val;



	do
	{

		Val = true;
		do
		{
			printf( "\t\n Ingrese el codigo de la venta \t\n C = Cooperativa - T = Tarjeta - E = EFECTIVO \t\n O Presione 'F' para Finalizar \t\n " );
	    	scanf(" %c",&codigo);
	    		
				if (codigo=='F')
				{
					Val =false;
				    Fin =false;
				}
					else if(codigo != 'C' && codigo!='T' && codigo != 'E')
							printf( "\t\n CODIGO INVALIDO" );

						else
	  					{
						    Val=false;
						    printf( "\t\n Ingrese el importe total de la venta: " );
	    					scanf("%f",&Vent);
						}



		}while(Val);

		
   		switch(codigo)
		   {
			case 'C':
				Coop += Vent*(1+DCoop);
				break;

			case 'E':
				Efect+= Vent*(1+DEfect);
				break;

			case 'T':
				Tarj += Vent*(1+DTarj);
				break;

			case 'F':
				Fin = false;
				printf( "\t\n Finalizacion del dia ");
				break;

			}
	}while(Fin);
	
	VentTotal = Efect+Tarj+Coop;

		printf("\n\t Efectivo en caja %.2f \n\t Ventas con tarjeta %.2f \n\t Total de Ventas %.2f \n\t Importe del IVA %.2f",Efect,Tarj,VentTotal,VentTotal*IVA);

		getch(); /* Pausa */
    	return 0;


}










