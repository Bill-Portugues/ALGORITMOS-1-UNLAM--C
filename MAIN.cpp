///// MOD ## 1

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define QJAB 12
#define QDIAS 8

typedef struct {
	int CJ;
	int NTJ;
	char PRES[10];
	int Q;
	}JAB;

typedef struct {
	int DP;
	int CJJ;
	int QP;
	}PROD;
	
int INGRESO(JAB[],int);
void LEVANTO(int[QJAB][QDIAS],JAB[],int);
void GRABARNUEVOS (PROD);
int BUSQUEDA(int,JAB[],int);
void GRABARACT(JAB[],int);
void REPORTAR0(int[QJAB][QDIAS],JAB[],int,int);
void REPORTAR1(int[QJAB][QDIAS],JAB[],int,int);
void REPORTAR2(JAB[],int);

	
main()
{

int QREAL,M[QJAB][QDIAS]={{0}};

JAB VA[QJAB];

QREAL=INGRESO(VA,QJAB);

LEVANTO(M,VA,QREAL);

REPORTAR0(M,VA,QREAL,QDIAS);

REPORTAR1(M,VA,QREAL,QDIAS);

REPORTAR2(VA,QREAL);

GRABARACT(VA,QREAL);

}
//////////////////////////////////////////////////////////////////////////


void REPORTAR0(int MM[QJAB][QDIAS],JAB V[],int i,int j)
{


int x,y,SUMA;

printf("\n PRODUCCION DE JABONES DIA x DIA:\n");
printf("\n CODIGO JABON ");

for(x=1;x<=j;x++)
{	printf("\t  %d",x);  }


for(x=0;x<i;x++)
{

	printf("\n  %d	",V[x].CJ);

	for (y=0;y<j;y++)

	{	printf("\t  %d",MM[x][y]);	}


}

}

/////////////////////////////////////////////////////////////////////////

void REPORTAR1(int MM[QJAB][QDIAS],JAB V[],int i,int j)
{

int x,y,SUMA;

printf("\n LOS JABONES QUE NO TUVIERON PRODUCCION SON:\n");
for(x=0;x<i;x++)
{
	SUMA=0;
	
	for (y=0;y<j;y++)

	{	SUMA+=MM[i][j];	}
	
	if (SUMA==0)
	    printf(" - %d - ",V[i].CJ);


}

}


//////////////////////////////////////////////////////////////////////

void REPORTAR2(JAB V[],int n)
{

int i;

for(i=0;i<n;i++)
{
	printf("\n PRESENTACION %s",V[i].PRES);
	printf("\n CODIGO JABON			NRO TANQUE			CANTIDAD		\n");
	printf("   %d					%d					%d				\n",V[i].CJ,V[i].NTJ,V[i].Q);
}

}

//////////////////////////////////////////////////////////////////////

void LEVANTO(int MM[QJAB][QDIAS],JAB V[],int n)
{

PROD aux;

FILE *PF;
int POS;

PF=fopen("PRODUCCION.DAT","rb");
if(PF==NULL)
	{printf("\n NO SE ENCONTRO ARCHIVO");
		getch();
		exit(1);
		}
		
fread(&aux,sizeof(PROD),1,PF);
while(!feof(PF))
{
POS=BUSQUEDA(aux.CJJ,V,n);

if(POS>0)

	{
		MM[POS][aux.DP-1]+=aux.QP;
		V[POS].Q+=aux.QP;
	}
	
else
		GRABARNUEVOS(aux);



fread(&aux,sizeof(PROD),1,PF);
}

	fclose(PF);
	
	


}

//////////////////////////////////////////////////////////////////////////

void GRABARACT(JAB V[],int n)
{

FILE *PF;

PF=fopen("JABACT.DAT","rb");
if(PF==NULL)
	{printf("\n NO SE ENCONTRO ARCHIVO");
		getch();
		exit(1);
		}

	fwrite(&V,sizeof(PROD),1,PF);




fclose(PF);

	}

///////////////////////////////////////////////////////////////////////
void GRABARNUEVOS(PROD V)
{

FILE *PF;

PF=fopen("VER_JABON.DAT","rb");
if(PF==NULL)
	{printf("\n NO SE ENCONTRO ARCHIVO");
		getch();
		exit(1);
		}
		
	fwrite(&V,sizeof(PROD),1,PF);

fclose(PF);

	}

///////////////////////////////////////////////////////////////////////
int BUSQUEDA(int QUE,JAB V[],int n)
{

int posi=-1;
int CONT=0;

while(posi<0 && CONT<n)

{	if(V[CONT].CJ==QUE)
		posi=CONT;
	else
		CONT++;
}

return (posi);

}


/////////////////////////////////////////////////////////////////////
int INGRESO(JAB V[],int n)
{

int i=0;
FILE *PF;

PF=fopen("JAMONES.DAT","rb");
if(PF==NULL)
	{printf("\n NO SE ENCONTRO ARCHIVO");
		getch();
		exit(1);
		}
		
 fread(&V[i],sizeof(JAB),1,PF);

 while(!feof(PF) && i<n)
 {
      	i++;
		fread(&V[i],sizeof(JAB),1,PF);
}


	fclose(PF);
	
return (i);
}

