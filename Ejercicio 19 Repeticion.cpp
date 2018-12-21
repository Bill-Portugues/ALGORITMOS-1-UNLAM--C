/* Ejercicio 19- Iteracion - TEMPERATURA*/
// Author: Liucas Serrenho

#include <conio.h>
#include <stdio.h>
#define end -50

main()
{
	int min,max,PosMin,PosMax,med=0,i=0;



	do{

 		if(i>1)
		{
			if (med>=max)
			{
				max=med;
				PosMax=i;
			}
			if (med<=min)
			{
				min=med;
		        PosMin=i;
			}
		}
		else
		{
			min = med;
			PosMin=1;
			max = med;
			PosMax=1;
		}
		
		i++;

		printf("Ingrese la temperatura de la medicion #%d: ",i);
		scanf(" %d",&med);

		}while(med!=end);

	printf("\t\n La medicion minima fue la N #%d y fue de %d grados, \t\n La medicion máxima fue en la posicion N #%d y fue de %d grados",PosMin,min,PosMax,max);

	getch(); /* Pausa */
   	return 0;


}
