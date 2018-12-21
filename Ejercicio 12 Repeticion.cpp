/* Ejercicio 12 - Iteracion*/
// Author: Liucas Serrenho

#include <conio.h>
#include <stdio.h>
#define PROM 7
#define FINAL 4


int main()
{
	int DNI,NP1,NP2,QA=0;
 	float SumA=0;
	bool Fin=true;



	do
	{

		printf( "\t\n\n Ingrese el DNI del Alumno: " );
	   	scanf(" %d",&DNI);

		if (DNI>=0)

		{
			printf( "\t\n\n Ingrese la nota del primer parcial: " );
	   		scanf(" %d",&NP1);

			printf( "\t\n\n Ingrese la nota del segundo parcial: " );
	   		scanf(" %d",&NP2);

		}
		else
			Fin=false;
				
	


   		if (NP1>=PROM && NP2>=PROM)
		{
			QA++;
			SumA += NP1+NP2;
            printf( "\t\n El alumno con DNI %d Saco un %d en el primer parcial y un %d en el segundo parcial. \t\n\n Por ende PROMOCIONA \t\n\n Actualmente la Nota promedio de los alumnos promocionados es %.1f: ",DNI,NP1,NP2,(SumA/(QA*2)));
  		}
		
		else if(NP1>=FINAL && NP2>=FINAL)
			printf( "\t\n El alumno con DNI %d Saco un %d en el primer parcial y un %d en el segundo parcial. \t\n\n Por ende RINDE EXAMEN FINAL \t\n\n Actualmente la Nota promedio de los alumnos promocionados es %.1f: ",DNI,NP1,NP2,(SumA/(QA*2)));

		else
			printf( "\t\n El alumno con DNI %d Saco un %d en el primer parcial y un %d en el segundo parcial. \t\n\n Por ende REPROBO LA MATERIA \t\n\n Actualmente la Nota promedio de los alumnos promocionados es %.1f: ",DNI,NP1,NP2,(SumA/(QA*2)));

	}while(Fin);

		getch(); /* Pausa */
    	return 0;


}






