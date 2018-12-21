//Ejercicio 2 Vectores - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#define Q 4

int MAXIMO(int[],int);
void PRINTMAX(int[],int[],int,int);
void CARGASEC(int[],int[],int[],int[],int);
void RESULTADOS(int[],int[],char [],int,int,int);
int LeeControlRangoExpulsor (int,int,int =-9999);
int LeeControlNroExpulsor (int,int=-9999);
int ControlMayor(int);
void NOTAOK(int[],bool[],int);
void LISTARASISTENCIA(bool[],int[],int);

main()
{
	int VDNI[Q],VP1[Q],VP2[Q],VASIST[Q];
	bool VNASISTOK[Q];
	char VRES[Q];
	int MAX;

	CARGASEC(VDNI,VP1,VP2,VASIST,Q);
	RESULTADOS(VP1,VP2,VRES,4,7,Q);
	NOTAOK(VASIST,VNASISTOK,Q);
	LISTARASISTENCIA(VNASISTOK,VDNI,Q);

getch(); /*Pausa*/

}


///////////////////////

void LISTARASISTENCIA(bool VASOK[],int DNI[],int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
        	if(VASOK[i]==false)
            	printf("\t\n DNI: %d",DNI[i]);

	}
}


////////////////////////////////



///////////////////////

void NOTAOK(int VAS[],bool VASOK[],int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
        	if(VAS[i]>=75)
            	VASOK[i]=true;
            	
	}
}


////////////////////////////////



void RESULTADOS(int NOTA1[],int NOTA2[],char RESULTADOS[],int Aprobo,int Promociono, int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
        	if(NOTA1[i]>=Promociono && NOTA2[i]>=Promociono)
            	RESULTADOS[i]='P';
			else
			{
				if(NOTA1[i]>=Aprobo && NOTA2[i]>=Aprobo)
			        RESULTADOS[i]='A';
       			else
				    RESULTADOS[i]='R';
			}
	}
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

void CARGASEC(int VAL1[],int VAL2[], int VAL3[],int VAL4[],int QV)
{
	int i;

	for (i=0;i<QV;i++)
	{
		printf("\t\n Ingrese DNI %d: ",i+1);
		VAL1[i]=LeeControlNroExpulsor(8);

		printf("\t\n Ingrese Nota Parcial 1 : ");
		VAL2[i]=LeeControlRangoExpulsor(0,10);

		printf("\t\n Ingrese Nota Parcial 2 : ");
		VAL3[i]=LeeControlRangoExpulsor(0,10);
		
		printf("\t\n Ingrese %% de Asistencia: ");
		VAL4[i]=LeeControlRangoExpulsor(0,100);

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

int ControlMayor (int mayor)
{
	int dato,Band=0;

	do
	{
        if (Band==0)
			Band=1;
		else
			printf("\t\n El numero ingresado debe ser superior a %d \t\n Vuelva a Intentarlo: ",mayor);

	   	scanf("%d",&dato);

	}while (dato<=mayor);

	return (dato);
}
