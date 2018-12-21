//Ejercicios Combinados 20-06-2018 - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define CAM 3
#define CON 3

typedef struct{
      		   float VxK;
      		   float QKM;
			   float TT;
			   char PATENTE[8];
			   }CAMION;
			   

int LeeControlRangoExpulsor(int,int,int);
float LeeControlMayor(int);
void Ingreso(CAMION[],int);
float Max(CAMION[],int);
void Mostrar(CAMION[],int);
int Busqueda(char[],CAMION[],int);
void InfMaximo(CAMION[],float,int);
void Switch(char[CON][31],float[],int, int);
void Orden(char[CON][31],float [],int);

//////////////////////////////////////////////////////////////////////////

main()
{
	int NC,POS,z;
	float KMR,TON,RECAUDADO[CON]={0},Maximo;
	char NP[8],NCON[CON][31];
	CAMION VA[CAM];

	Ingreso(VA,CAM);
	
 	printf("\t\n INGRESE EL NUMERO DE CONDUCTOR:  ");
	NC=LeeControlRangoExpulsor(1,CON,100);
	
	while(NC!=100)
	{

		
        printf("\t\n INGRESE EL NUMERO DE PATENTE DEL CAMION:  ");
		fflush(stdin);
		gets(NP);

		POS=Busqueda(NP,VA,CAM);


		if(POS>=0)
		{
            printf("\t\n INGRESE EL NOMBRE DEL CONDUCTOR:  ");
        	fflush(stdin);
			gets(NCON[NC-1]);

			printf("\t\n INGRESE LA CANTIDAD DE KM RECORRIDOS:  ");
			scanf("%f",&KMR);
			VA[POS].QKM += KMR;
			
			printf("\t\n INGRESE LA CANTIDAD DE TONELADAS TRANSPORTADAS:  ");
			scanf("%f",&TON);
			VA[POS].TT += TON;
			
			RECAUDADO[NC-1]+=(KMR*VA[POS].VxK);
		}
		else
		    printf("\n CODIGO PATENTE INEXISTENTE");

		printf("\t\n INGRESE EL NUMERO DE CONDUCTOR:  ");
		NC=LeeControlRangoExpulsor(1,50,100);

	}
	
	Mostrar(VA,CAM);
	Maximo=Max(VA,CAM);
	InfMaximo(VA,Maximo,CAM);
	Orden(NCON,RECAUDADO,CON);

	printf("\t\n NOMBRE DEL CONDUCTOR 		IMPORTE  ");
	for(z=0;z<CON;z++)
		{printf("\n %s					%.1f",NCON[z],RECAUDADO[z]);}



getch(); /*Pausa*/
}

///////////////////////////////////////////////////////////////////////////////
void Orden(char Nombres[CON][31],float V[],int n)
{

	int i,j;

	for (i=1;i<n;i++)
	{
	    j=i;

		while(j>0)
		{
			if (V[j]<V[j-1])
				Switch(Nombres,V,j-1,j);

			j--;
		}

	}




}

///////////////////////////////////////////////////////////////////////////////
void Switch(char Nombres[CON][31],float V[],int posA, int posB)

{
	float puente;
	char puenteS[31];
	
	strcpy(puenteS,Nombres[posA]);
	strcpy(Nombres[posA],Nombres[posB]);
	strcpy(Nombres[posB],puenteS);
	
	puente = V[posA];
    V[posA] = V[posB];
    V[posB] = puente;

}


///////////////////////////////////////////////////////////////////////////////
void InfMaximo(CAMION V[],float Maxi,int n)
{
    int i;
	
	printf("\n LAS SIGUIENTES PATENTES CORRESPONDEN A LOS CAMIONES QUE TUVIERON EL MAXIMO DE KM RECORRDIOS QUE FUERON: %.1f",Maxi);
	
	for (i=0;i<n;i++)
	{
		if(V[i].QKM==Maxi)
		    printf(" \n %s",V[i].PATENTE);
			
	}

}

///////////////////////////////////////////////////////////////////////////////
void Ingreso (CAMION V[],int n)
{
	int i;

	for (i=0;i<n;i++)
	{
		printf("\n INGRESE EL NUMERO DE PATENTE: ");
		fflush(stdin);
		gets(V[i].PATENTE);

		printf("\n INGRESE EL VALOR POR KILOMETRO DEL CAMION: ");
        V[i].VxK=LeeControlMayor(0);
        
        V[i].QKM=0;
        V[i].TT=0;
	}
}

///////////////////////////////////////////////////////////////////////////////
void Mostrar (CAMION V[],int n)
{
	int i;

	printf("\n PATENTE DEL TRANSPORTE \t TONELAJE TRANSPORTADO ");

	for (i=0;i<n;i++)
	{
		printf("\n	 %s \t	  %.1f",V[i].PATENTE,V[i].TT);
	}
}

///////////////////////////////////////////////////////////////////////////////
float Max (CAMION V[],int n)
{
	int i;
	float Maxi=V[0].QKM;

	for (i=1;i<n;i++)
	{
		if(V[i].QKM>Maxi)
			Maxi=V[i].QKM;
	}
	
	return (Maxi);
}


///////////////////////////////////////////////////////////////////////////////
int Busqueda (char QUE[8],CAMION V[],int n)
{
	int POSI=-1,CONT=0;

	while(POSI<0 && CONT<n)
	{
		if(strcmpi(QUE,V[CONT].PATENTE)==0)
		    POSI=CONT;
		else
		    CONT++;
	}

	return (POSI);
}

///////////////////////////////////////////////////////////////////////////////
int LeeControlRangoExpulsor (int LI,int LS,int Expulsor)
{

	int dato,Band=0;

	do
	{

        if (Band==0)
			Band=1;
		else
		    printf("\t\n INTENTE NUEVAMENTE ");

		scanf("%d",&dato);


	}while ((dato<LI || dato>LS)&&dato!=100);


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

