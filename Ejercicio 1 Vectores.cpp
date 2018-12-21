//Ejercicio 1 Vectores - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#define Q 10

void CARGASEC(int[],int);
void COPIARVECTORES(int[],int[],int);
void SUMA2VEC(int[],int[],int[],int);
void INVERSOVEC(int[],int[],int);
void LISTAR4VEC(int[],int[],int[],int[],int);
void PRINTIFPAR(int[],bool,int);
int  SUMAVEC(int[],int);
float PROMEVEC(int[],int);
int QELEMENTOVEC(int[],int,int);

main()
{
	int VA[Q],VB[Q],VC[Q],VD[Q];
	int SUMA,QELEMENTO;
	float PROME;

	CARGASEC(VA,Q);
	COPIARVECTORES(VA,VB,Q);
	SUMA2VEC(VA,VB,VC,Q);
	INVERSOVEC(VA,VD,Q);
	LISTAR4VEC(VA,VB,VC,VD,Q);
	PRINTIFPAR(VA,true,Q);
	PRINTIFPAR(VA,false,Q);
	SUMA=SUMAVEC(VA,Q);
	printf("\t\n Suma Vector A %d",SUMA);
	PROME=PROMEVEC(VA,Q);
	printf("\t\n Promedio Vector A %.2f",PROME);
	QELEMENTO=QELEMENTOVEC(VA,32,Q);
	printf("\t\n Cantidad de elementos 32: %d",QELEMENTO);

getch(); /*Pausa*/

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

///////////////////////

void COPIARVECTORES(int V1[],int V2[], int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
		V2[i]=V1[i];
	}
}


///////////////////////

void SUMA2VEC(int V1[],int V2[],int V3[], int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
		V3[i]=V1[i]+V2[i];
	}
}

///////////////////////

void INVERSOVEC(int V1[],int VINVERSO1[], int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
		VINVERSO1[i]=V1[QV-i-1];
	}
}

////////////////////////

void LISTAR4VEC(int V1[],int V2[],int V3[],int V4[], int QV)
{
	int i;

	printf("\t\n	NRO     	VA  	VB  	VC  	VD");

	for (i=0;i<QV;i++)
	{
		printf ("\t\n	%3d) 	%5d  %5d  %5d  %5d",i+1,V1[i],V2[i],V3[i],V4[i]);

	}
}

////////////////////////

void PRINTIFPAR(int V1[],bool PARES,int QV)
{
	int i;
	
	if(PARES==true)
	    printf("\t\n PARES");
	else
	    printf("\t\n IMPARES");

	for (i=0;i<QV;i++)
	{
		if(V1[i]%2==0)
	    {	if (PARES==true)
		        printf("\t\n Posicion %d",i+1);
		}
		else
		{   if (PARES==false)
		        printf("\t\n Elemento %d ",V1[i]);
		}
	}
}

/////////////////////////

int SUMAVEC(int V1[], int QV)
{
	int i,SUMA=0;

	for (i=0;i<QV;i++)
	{
		SUMA += V1[i];
	}

	return (SUMA);
}

///////////////////////


float PROMEVEC(int V1[], int QV)
{

	return((float)SUMAVEC(V1,QV)/QV);
	

}

///////////////////////

int QELEMENTOVEC(int V1[],int ELEMENTO,int QV)
{
	int SUMA=0,i;

	for (i=0;i<QV;i++)
	{
		if(ELEMENTO == V1[i])
			SUMA++;
	}

	return (SUMA);
}
