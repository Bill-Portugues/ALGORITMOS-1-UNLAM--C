//Ejercicio 4 Vectores - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#define Q 6

int MAXIMO(int[],int);
void PRINTMAX(int[],int[],int,int);
void CARGASEC(int[],int[],int);
int LeeControlRangoExpulsor (int,int,int =-9999);
int LeeControlNroExpulsor (int,int=-9999);

main()
{
	int VLEGAJO[Q],VSUELDO[Q];
	int MAX;

	CARGASEC(VLEGAJO,VSUELDO,Q);
	MAX=MAXIMO(VSUELDO,Q);
	PRINTMAX(VLEGAJO,VSUELDO,MAX,Q);



getch(); /*Pausa*/

}

///////////////////////

void PRINTMAX(int REPORTEAR[],int BUSCAR[],int MAX,int QV)
{
	int i;

	if(QV>0)
	    printf("\t\n El sueldo Maximo es %d y los siguientes empleados son los que lo cobran: \n ",MAX);


	for (i=0;i<QV;i++)
	{
        	if(MAX==BUSCAR[i])
            	printf("\t\n LEGAJO %3d ",REPORTEAR[i]);
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

void CARGASEC(int VAL[],int NOVAL[],int QV)
{
	int i,dato;

	for (i=0;i<QV;i++)
	{
		printf("\t\n Ingrese Legajo %d: ",i+1);
		dato=LeeControlNroExpulsor(4);
		VAL[i]=dato;
		printf("\t\n Ingrese Sueldo %d: ",i+1);
		scanf(" %d", &dato);
		NOVAL[i]=dato;
		
	}
}


int LeeControlRangoExpulsor (int min,int max,int expulsor)
{

	int dato,Band=0;

	do
	{

        if (Band==0)
			Band=1;
		else
		    printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",min,max);

		scanf("%d",&dato);


	}while ((dato<min || dato>max) && dato !=expulsor);


	return(dato);

}



/////////////////////////////////////////////////////////////////////////////////////

int LeeControlNroExpulsor (int target,int expulsor) //// target va a ser la cantidad de cifras que queremos que tenga el numero
{

	int max,min=1,i;

	for(i=1;i<target;i++)
	{
		min*=10;
	}


	max= min*10-1;

	return (LeeControlRangoExpulsor(min,max,expulsor));

}

/////////////////////////////////////////////////////////////////////////////////

