//// MODELO DE PARCIAL TEMA 1

#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


# define QPROD 100
# define QMIN 100

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




char LeeControl(char,char);
int Lectura(PRODUCTOS[],int,char);
int CORTE(PRODUCTOS[],int,int[]);
int Busqueda(int,PRODUCTOS[],int);
void Grabar(PRODUCTOS [],int );
void Ordenar(PRODUCTOS[],int);


main()
{

char SECTOR;
int COMPRHOY[QPROD]={0},QREAL,COMPRASTOT,i;
PRODUCTOS VART[QPROD];

printf("\n INGRESE EL SECTOR QUE DESEA ANALIZAR: ");
SECTOR=LeeControl('P','F');

QREAL=Lectura(VART,QPROD,SECTOR);

COMPRASTOT = CORTE(VART,QREAL,COMPRHOY);

printf("\n LAS COMPRAS TOTALES FUERON DE %d",COMPRASTOT);


printf("\n LISTADO DE PRODUCTOS QUE NO TUVIERON COMPRAS: ");
for (i=0;i<QREAL;i++)

	{
		if(COMPRHOY[i]==0)
		    printf("\n EL CODIGO %d NO TUVO COMPRAS",VART[i].CP);
	}
	
Ordenar(VART,QREAL);
printf("\n COD PROD 	FECHA  			STOCK ACTUAL\n");
for (i=0;i<QREAL;i++)
{
	printf("\n %d		%s			%d",VART[i].CP,VART[i].FECHA,VART[i].SA);
}

Grabar(VART,QREAL);
/* */

getch();

}


void Grabar(PRODUCTOS V[],int n)
{
	FILE *PF;
	int i;

	PF=fopen("ARTI_ACT.DAT","wb");
	if (PF==NULL)
	{
		printf("NO ESTA EL ARCHIVIO");
		getch();
		exit(1);
	}

	for(i=0;i<n;i++)
	{
		fwrite(&V[i],sizeof(PRODUCTOS),1,PF);
	}
	
	fclose(PF);
	
	}





void Ordenar(PRODUCTOS V[], int n)

{
int KOTA=n;
int K=1,i;
PRODUCTOS aux;

while(K!=0)

{
K=0;
for(i=1;i<KOTA;i++)
	{
		if(V[i-1].SA<V[i].SA)
		{
			aux=V[i-1];
			V[i-1]=V[i];
			V[i]=aux;
			
			K=i;
		}
	}
	KOTA=K;
}




}


int CORTE(PRODUCTOS V[],int n,int COMPRHOY[])
{
	FILE *PF,*PF2;
	COMP aux;
	int NDANT,pos,QCOMPRADAS,QTOTAL=0;
	
	PF=fopen("COMPRAS.DAT","rb");
    PF2=fopen("NOESTA.DAT","wb");

	if(PF==NULL || PF2==NULL)
	{
		printf("NO ESTA EL ARCHIVO");
		getch();
		exit(1);
	}
	
	fread(&aux,sizeof(COMP),1,PF);
	
	while(!feof(PF))
	{
		NDANT=aux.CPROV;
		QCOMPRADAS=0;
		
		while(NDANT==aux.CPROV && !feof(PF))
		{
            QCOMPRADAS +=aux.QC;
			pos=Busqueda(aux.CPP,V,n);
			
			if(pos>=0)
				{
					V[pos].SA+=aux.QC;
					strcpy(V[pos].FECHA,aux.FECHA);
					COMPRHOY[pos]+=aux.QC;
					
				}

			else
			    fwrite(&aux,sizeof(COMP),1,PF2);

        fread(&aux,sizeof(COMP),1,PF);
		}
		
		printf("\n EL PROVEEDOR %d NOS VENDIO %d ",NDANT,QCOMPRADAS);
		QTOTAL+=QCOMPRADAS;
	}


fclose(PF);
fclose(PF2);

return(QTOTAL);

}

int Busqueda(int que,PRODUCTOS DONDE[],int n)
{
	int posi=-1;
	int cont=0;
	
	while(posi<0 && cont<n)
	{
		if(DONDE[cont].CP==que)
		    posi=cont;
		else
		    cont++;
	}
	
	return (posi);
}


int Lectura(PRODUCTOS V[],int n,char LETRA)
{
	FILE *PF;
	int i=0;
	PRODUCTOS aux;
	
	PF=fopen("PRODUCTOS.DAT","rb");
	if (PF==NULL)
	{
		printf("NO EXISTE ARCHIVO");
		getch();
		exit(1);
	}
	
	fread(&aux,sizeof(PRODUCTOS),1,PF);
	
	while(!feof(PF) && i<n)
	{
		if(LETRA==aux.SEC)
		{    if(aux.SA < QMIN)
				{
					V[i]=aux;
					i++;
				}
		}
		
		
		fread(&aux,sizeof(PRODUCTOS),1,PF);
	}
	
	fclose(PF);
	return (i);
	
}

char LeeControl(char L1,char L2)
{

	int BAND=0;
	char aux;
	
	do{
		if (BAND==0)
			BAND=1;
		else
		    printf("\n VUELVA A INTENTARLO \n ");
		    
		fflush(stdin);
		scanf("%c",&aux);
		aux=toupper(aux);

	}while(aux!=L1 && aux!=L2);

	return aux;


}


