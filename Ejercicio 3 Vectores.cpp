//Ejercicio 3 Vectores - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#define Q 6

int MAXIMO(int[],int);
void PRINTMAX(int[],int,int);
void CARGASEC(int[],int);

main()
{
	int VA[Q];
	int MAX;
	
	CARGASEC(VA,Q);
	MAX=MAXIMO(VA,Q);
	PRINTMAX(VA,MAX,Q);



getch(); /*Pausa*/

}

///////////////////////

void PRINTMAX(int V[],int MAX,int QV)
{
	int i;

	if(QV>0)
	    printf("\t\n El sueldo Maximo es %d y los siguientes empleados son los que lo cobran: \n ",MAX);


	for (i=0;i<QV;i++)
	{
        	if(MAX==V[i])
            	printf("\t\n LEGAJO %3d ",i+1);
	}
}

///////////////////////

int	MAXIMO(int V1[], int QV)
{
	int i,MAX=V1[0];

	for (i=1;i<QV;i++)
	{
		if(MAX<V1[i])
		    MAX=V1[i];
	}
	
	return(MAX);
}

///////////////////////

void CARGASEC(int V[],int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
		printf("\t\n Ingrese Numero %d: ",i+1);
		scanf(" %d", &V[i]);
	}
}

