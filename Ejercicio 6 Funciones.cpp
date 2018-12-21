//Ejercicio 6 Funciones - Elementos de Programacion
//Autor: Lucas Serrenho


#include <stdio.h>
#include <conio.h>
#define MinComp 100
#define MaxComp 2000
#define MinProm 1200
#define Nexit 99

int LeeControlRango (int,int,int=-1);
float PROMEDIO (int,int);

////////////////
main()
{
	int SMinProm=0,QProm=0,num;
	
	printf("\t\n Si desea salir del sistema ingresar '%d' \t\n Ingrese un Numero Entero entre %d y %d:  ",Nexit,MinComp,MaxComp);
	num=LeeControlRango(MinComp,MaxComp,Nexit);

	while(num!=Nexit)
	{

		if(num>=MinProm)
		{
			QProm++;
			SMinProm+=num;
		}
	
		printf("\t\n Ingrese Otro Numero Entero entre %d y %d:  ",Nexit,MinComp,MaxComp);
		num=LeeControlRango(MinComp,MaxComp,Nexit);

	}

	printf("\t\n El promedio de los numeros ingresados superiores a %d e inferiores a %d es %.2f",MinProm,MaxComp,PROMEDIO(SMinProm,QProm));

getch(); /*Pausa*/
}

/////////////////

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

float PROMEDIO (int suma,int q)
{
	return ((float)suma/q);

}
