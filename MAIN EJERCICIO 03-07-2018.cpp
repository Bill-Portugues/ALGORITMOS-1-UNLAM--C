//// TP A ENTREGAR 03-7-2018

//Autor: Lucas Serrenho
// Se considera que el listado de cantidad de pedidos por hora contempla tanto a productos con código existente como inexistente.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define QPROD 1000


typedef struct{
      		   char CP[11];
      		   float PU;
				int SA;
			   }PRODUCTOS;


typedef struct{
				int HP;
				char CPP[11];
      		   int QP;
      		   }PEDIDOS;


int LECTURA(PRODUCTOS[],int);
void IngresoBIS(PRODUCTOS[],int,float[]);
void GRABAR(PRODUCTOS[],int);
int Busqueda (char[],PRODUCTOS[],int);
void Listado(PRODUCTOS[],float[],int);
void ListadoOrdenado(PRODUCTOS[],float[],int);
void Orden(PRODUCTOS[],float[],int);
void MOSTRAR();
void Corte(void);

//////////////////////////////////////////////////////////////////////////

main()
{
	PRODUCTOS VP[QPROD];
 	int QREAL;
 	float REC[24]={0};
 	
 	QREAL=LECTURA(VP,QPROD);

	IngresoBIS(VP,QREAL,REC);

	Listado(VP,REC,QREAL);
	
	Corte();

	GRABAR(VP,QREAL);

	ListadoOrdenado(VP,REC,QREAL);

	printf("\n\n\n MOSTRAR CONTENIDO DEL ARCHIVO ACTUALIZADO DE 'LIBRERIAS.DAT'\n ");
	MOSTRAR();
	
	
getch(); /*Pausa*/
}


//////////////////////////////////////////////////////////////////////////////
void Corte()
{
    FILE *PF;
    PEDIDOS VB;
    PF=fopen("VENTAS.DAT","rb");
	int NDANT,ACUM=0;

	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}
		
		printf("\n\n\n TOTAL DE PEDIDOS POR HORA: \n");
		
		  fread(&VB,sizeof(PEDIDOS),1,PF);

	while(!feof(PF))
	{
		NDANT=VB.HP;
		ACUM=0;

		while(NDANT==VB.HP && !feof(PF))
		{
			ACUM++;
	        fread(&VB,sizeof(PEDIDOS),1,PF);

		}

		printf("\n HORA: %d - PEDIDOS %d",NDANT,ACUM);

  	}

	fclose(PF);

}


//////////////////////////////////////////////////////////////////////////////
void IngresoBIS (PRODUCTOS V[] ,int n ,float R[])
{

 	int pos;
	PEDIDOS VB;
	FILE *PF,*PF2;



	PF=fopen("VENTAS.DAT","rb");
	PF2=fopen("ERROR.DAT","wb");

	if (PF==NULL || PF2==NULL )
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	printf("\n CARGANDO ARCHIVOS - ALGUNAS OBSERVACIONES: \n");

    fread(&VB,sizeof(PEDIDOS),1,PF);

	while(!feof(PF))
	{

		pos=Busqueda(VB.CPP,V,n);


			if(pos>=0)
			{
				if(VB.QP > V[pos].SA )
			    		printf("\n EL PRODUCTO %s ESTA CON STOCK INSUFICIENTE PARA PROCESAR EL ULTIMO PEDIDO", V[pos].CP);


				else
					{
						V[pos].SA-=VB.QP;
						R[pos]+=(VB.QP*V[pos].PU);
					}
			}

			else
			{
				printf("\n CODIGO INEXISTENTE - PRODUCTO %s GRABADO EN 'ERROR.DAT'",VB.CPP);
				fwrite(&VB,sizeof(PEDIDOS),1,PF2);
			}



	       fread(&VB,sizeof(PEDIDOS),1,PF);

  	}

	fclose(PF);
	fclose(PF2);

}

///////////////////////////////////////////////////////////////////////////////
int Busqueda (char QUE[11],PRODUCTOS V[],int n)
{
	int POSI=-1,CONT=0;

	while(POSI<0 && CONT<n)
	{

		if(strcmpi(QUE,V[CONT].CP)==0)
		    POSI=CONT;
		else
		    CONT++;
	}

	return (POSI);
}
////////////////////////////////////////////////////////////////////////////////
void ListadoOrdenado(PRODUCTOS V[],float R[],int n)

{
	int i;

	Orden(V,R,n);
	
	printf("\n\n\n PRODUCTOS ORDENADO POR CANTIDAD DE STOCK \n");

	printf("\n\ CODIGO DE PRODUCTO          STOCK ACTUAL            RECAUDACION\n");



	for (i=0;i<n;i++)
	{
		printf("\n %11s 	  %15d	 	    %.1f",V[i].CP,V[i].SA,R[i]);
	}


}

///////////////////////////////////////////////////////////////////////////////
void Orden(PRODUCTOS V[],float R[],int n)

{
	int i;
	PRODUCTOS AUX;
	float AUXF;
	int KOTA=n;
	int K=1;
	
	while(K!=0)
	{
		K=0;
		for(i=1;i<KOTA;i++)
		{
			if(V[i-1].SA<V[i].SA)
			{
				AUX=V[i-1];
				AUXF=R[i-1];
				V[i-1]=V[i];
				R[i-1]=R[i];
				V[i]=AUX;
				R[i]=AUXF;
				
				K=i;

			}

		}

		KOTA=K;
	}


}
///////////////////////////////////////////////////////////////////////////////
void Listado(PRODUCTOS V[],float R[],int n)
{

	int i;

	printf("\n\n\n RECAUDACION TOTAL POR PRODUCTO POR DIA ");
    printf("\n\n CODIGO PRODUCTO 			RECAUDADO EN EL DIA \n");

	 
	for(i=0;i<n;i++)
	{
		printf("\n %s				%.2f				",V[i].CP,R[i]);
    }


}


///////////////////////////////////////////////////////////////////////////////
void MOSTRAR()
{
	PRODUCTOS V;
	int i;
	FILE *PF;

	PF=fopen("LIBRERIAS.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	fread(&V,sizeof(PRODUCTOS),1,PF);

   	while (!feof(PF))
	{
	

			printf("\n MOSTRAR COD.PRODUCTO %s , STOCK ACTUAL %d Y PRECIO UNITARIO %.1f", V.CP,V.SA,V.PU);

		fread(&V,sizeof(PRODUCTOS),1,PF);
	}

	fclose(PF);


}

///////////////////////////////////////////////////////////////////////////////
void GRABAR(PRODUCTOS V[],int n)
{

	int i=0;
	FILE *PF;

	PF=fopen("LIBRERIAS.DAT","wb");
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


}



///////////////////////////////////////////////////////////////////////////////
int LECTURA (PRODUCTOS V[],int n)
{
 	int i=0;
	PRODUCTOS AUX;
	FILE *PF;

	PF=fopen("LIBRERIAS.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}

	fread(&AUX,sizeof(PRODUCTOS),1,PF);
	while(!feof(PF) && i<n)
	{
		if(AUX.SA>0)
		{
			V[i]=AUX;
            i++;
		}
		
        fread(&AUX,sizeof(PRODUCTOS),1,PF);
	}

	fclose(PF);
	
	return(i);

}
