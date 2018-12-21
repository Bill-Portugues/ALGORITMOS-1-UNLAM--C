/* Ejercicio 17-04-18*/

#include <conio.h>
#include <stdio.h>



int main()
{

	float Sbru,Ded;
	
	#define Jub 0.11
	#define OS 0.03
	#define Seg 0.001


	int HT ;
 		printf("\t\n Ingrese la cantidad de horas trabajadas: " );
	    scanf("%d",&HT);


	float VH ;
	printf("\t\n Ingrese el valor por hora: " );
	    scanf("%f",&VH);

	Sbru = HT*VH;
	Ded = Sbru*(Jub+OS+Seg);

		printf("\t\n Sueldo Bruto %.2f \t\n Total de deducciones %.2f \t\n Sueldo Neto %.2f",Sbru,Ded,Sbru-Ded);


		getch(); /* Pausa */
   


		}

