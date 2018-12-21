/* Ejercicio 14 - Iteracion - PRIMOS*/
// Author: Liucas Serrenho

#include <conio.h>
#include <stdio.h>



int main()
{
	int QTOTAL,i=0,z,Qprimos=0;
  	bool NoPrimo;

	printf( "\t\n\n Ingrese Hasta que numero se analizan la condicion de ser primos o no: " );
	scanf(" %d",&QTOTAL);

	for (i=1;i<=QTOTAL;i++)
	{

	//	printf( "\t\n\nPRUEBA A VER DONDE MUERE 1" );

		z=1;
		NoPrimo=true;
		do{
			if ((i%z)==0 && z!=1)
			NoPrimo = false;

			if (z==i)
		{	Qprimos++;
			printf(" \n %d ES PRIMO",i);
			NoPrimo = false;
		}
			z++;
		}while(NoPrimo);
	}
				
		printf( " \n La cantidad total de numeros primos entre 1 y %d es de %d ",QTOTAL,Qprimos );

		getch(); /* Pausa */
    	return 0;


}

