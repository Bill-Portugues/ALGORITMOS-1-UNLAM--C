//Ejercicio 3 Funciones - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define QDias 30
#define Nexit 'F'
#define DescC -0.3
#define DescE -0.1
#define DescT 0.12
#define IVA 0.21


int ControlMayor(int,int=-1);
float ImporteNeto(float,int);
char LeeControlLetra(char,char,char,char);

//////////////////////////////////////////////////////////////////////////
main()
{
	int Importe;
	float EyC=0,Tarj=0,TotVentas;
	char LETRA;

	printf("\t\n Si desea salir del sistema ingresar '%c' \t\n Indique la forma de pago: C-Cooperativa, E-Contado, T-Tarjeta \t\n  ",Nexit);
	LETRA=LeeControlLetra('C','E','T','F');

	while(LETRA!=Nexit)
	{

        printf("\nIngrese El importe total de la Venta: ");
		Importe=ControlMayor(0);


	    switch(LETRA)
		{
			case 'C':
				EyC+=ImporteNeto(DescC,Importe);
				break;
			case 'E':
				EyC+=ImporteNeto(DescE,Importe);
				break;
			case 'T':
				Tarj+=ImporteNeto(DescT,Importe);
				break;
			case 'F':
				printf("\t\n -Procesando Ventas del dia-");
				break;
		
		}

	printf("\t\n Indique la forma de pago: C-Cooperativa, E-Contado, T-Tarjeta \t\n  ");
	LETRA=LeeControlLetra('C','E','T','F');
	

	}
    TotVentas= EyC + Tarj;

///Mejorar con printadores especiales por tipo de vehiculo
	printf("\t\n A) Ventas en Caja: %.2f \t\n B) Ventas con tarjeta: %.2f", EyC,Tarj);
	printf("\t\n C) Total de Ventas: %.2f \t\n D) Importe del IVA: %.2f", TotVentas,TotVentas*IVA);


getch(); /*Pausa*/
}

float ImporteNeto(float desc, int Imp)
{
	return (Imp*(1+desc));
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


