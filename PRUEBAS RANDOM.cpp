#include <stdio.h>
#include <conio.h>
#define q 7
#define altq 3

int min(int[],int);
void infomin(int[],int,int);
int Busqueda(int[],int,int);
int ControlDato(int,int);
void Carga(int[altq][altq],int);
void Reportear(int[altq][altq],int);

main()
{

int CARLOS[q]={5,14,8,9,48,70,5},ACARGAR[altq][altq],MINIMO,Pos;

MINIMO=min(CARLOS,q);
infomin(CARLOS,MINIMO,q);
Pos=Busqueda(CARLOS,48,q);

if(Pos>=0)
	printf("\n La Pos es %d",Pos);
else
	printf("\n Codigo Inexistente");

Carga(ACARGAR,altq);
Reportear(ACARGAR,altq);

getch(); /*Pausa*/
}
/////////////////////////////////////////
void Reportear (int V[altq][altq],int qq)

{

int i,j;

printf("\n COL1    COL2    COL3 \n");

for(i=0;i<qq;i++)
{
	for(j=0;j<qq;j++)
	{
		printf(" %d	   ",V[i][j]);

	}

	printf("\n");


}


}

////////////////////////////////////////

int ControlDato(int LI,int LS)

{

int Band=0,dato;

do{

if(Band==0)
	{Band=1;
	}
else
    printf("Intente Nuevamente");

scanf("%d",&dato);


}while(dato>LS || dato<LI);

return (dato);

}


////////////////////////////////////////
void Carga(int M[altq][altq],int qq)

{
int x;

for (x=0;x<qq;x++)
{
	printf("\n Ingrese fila %d columna %d ",x+1,1);
	M[x][0]=ControlDato(1,50);
    printf("\n Ingrese fila %d columna %d ",x+1,2);
	M[x][1]=ControlDato(100,999);
	printf("\n Ingrese fila %d columna %d ",x+1,3);
    M[x][2]=ControlDato(1000,1001);

}

}
/////////////////////////////////////////
int min(int BusqMin[],int x)
{

	int i,min=BusqMin[0];
	
	for(i=1;i<x;i++)
	{
		if(BusqMin[i]<min)
		    min=BusqMin[i];
	}

	return (min);

	}

/////////////////////////////////////////

void infomin(int Busq[],int min,int x)
{

int i;

for (i=0;i<x;i++)
{

	if(min==Busq[i])
	    printf("\n NUMERO que cumple con el minimo %d esta en la posicion %d",min,i+1);

}

}

///////////////////////////////////////
int Busqueda(int Donde[],int que,int cuantos)

{
	int cont=0,posi=-1;
	
	while(posi<0 && cont<cuantos)
	
	{
		if(Donde[cont]==que)
			posi=cont;
		else
			cont++;
	}

return (posi);

}


//////////////////////////////////////
