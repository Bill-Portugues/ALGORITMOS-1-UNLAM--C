//Ejercicio 2 estructuras
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Q 80

typedef struct{
			   int DNI;
			   int N1;
			   int N2;
			   char NYA[81];
			   float NP;
			  }MEDI;


int LeeControlRango (int,int);
int LeeControlMayor(int);
int Ingreso(MEDI[],int);
void Resultado(MEDI[],int);
void InformePromo(MEDI[],int);


//////////////////////////////////////////////////////////////////////////

main()
{
	int Qreal;
	MEDI VA[Q];

	Qreal= Ingreso(VA,Q);
	
 	Resultado(VA,Qreal);
 	
 	InformePromo(VA,Qreal);



getch(); /*Pausa*/
}
///////////////////////////////////////////////////////////////////////////////
int Ingreso (MEDI V[],int n)
{
	int i=0,DNI;
	
	printf("\t\n INGRESE EL DNI DEL ALUMNO A CARGAR:  ");
	scanf("%d",&DNI);

	while (DNI!=0 && i<n)
	{
		V[i].DNI=DNI;

		printf("\n INGRESE NOMBRE Y APELLIDO: ");
		fflush(stdin);
		gets(V[i].NYA);

		printf("\n INGRESE LA NOTA DEL PRIMER PARCIAL: ");
        V[i].N1=LeeControlMayor(0);

		printf("\n INGRESE LA NOTA DEL SEGUNDO PARCIAL: ");
        V[i].N2=LeeControlMayor(0);
	
	    V[i].NP=(float) (V[i].N2+V[i].N1)/2;

	    printf("\t\n INGRESE EL DNI DEL ALUMNO A CARGAR:  ");
		scanf("%d",&DNI);
		
		i++;

	}
	
	return (i);
}

///////////////////////////////////////////////////////////////////////////////
void Resultado (MEDI V[],int n)
{
	int i,Apro=0,Des=0;

	
	for (i=0;i<n;i++)
	{
		if(V[i].N1>=4 && V[i].N2>=4)
		    Apro++;
		else
		    Des++;
	}
	
	printf("\n APROBARON: %d           DESAPROBARON: %d",Apro,Des);
}



///////////////////////////////////////////////////////////////////////////////
void InformePromo (MEDI V[],int n)
{
	int i;

		printf("\n ALUMNOS QUE PROMOCIONARON: ");

		for (i=0;i<n;i++)
	{
		if(V[i].N1>=7 && V[i].N2>=7)
		    printf("\n %d  %s  %1.f",V[i].DNI,V[i].NYA,V[i].NP);
	}
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

int LeeControlMayor (int MIN)
{
	int dato;
	int Band=0;

	do
	{
        if (Band==0)
			Band=1;
		else
			printf("\t\n INTENTE NUEVAMENTE ");

	   	scanf("%d",&dato);

	}while (dato<=MIN);

	return (dato);
}


