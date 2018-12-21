//Ejercicio 19-06-2018 - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Q 3

typedef struct{
			   int CM;
			   int ST;
			   float PR;
			   char D[51];
			   char OBS[21];
			  }MEDI;


int LeeControlRango (int,int);
float LeeControlMayor(int);
void Ingreso(MEDI[],int);
void Proceso(MEDI[],int);
void Mostrar(MEDI[],int);
int Busqueda(int,MEDI[],int);

//////////////////////////////////////////////////////////////////////////

main()
{
	int CMM,POS;
	MEDI VA[Q];

	Ingreso(VA,Q);
	Proceso(VA,Q);
	Mostrar(VA,Q);
	
 	printf("\t\n INGRESE EL CODIGO DE PRODUCTO CUYO PRECIO DESEA CONOCER:  ");
	scanf("%d",&CMM);

	while(CMM!=0)
	{

        POS=Busqueda(CMM,VA,Q);

		if(POS>=0)
		    printf("\n EL CODIGO %d TIENE DE PRECIO UNITARIO: %.2f",CMM,VA[POS].PR);
		else
		    printf("\n CODIGO INEXISTENTE");

		printf("\t\n\n INGRESE EL CODIGO DE PRODUCTO CUYO PRECIO DESEA CONOCER:  ");
		scanf("%d",&CMM);

	}

	
getch(); /*Pausa*/
}
///////////////////////////////////////////////////////////////////////////////
void Ingreso (MEDI V[],int n)
{
	int i;
	
	for (i=0;i<n;i++)
	{
		printf("\n INGRESE EL CODIGO DEL MEDICAMENTO: ");
		V[i].CM=LeeControlRango(100,999);
		printf("\n INGRESE LA DESCRIPCION DEL MEDICAMENTO: ");
		fflush(stdin);
		gets(V[i].D);
		printf("\n INGRESE EL PRECIO DEL MEDICAMENTO: ");
        V[i].PR=LeeControlMayor(0);
		printf("\n INGRESE LA CANTIDAD EN STOCK DEL MEDICAMENTO: ");
        V[i].ST=LeeControlRango(0,32767);
	}
}

///////////////////////////////////////////////////////////////////////////////
void Mostrar (MEDI V[],int n)
{
	int i;

	printf("\n CODIGO MEDICAMENTO \t DESCRIPCION \t PRECIO \t STOCK \t OBSERVACION");

	for (i=0;i<n;i++)
	{
		printf("\n	 %d \t	  %s \t %.1f   \t %d   \t %s",V[i].CM,V[i].D,V[i].PR,V[i].ST,V[i].OBS);
	}
}

///////////////////////////////////////////////////////////////////////////////
void Proceso (MEDI V[],int n)
{
	int i;

	for (i=0;i<n;i++)
	{
		if(V[i].ST>=10)
			strcpy(V[i].OBS,"SUFICIENTE");
		else
		{	if(V[i].ST==0)
		    	strcpy(V[i].OBS,"SIN STOCK");
		    else
                strcpy(V[i].OBS,"REPONER");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
int Busqueda (int QUE,MEDI V[],int n)
{
	int POSI=-1,CONT=0;

	while(POSI<0 && CONT<n)
	{
		if(QUE==V[CONT].CM)
		    POSI=CONT;
		else
		    CONT++;
	}
	
	return (POSI);
}

///////////////////////////////////////////////////////////////////////////////
int LeeControlRango (int LI,int LS)
{

	int dato,Band=0;

	do
	{

        if (Band==0)
			Band=1;
		else
		    printf("\t\n INTENTE NUEVAMENTE ");

		scanf("%d",&dato);


	}while (dato<LI || dato>LS);


	return(dato);

}

/////////////////////////////////////////////////////////////////////////////////////

float LeeControlMayor (int MIN)
{
	float dato;
	int Band=0;

	do
	{
        if (Band==0)
			Band=1;
		else
			printf("\t\n INTENTE NUEVAMENTE ");

	   	scanf("%f",&dato);

	}while (dato<=MIN);

	return (dato);
}

