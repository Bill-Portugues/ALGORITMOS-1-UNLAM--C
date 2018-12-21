//Ejercicio 29/5/2018 - Elementos de Programacion
//Autor: Lucas Serrenho
/* Se considera que las personas pueden trabajar fracciones de hora
 por lo cual se abarca con el tipo de dato float lo referido a horas. */

#include <stdio.h>
#include <conio.h>
#include<string.h>
#define VH 150
#define Q 5


///CARGAR LAS CONTROL RANGO NUMERO Y MAYOR DEL ULTIMO TP


main()
{
///	float HS[Q].SUE[Q],MIN;
	int res3;
	char res1[40];
	char res2[40];
	char res4[40];

	int BAND1=0,BAND2=0,BAND3=0,BAND4=0;
	
		printf("\n -COMPLETE TODO EN MAYUSCULAS PARA SU VLAIDEZ- ");
	
	printf("\n COMO SE LLAMA LA PERSONA MAS IMPORTANTE DE TU VIDA:   ");
	do
	{
		if(BAND1==0)
		    BAND1=1;
		else
		    printf("\n LE ERRASTE OJAJAZOS - PROBA DEVUELTA:   ");

	fflush(stdin);
	gets(res1);
	}while(strcmp(res1,"YOLY"));
	
	
			printf("\n COMO SE LLAMA LA SEGUNDA PERSONA MAS IMPORTANTE DE TU VIDA\n SOLO PONGA SU NOMBRE DE PILA: ");
	do
	{
		if(BAND2==0)
		    BAND2=1;
		else
		    printf("\n LE ERRASTE OJAJAZOS - PROBA DEVUELTA:  ");

	fflush(stdin);
	gets(res2);
	}while(strcmp(res2,"LUCAS"));
	
	

			printf("\n QUE DIA LA CONOCISTE, UNICAMENTE COLOQUE EL NUMERO: ");
	do
	{
		if(BAND3==0)
		    BAND3=1;
		else
		    printf("\n LE ERRASTE OJAJAZOS - PROBA DEVUELTA:  ");

	scanf("%d",&res3);
	}while(res3 != 29);
	
	printf("\n QUE FRASSE DIRIAS QUE ES LA QUE MAS VECES TE DIJO??: ");
	do
	{
		switch(BAND4)
		{case 0:
		break;
		case 1:
		printf("\n LE ERRASTE OJAJAZOS - DALE VOS PODES:  ");
		break;
		case 2:
        printf("\n UN ESFUERCITO MAS DALE, NO ES DIFICIL:  ");
        break;
        case 3:
		printf("\n YA CASI ESTAS DALE DALE, SON 2 PALABRAS:  ");
		break;
		case 4:
		printf("\n ULTIMA VIDA EHH, SON 5 LETRAS Y UN ESPACIO EN EL MEDIO:  ");
		break;
	}
	fflush(stdin);
	gets(res4);
	BAND4++;
	}while(strcmp(res4,"TE AMO") && BAND4<=4);

	if (BAND4<5)
	    printf("\n GANASTE %d BESOS POR EL ESFUERZO",BAND4);
 	else
	    printf("\n PERDISTE OJAZOS, MALISIMO, TE QUEDASTE SIN BESOS. FLOJELI AMOR");
	    

	///CARGASEC(DNI,HS,Q);
	///CARGA_SUE(HS,SUE,VH,Q);
	///MIN=MINIMO(SUE,Q);
	///INF_MIN(MIN,SUE,DNI,Q);
	///BUSQUEDA(DNI,SUE,Q);

	//printf("\t\n Ingrese el numero para hacer el calculo de la tabla:  ");
	///scanf("%d",&NUM);

	//for (i=1;i<=tab;i++)
	//	printf("\t\n %d x %d = %d",NUM,i,NUM*i);

getch(); /*Pausa*/
}
