/* Ejercicio 16- Iteracion - Numeros Naturales*/
// Author: Liucas Serrenho

#include <conio.h>
#include <stdio.h>
#define mul1 3
#define mul2 5

main()
{
	int i=0,n,SPar=0, total,Q5=0,SM3=0;
	
	printf("Ingrese la cantidad de Numeros naturales a ingresar: ");
	scanf(" %d",&total);
		
	for(i=1;i<=total;i++)
	{
		printf("Ingrese el Numero natural # %d: ",i);
		scanf(" %d",&n);

		if(i%2==0)
			SPar+= n;

		if(n%mul1==0)
			SM3+=n;

		if(n%mul2==0)
			Q5++;


	}

	printf("\t\n Sumatoria de los pares: %d, \t\n Sumatorio de los multiplos de 3: %d, \t\n Cantidad de Multiplos de 5: %d",SPar,SM3,Q5);
	
	getch(); /* Pausa */
   	return 0;


}
