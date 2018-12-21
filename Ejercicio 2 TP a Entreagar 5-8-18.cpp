//Ejercicio 2 8/5/2018 - Elementos de Programacion
//Autor: Lucas Serrenho



#include <stdio.h>
#include <conio.h>
#define tab 10

main()
{
	int NUM,i;

	printf("\t\n Ingrese el numero para hacer el calculo de la tabla:  ");
	scanf("%d",&NUM);

	for (i=1;i<=tab;i++)
		printf("\t\n %d x %d = %d",NUM,i,NUM*i);

    

getch(); /*Pausa*/
}
