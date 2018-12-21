// Modelo de Parcial #1

#include <stdio.h>
#include <conio.h>
#define Clientes 5
#define Piezas 3


void Cargar_Piezas(int[],float[],int);
int LeeControlDato(int,int);
int Busqueda(int[],int, int);
void ListadoPiezaTaller(float[Piezas][Clientes],int[],int,int);
void ListadoCantPiezas(int[],int);
int Minimo(int[],int);
void InformeMinimo(int[],int,int);

main()
{
	int Cod[Piezas],NF,NTal,CPS,QP,Pos,SumXT[Clientes]={0},Min;
	float PreP[Piezas],CodyPie[Piezas][Clientes]={{0}};

	Cargar_Piezas(Cod,PreP,Piezas);

	printf("\n Ingrese el Numero de Factura: ");
	scanf(" %d", &NF);

	while(NF!=0)
	{

        printf("\n Ingrese el Codigo de Pieza: ");
		CPS=LeeControlDato(999,10000);

		Pos=Busqueda(Cod,CPS,Piezas);

		if (Pos>=0)
		{
			printf("\n Ingrese el Numero de Taller: ");
			NTal=LeeControlDato(1,Clientes);

			printf("\n Ingrese Cantidad de Piezas: ");
			scanf(" %d", &QP);

			CodyPie[Pos][NTal-1]+=(QP*PreP[Pos]);
			SumXT[NTal-1]+=QP;
		}
		else
			printf("\n CODIGO INEXISTENTE");

  	printf("\n Ingrese el Numero de Factura: ");
	scanf(" %d", &NF);
	}
	
	Min=Minimo(SumXT,Clientes);
	

	ListadoPiezaTaller(CodyPie,Cod,Piezas,Clientes);
	ListadoCantPiezas(SumXT,Clientes);

	printf("\n\n Los Talleres que tienen el Minimo de piezas son: ");
	InformeMinimo(SumXT,Min,Clientes);

    printf("\n\n Los Talleres que No Realizaron compras son: ");
	InformeMinimo(SumXT,0,Clientes);


getch(); /*Pausa*/

}

///////////////////////////////////////
void InformeMinimo(int donde[],int que,int cuantos)
{
	int i;

 	for(i=0;i<cuantos;i++)
	{
		if(que==donde[i])
			printf("\n Taller %d",i+1);
	}
}


///////////////////////////////////////

int Minimo (int donde[],int cuantos)
{
	int i,min=donde[0];
	
	for(i=1;i<cuantos;i++)
	{
		if (min>donde[i] && donde[i]!=0)
		    min=donde[i];
	}
	
	return (min);

}

///////////////////////////////////////

void ListadoCantPiezas(int donde[],int cuantos)
{
	int i;

	printf("\n CANTIDAD DE PIEZAS SOLICITADAS POR TALLER \n NRO TALLER              CANTIDAD DE PIEZAS");

	for(i=0;i<cuantos;i++)
	{
		printf("\n Taller %d				%d",i+1,donde[i]);

	}
}
//////////////////////////////////////

void ListadoPiezaTaller(float M[Piezas][Clientes],int filas[],int Qi,int Qj)
{
	int x,i,j;

	printf("\n CODIGO PIEZA/TALLER \n\n");
	
	for(x=0;x<Qj;x++)
	{
		printf(" \t %d",x+1);
	}

	for(i=0;i<Qi;i++)
	{
		printf("	\n %d ", filas[i]);
		
		for(j=0;j<Qj;j++)
		{
			printf(" %8.1f \t ",M[i][j]);
		}
	}

}

//////////////////////////////////////

int Busqueda(int Donde[],int Que, int Cuantos)
{
	int posi=-1,Cont=0;
	
	while(posi<0 && Cont<Cuantos)
	{
		if (Donde[Cont]== Que)
		    posi=Cont;

		else
		    Cont++;

	}

	return (posi);

}



//////////////////////////////////////

void Cargar_Piezas(int VC[],float VP[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{

		printf("\n Ingrese el Codigo de Producto #%d: ",i+1);
		VC[i]=LeeControlDato(999,10000);
		
		printf("\n Ingrese el Precio del Producto #%d: ",i+1);
		scanf(" %f", &VP[i]);

	}

}

////////////////////////////////////
int LeeControlDato(int min,int max)
{
		int dato,Band=0;

	do
	{

        if (Band==0)
			Band=1;
		else
		    printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",min,max);

		scanf("%d",&dato);


	}while (dato<min || dato>max);


	return(dato);

	
}
