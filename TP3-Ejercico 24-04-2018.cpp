/* Ejercicio 24/4/2018 */
// Author: Liucas Serrenho Pfefferkorn (DNI 36159282)
//Se considera que el Kilometraje puede ser un numero decimal.


#include <conio.h>
#include <stdio.h>
#define V 800

int main()
{

	float KMI, KMF, KMA;

	printf( "\t\n Ingrese el kilometraje al iniciar el viaje: " );
	scanf(" %f",&KMI);


	printf( "\t\n Ingrese el kilometraje actual: " );
	scanf(" %f",&KMA);
	    	
	KMF = V - (KMA-KMI);

 	if (KMF<=100)
		printf( "\t\n FALTA POCO" );
	else if (KMF<=200)
	    printf( "\t\n PARAMOS A DESAYUNAR" );
	else
		printf( "\t\n CARGAR NAFTA" );

    printf( "\t\n Faltan %.1f Km para llegar a tu destino",KMF );

	getch(); /* Pausa */
   	return 0;


}










