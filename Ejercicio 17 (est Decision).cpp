/* Ejercicio 17*/

#include <conio.h>
#include <stdio.h>



int main()
{

	float S;
//	char ART[6];


	int CA ;
 		printf( "Ingrese el Codigo del Articulo a comprar: " );
	    scanf("%d",&CA);
	    

	int Q ;
	printf( "Ingrese la cantidad a comprar: " );
	    scanf("%d",&Q);
		
		

   switch(CA){
		case 1:
			S=Q*120;
		
//		char ART[] = "10;100";
			break;

		case 4:
			S=Q*100;
	//		char *ART = "44";
			break;

		case 3:
//			char *ART = "33";
			if (Q>10){
			    S=Q*200*0.9;
			}
			else{
				S=Q*200;
   }
			break;

		case 2:
			int CAJ,UNI;
			CAJ = Q/10;
			UNI = Q%10;
			S=CAJ*650+UNI*70;
//			char *ART = "22;220";
			break;

		default:
			break;

		}
		
		printf("\n ARTICULO \t CANTIDAD %d \t IMPORTE A PAGAR %.2f",Q,S);
	
		
		getch(); /* Pausa */
    	return 0;
    	
    	
		}





