/// MOD ##1 sin REFRITAR NADA

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


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


void GENERAR1(void);
void GENERAR2(void);
void MOSTRAR1(void);
void MOSTRAR2(void);


main()
{
	GENERAR1();

	GENERAR2();

	MOSTRAR1();

	MOSTRAR2();
	
	getch();


}

void GENERAR1()

{
	int aux;
	JAB V;
	FILE *PF;

	PF=fopen("JAMONES.DAT","wb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}


	printf("\n INGRESE EL CODIGO DE JABON: ");
	scanf("%d", &V.CJ);
	
	while(V.CJ!=0)
	{

	printf("\n INGRESE EL NRO DE TANQUE: ");
	scanf("%d", &V.NTJ);


	printf("\n INGRESE LA PRESENTACION (1 - LIQUIDO , 2 - EN POLVO: ");
	scanf("%d", &aux);

	if(aux==2)
		strcpy(V.PRES,"EN POLVO");
	else
	    {if(aux==1)
			strcpy(V.PRES,"LIQUIDO");
		}

	printf("\n INGRESE LA CANTIDAD: ");
	scanf("%d", &V.Q);


	fwrite(&V,sizeof(JAB),1,PF);

	printf("\n INGRESE EL CODIGO DE JABON: ");
	scanf("%d", &V.CJ);
		}

	fclose(PF);

	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void MOSTRAR2()

{
	int i=0;
	PROD V;
	FILE *PF;

	PF=fopen("PRODUCCION.DAT","rb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}
	

	fread(&V,sizeof(PROD),1,PF);

	while(!feof(PF))
	{
		printf("\n %d             %d                  %d",V.CJJ,V.DP,V.QP);
        fread(&V,sizeof(PROD),1,PF);

	}
	fclose(PF);

	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
void MOSTRAR1()

{
	int i=0;
	JAB V;
	FILE *PF;
	
	PF=fopen("JAMONES.DAT","rb");
		if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}
	
	
	
	fread(&V,sizeof(JAB),1,PF);

	while(!feof(PF))
	{
		printf("\n %d             %d            %s          %d",V.CJ,V.NTJ,V.PRES,V.Q);
        fread(&V,sizeof(JAB),1,PF);

	}

	fclose(PF);

	}

/////////////////////////////////////////////////
	void GENERAR2()

{
	int aux;
	PROD V;
	FILE *PF;

	PF=fopen("PRODUCCION.DAT","wb");
	if (PF==NULL)
	    {   printf("\n NO SE PUDO ENCONTRAR EL ARCHIVO");
	        getch();
	        exit(1);
		}


	printf("\n INGRESE EL DIA DE PRODUCCION ");
	scanf("%d", &V.DP);

	while(V.DP!=0)
	{

	printf("\n INGRESE EL CODIGO DE JABON: ");
	scanf("%d", &V.CJJ);


	printf("\n INGRESE LA CANTIDAD PRODUCIDA: ");
	scanf("%d", &V.QP);


	fwrite(&V,sizeof(PROD),1,PF);

	printf("\n INGRESE EL DIA DE PRODUCCION: ");
	scanf("%d", &V.DP);
		}



	fclose(PF);

	}





