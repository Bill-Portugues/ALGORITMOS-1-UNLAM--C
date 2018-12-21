//// ARCHIVO DE GENERACION MASIVA Y GENERAL

//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
      		   int CP;
      		   char SEC;
      		   char FECHA[11];
				int SA;
			   }PRODUCTOS;


typedef struct{
				int CPP;
				int CPROV;
      		   int QC;
      		   char FECHA[11];
      		   }COMP;


void Ingreso();
void IngresoBIS();
void MOSTRAR();
void MOSTRARBIS();





//////////////////////////////////////////////////////////////////////////

main()
{
///	Ingreso();
/// IngresoBIS();


	printf("\n MOSTRAR CONTENIDO DEL ARCHIVO 'PRODUCTOS.DAT'\n ");
	MOSTRAR();

    printf("\n \n MOSTRAR CONTENIDO DEL ARCHIVO 'COMPRAS.DAT'\n ");
	MOSTRARBIS();

getch(); /*Pausa*/
}
///////////////////////////////////////////////////////////////////////////////
void MOSTRAR()
{
	PRODUCTOS V;
	FILE *PF;

	PF=fopen("PRODUCTOS.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	fread(&V,sizeof(PRODUCTOS),1,PF);
   	while (!feof(PF))
	{
		printf("\n  %d , STOCK ACTUAL %d Y FECHA %s Y %c", V.CP,V.SA,V.FECHA,V.SEC);

		fread(&V,sizeof(PRODUCTOS),1,PF);


	}

	fclose(PF);


}

///////////////////////////////////////////////////////////////////////////////
void MOSTRARBIS()
{
	COMP V;

	FILE *PF;
	int i=0;

	PF=fopen("COMPRAS.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	fread(&V,sizeof(COMP),1,PF);
	
  	while (!feof(PF))
	{
	
		printf("\n  %d  %d y  %d y fecha %s",V.CPP,V.QC,V.CPROV, V.FECHA);

    	fread(&V,sizeof(COMP),1,PF);

	}

	fclose(PF);


}


///////////////////////////////////////////////////////////////////////////////
void Ingreso ()
{
	int i,CPP;
	PRODUCTOS V;
	FILE *PF;
	
	PF=fopen("PRODUCTOS.DAT","wb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	printf("DEJA DE CARGAR CON VALOR 0 EN CODIGO DE PRODUCTO");

	printf("\n INGRESE EL CODIGO DE PRODUCTO: ");
	scanf("%d",&CPP);

	while (CPP!=0)
	{
        V.CP=CPP;

		printf("\n INGRESE EL STOCK ACTUAL: ");
       	scanf("%d",&V.SA);

		printf("\n INGRESE EL SECTOR F(FARMACIA) P ()PERFUMERIA): ");
		fflush(stdin);
		scanf("%c",&V.SEC);


		printf("\n INGRESE LA FECHA DD-MM-AAAA: ");
		fflush(stdin);
		gets(V.FECHA);
		
		fwrite(&V,sizeof(PRODUCTOS),1,PF);

		printf("\n INGRESE EL CODIGO DE PRODUCTO: ");
		scanf("%d",&CPP);
	
	}

	fclose(PF);

}

//////////////////////////////////////////////////////////////////////////////
void IngresoBIS ()
{
	int i,HPP;
	COMP V;
	FILE *PF;

	PF=fopen("COMPRAS.DAT","wb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	printf("DEJA DE CARGAR CON VALOR 0 EN HORA DE PEDIDO");

	printf("\n INGRESE EL CODIGO DE PRODUCTO: ");
	scanf("%d",&HPP);

	while (HPP!=0)
	{
        V.CPP=HPP;

		printf("\n INGRESE LA CANTIDAD COMPRADA: ");
		scanf("%d",&V.QC);

		printf("\n INGRESE EL CODIGO DE PROVEEDOR: ");
		scanf("%d",&V.CPROV);
		
		printf("\n INGRESE LA FECHA DD-MM-AAAA: ");
		fflush(stdin);
		gets(V.FECHA);

	
		fwrite(&V,sizeof(COMP),1,PF);

        printf("\n INGRESE EL CODIGO DE PRODUCTO: ");
		scanf("%d",&HPP);

	}
	
		fclose(PF);
}
