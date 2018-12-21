//Ejercicio 4 Funciones - Elementos de Programacion
//Autor: Lucas Serrenho


#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define TotDep 50
#define MinDep 100
#define MaxDep 500
#define Nexit 0

int LeeControlRango (int,int,int=-1);
float ControlMayorFloat(int,int=-1);
char LeeControlLetra(char,char);
float PORCENTAJE(int,int);
//////////////////////////////////////////////
main()
{
	int Depto,Cont=0;
	float Importe,SF=0,SA=0;
	char LETRA;

	printf("\t\n Si desea salir del sistema ingresar %d \t\n Indique El numero de Departamento: ",Nexit);
	Depto=LeeControlRango(MinDep,MaxDep,Nexit);

	while(Cont<TotDep && Depto!=Nexit)
	{

        printf("\t\n Indique el sector del departamento: F-Frente, A-Atras \t\n ",Nexit);
		LETRA=LeeControlLetra('F','A');

		printf("\nIngrese El importe de la expensa: ");
		Importe=ControlMayorFloat(0);
		
		printf( "\n %.2f",Importe);
		
		if(LETRA=='A')
			SA+=Importe;
  		else
			SF+=Importe;

        Cont++;
        
		if (Cont<TotDep)
		{
			printf("\t\n -Expensa Procesada- \t\n\n Indique El numero de Departamento: ",Nexit);
			Depto=LeeControlRango(MinDep,MaxDep,Nexit);
		}
		
	}
	
	printf("\t\n Lo Recaudado en el Sector del Frente es %.2f y en el Sector de Atras es %.2f",SF,SA);
	printf("\t\n El Porcentaje de Departamentos habitados son: %.2f %%",PORCENTAJE(Cont,TotDep));
	getch(); /*Pausa*/
}
/////////////////////////////////////////////////////////////
int LeeControlRango (int min,int max,int expulsor)
{

	int dato;
	scanf(" %d",&dato);


	while (dato<min || dato>max)
	{

        if(dato==expulsor)
		    return(dato);

		printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",min,max);
   		scanf(" %d",&dato);
	}

	return (dato);
}

char LeeControlLetra (char Op1,char Op2)
{
	char dato,datoM;
	bool Fin=false;


	while(Fin!=true)
	{

		scanf(" %c",&dato);
		datoM=toupper(dato);

		if(datoM == Op1 || datoM == Op2 )
		{
			Fin=true;
			return (datoM);
		}


		printf("\t\n Vuelva a intentarlo, unicamente son validos las opciones %c - %c : ",Op1,Op2);

	}

}

float ControlMayorFloat (int mayor, int expulsor)
{
	float dato;
	scanf(" %f",&dato);

	while (dato<=mayor)
	{

        if(dato==expulsor)
		    return(dato);

		printf("\t\n El numero ingresado debe ser superior a %d \t\n Vuelva a Intentarlo: ",mayor);
   		scanf(" %f",&dato);
	}

	return (dato);
}

float PORCENTAJE (int q,int Tot)
{

return (((float)q/Tot)*100);

}
