//Ejercicio 8 - Estructura de Repeticion

#include <stdio.h>
#include <conio.h>

main()
{
int edad, QM10=0, QMe=0,I,Qal;
float stat, SumStat=0,SumEdad=0;


printf("Ingrese la cantidad de alumnos a evaluar: ");
scanf("%d",&Qal);

for (I=1;I<=Qal;I++){

	printf("Ingrese la edad del alumno %d: ",I);
	scanf("%d",&edad);

	printf("Ingrese la estatura del alumno %d: ", I);
	scanf("%f",&stat);

	SumEdad += edad;
	SumStat += stat;

	if (edad>10){

		QM10++;
		
	}

	if (stat<1.4){

		QMe++;
	}

}

printf("\n\t Edad promedio %.2f \n\t Estatura promedio %.2f \n\t Q Alumnos Mayores 10 anos %d \n\t Q Alumnos Menores de 1.4: %d",(SumEdad/Qal),(SumStat/Qal),QM10,QMe);
getch(); /*Pausa*/
}
