/* Ejercicio 15- Iteracion - X,Y*/
// Author: Liucas Serrenho

#include <conio.h>
#include <stdio.h>
#define Part 5
#define Disp 10


int main()
{
	int QAI=0,QAD=0,QDI=0,QDD=0,i=0,z=0,Qcentro=0;
 	float X,Y;
	bool NoPrimo;
	char Eje;




	for (i=1;i<=Part;i++)
	{

		for (z=1;z<=Disp;z++)
	
		{	printf( "\t\n\n Ingrese la coordenada X del Disparo %d del participante %d: ",z,i );
			scanf(" %f",&X);

			printf( "\t\n\n Ingrese la coordenada Y del Disparo %d del participante %d: ",z,i );
			scanf(" %f",&Y);

			if (X==0 && Y==0)
			    Qcentro++;

			else if(X>0 && Y>0)
			    QAD++;
			    
			else if(X>0 && Y<0)
				QDD++;

			else if(X<0 && Y>0)
			    QAI++;

			else
			    QDI++;
		}

	}

		printf( " \n La cantidad total de disparos en el centro son %d \n ",Qcentro );
		
		printf( " \n Disparon por cuadrantes: \n\n\t Derecha Arriba %d \n\t Derecha Abajo %d\n\t Izquierda Arriba %d\n\t Izquierda Abajo %d ",QAD,QDD,QAI,QDI );


		getch(); /* Pausa */
    	return 0;




}

