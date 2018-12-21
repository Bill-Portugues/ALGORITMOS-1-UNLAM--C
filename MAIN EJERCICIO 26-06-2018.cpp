//// TP A ENTREGAR 26-6-2018

//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define QPROD 1000


typedef struct{
      		   int CP;
      		   char DESC[41];
				int ST;
			   }PRODUCTOS;


typedef struct{
      		   int CPP;
      		   int QP;
      		   }PEDIDOS;



int Ingreso(PRODUCTOS[],int);
void IngresoBIS(PRODUCTOS[],int);
void GRABAR(PRODUCTOS[],int);
int Busqueda (int,PRODUCTOS[],int);
void Listado(PRODUCTOS[],int);
void MOSTRAR();

//////////////////////////////////////////////////////////////////////////

main()
{
	PRODUCTOS VP[QPROD];
	int QREAL;
	
	
	QREAL=Ingreso(VP,QPROD);
	IngresoBIS(VP,QREAL);
	Listado(VP,QREAL);
	GRABAR(VP,QREAL);

	printf("\n\n MOSTRAR CONTENIDO DEL ARCHIVO 'ACTUAL.DAT'");
	MOSTRAR();
	
	
getch(); /*Pausa*/
}


///////////////////////////////////////////////////////////////////////////////
void Listado(PRODUCTOS V[],int n)
{

	int i;

    printf("\n\n CODIGO PRODUCTO 			DESCRIPCION			CANTIDAD EN STOCK ACTUALIZADA \n");
    
	for(i=0;i<n;i++)
	{
		printf("\n %d				%20s				%5d",V[i].CP,V[i].DESC,V[i].ST);
	}


}


///////////////////////////////////////////////////////////////////////////////
void MOSTRAR()
{
	PRODUCTOS V;
	int i;
	FILE *PF;

	PF=fopen("ACTUAL.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	fread(&V,sizeof(PRODUCTOS),1,PF);

   	while (!feof(PF))
	{
	

		printf("\n\n MOSTRAR CODIGO DE PRODUCTO %d , \n MOSTRAR DESCRIPCION %s \n MOSTRAR STOCK %d ", V.CP,V.DESC,V.ST);

		fread(&V,sizeof(PRODUCTOS),1,PF);
	}

	fclose(PF);


}

///////////////////////////////////////////////////////////////////////////////
void GRABAR(PRODUCTOS V[],int n)
{

	int i=0;
	FILE *PF;

	PF=fopen("ACTUAL.DAT","wb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	while(i<n)
	{
	
		fwrite(&V[i],sizeof(PRODUCTOS),1,PF);
        i++;
	}

	fclose(PF);

getch(); /*Pausa*/
}



///////////////////////////////////////////////////////////////////////////////
int Ingreso (PRODUCTOS V[],int n)
{
 	int i=0;
	FILE *PF;

	PF=fopen("PRODUCTOS.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	fread(&V[i],sizeof(PRODUCTOS),1,PF);
	while(!feof(PF) && i<n)
	{
		i++;
        fread(&V[i],sizeof(PRODUCTOS),1,PF);
	}

	fclose(PF);
	
	return(i);

}

//////////////////////////////////////////////////////////////////////////////
void IngresoBIS (PRODUCTOS V[] ,int n)
{
	int i, pos;
	PEDIDOS VB;
	FILE *PF;

	PF=fopen("PEDIDOS.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}


    fread(&VB,sizeof(PEDIDOS),1,PF);
    
	while(!feof(PF))
	{	
		pos=Busqueda(VB.CPP,V,n);

		if(pos>=0)
		{
			if(VB.QP > V[pos].ST )
			    printf("\n EL PRODUCTO %s ESTA CON STOCK INSUFICIENTE PARA PROCESAR EL ULTIMO PEDIDO", V[pos].DESC);
			else
			    V[pos].ST-=VB.QP;
		}
		else
		    printf("\n EL CODIGO %d ES UN PRODUCTO INEXISTENTE",VB.CPP);

       fread(&VB,sizeof(PEDIDOS),1,PF);

	}

	fclose(PF);

}

///////////////////////////////////////////////////////////////////////////////
int Busqueda (int QUE,PRODUCTOS V[],int n)
{
	int POSI=-1,CONT=0;
	
	while(POSI<0 && CONT<n)
	{

		if(QUE == V[CONT].CP)
		    POSI=CONT;
		else
		    CONT++;
	}

	return (POSI);
}
