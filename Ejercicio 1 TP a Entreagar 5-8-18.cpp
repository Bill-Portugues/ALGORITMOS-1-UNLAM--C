//Ejercicio 1 8/5/2018 - Elementos de Programacion
//Autor: Lucas Serrenho
// Se considera Float la Nota ya que se considera que puede haber nota con decimales. Ej 7.5


#include <stdio.h>
#include <conio.h>
#define alum 4

main()
{
	int QDes=0, QProm=0,QGener=0,DNI;
	float NOTA,PromP=0;


	printf("\t\n Para salir del programa pulsar 0 en lugar del DNI \t \n\n Ingrese el DNI del Alumno #1:  ");
	scanf("%d",&DNI);

	while(DNI!=0 && QGener<alum)
	{
		QGener++;
		printf(" Ingrese la NOTA del Alumno #%d: ",QGener);
		scanf("%f",&NOTA);

		if(NOTA>= 7)
		{
			QProm++;
			PromP+=NOTA;
		}
		else
			if(NOTA<4)
				QDes++;

		if (QGener<alum)
		{
			printf("\t\n Ingrese el DNI del Alumno #%d:  ", QGener+1);
			scanf("%d",&DNI);
		}
	}
	
	printf("\t\n Cantidad de Alumnos Reprobados: %d",QDes);

    if (QGener>0)
		printf("\t\n Nota Promedio de los Alumnos que pueden promocionar: %.2f",(float)PromP/QProm);

    printf("\t\n Cantidad de Alumnos NO Presentados al examen %d",alum-QGener);


getch(); /*Pausa*/
}
