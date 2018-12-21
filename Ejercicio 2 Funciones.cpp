//Ejercicio 2 Funciones - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define QDias 30
#define Nexit 0


int LeeControlRango (int,int,int=-1);
int ControlMayor(int,int=-1);
char LeeControlLetra(char,char,char,char);
void PrintadorGen (char,int);
//////////////////////////////////////////////////////////////////////////
main()
{
	int DiaR, Recaudacion,MinDA,MinQA=0,RA=0,RB=0,RC=0,RD=0;
	char LETRA;

	printf("\t\n Si desea salir del sistema ingresar 0 \t\n Ingrese Dia de Recaudacion:  ");
	DiaR=LeeControlRango(1,QDias,Nexit);

	while(DiaR!=Nexit)
	{

        printf("\nIngrese La Linea del SUBTE: ");
		LETRA=LeeControlLetra('A','B','C','D');

 		printf("\nIngrese La Recaudacion del dia: ");
		Recaudacion=ControlMayor(0);

	    switch(LETRA)
		{
			case 'A':
				if(RA==0)
				{
					MinQA=Recaudacion;
					MinDA=DiaR;
				}
				else
					if(Recaudacion<MinQA)
					{
						MinQA=Recaudacion;
						MinDA=DiaR;
					}
					
				RA+=Recaudacion;
				break;
			case 'B':
				RB+=Recaudacion;
				break;
			case 'C':
				RC+=Recaudacion;
				break;
			case 'D':
				RD+=Recaudacion;
				break;
		}
		
		printf("\n Ingrese Dia de la Recaudacion: ");
		DiaR=LeeControlRango(1,QDias,Nexit);

	}


///Mejorar con printadores especiales por tipo de vehiculo
	printf("\t\n Dia de Menor Recaudacion de la linea A:  %d", MinDA);
	PrintadorGen('A',RA);
	PrintadorGen('B',RB);
	PrintadorGen('C',RC);
	PrintadorGen('D',RD);


getch(); /*Pausa*/
}


char LeeControlLetra (char Op1,char Op2,char Op3,char Op4)
{
	char dato,datoM;
	bool Fin=false;

	
	while(Fin!=true)
	{

		scanf(" %c",&dato);
		datoM=toupper(dato);
	
		if(datoM == Op1 || datoM == Op2 || datoM == Op3 || datoM == Op4 )
		{
			Fin=true;
			return (datoM);
		}
		

		printf("\t\n Vuelva a intentarlo, unicamente son validos las opciones %c - %c - %c - %c: ",Op1,Op2,Op3,Op4);

	}

}
int LeeControlRango (int min,int max,int expulsor)
{

	int dato;
	scanf("%d",&dato);


	while (dato<min || dato>max)
	{

        if(dato==expulsor)
		    return(dato);
		    
		printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",min,max);
   		scanf("%d",&dato);
	}

	return (dato);
}

int ControlMayor (int mayor, int expulsor)
{
	int dato;
	scanf("%d",&dato);

	while (dato<=mayor)
	{

        if(dato==expulsor)
		    return(dato);
		    
		printf("\t\n El numero ingresado debe ser superior a %d \t\n Vuelva a Intentarlo: ",mayor);
   		scanf("%d",&dato);
	}

	return (dato);
}

void PrintadorGen(char letra,int numero)
{

printf("\t\n La Linea %c tuvo de recaudacion %d",letra,numero);

}
