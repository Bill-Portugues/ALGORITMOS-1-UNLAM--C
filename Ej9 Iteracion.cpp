//Ejercicio 9 - Estructura de Repeticion
// Autor: Lucas Serrenho

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define  MAX 12

main()
{
int Q0=0, QP=0, QN=0, Num, I;
float  SumN=0,SumP=0,Nreal;


printf("Ingrese un numero entero entre 0 y %d: ",MAX);
scanf("%d",&Num);

if(Num>MAX){

	printf("Valor Excedido, Finaliza el programa");
	getch(); /*Pausa*/
	exit(-1);
}

for (I=1;I<=Num;I++){

	printf("Ingrese el Numero Real #%d: ",I);
	scanf("%f",&Nreal);


	if (Nreal>0){

		SumP +=Nreal;
		QP++;
	}
		
	else if(Nreal==0)

	    	Q0++;
	    	
		else{

	    	SumN +=Nreal;
	    	QN++;

	}

}
printf("\n\t Promedio positivos %.2f \n\t Promedio Negativos %.2f \n\t Q Suma de Numeros 0:  %d" ,(SumP/QP),(SumN/QN),Q0);
getch(); /*Pausa*/
}
