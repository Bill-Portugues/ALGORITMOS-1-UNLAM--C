//Ejercicio 22-5-18 - Elementos de Programacion
//Autor: Lucas Serrenho
// Considero que la segunda quincena arranca a partir del 16 de Marzo

#include <stdio.h>
#include <conio.h>
#define QAutos 4
#define QDias 30
#define QMeses 12
#define QCodProd 3
#define QCRemitos 4
#define MesR 3 ///Para que el reporte sea del mes de Marzo
#define DiaR 15 /// Para que el reporte sea superior o igual al dia del mes que se selecciona
#define Nexit 0

int LeeControlRangoExpulsor (int,int,int =-9999);
int LeeControlNroExpulsor (int,int=-9999);
int ControlMayor(int);
float PORCENTAJE(int,int);
void PrintadorAutos (int,int,int);
//////////////////////////////////////////////////////////////////////////
main()
{
	int CRemito,Auto,Dia,Mes,CodProd,QEntrega,ReporDiaMes=0;
	int V1=0,V2=0,V3=0,V4=0; /// Declarados los 4 vechiculos
	int QV1=0,QV2=0,QV3=0,QV4=0; /// Declarados los 4 contadores de los vehiculos
	float PorcV1;

	printf("\t\n Si desea salir del sistema ingresar 0 \t\n Ingrese el Nro de Remito:  ");

	CRemito=LeeControlNroExpulsor(QCRemitos,Nexit);

	while(CRemito!=0)
	{
       
        printf("\t\n Ingrese La Cantidad a entregar: ");
		QEntrega=ControlMayor(0);


		printf("\t\n Ingrese el Numero de Vehiculo: ");

		Auto=LeeControlRangoExpulsor(1,QAutos);

	    switch(Auto)
		{
			case 1:
				V1++;
				QV1+=QEntrega;
				break;
			case 2:
				V2++;
				QV2+=QEntrega;
				break;
			case 3:
				V3++;
				QV3+=QEntrega;
				break;
			case 4:
				V4++;
				QV4+=QEntrega;
				break;
		}


		printf("\t\n Ingrese el Dia de Entrega: ");
		Dia=LeeControlRangoExpulsor(1,QDias);

		printf("\t\n Ingrese el Mes de Entrega: ");
		Mes=LeeControlRangoExpulsor(1,QMeses);

		if(Dia>DiaR && Mes == MesR)
		    ReporDiaMes++;

		printf("\t\n Ingrese el Codigo de Producto: ");
		CodProd=LeeControlNroExpulsor(QCodProd);
		
 		printf("\t\n -Pedido Procesado-");

		printf("\t\n\n\n Ingrese un Nuevo Nro de Remito:  ");
		CRemito=LeeControlNroExpulsor(QCRemitos,0);

	}

	PrintadorAutos(1,V1,QV1);
	PrintadorAutos(2,V2,QV2);
	PrintadorAutos(3,V3,QV3);
	PrintadorAutos(4,V4,QV4);

	printf("\t\n\n Hubo %d entregas en la segunda quincena de marzo", ReporDiaMes);
	
	PorcV1 = PORCENTAJE(V1,V1+V2+V3+V4);
	
	if (PorcV1!=0)
	
		printf("\t\n\n Porcentaje de viajes realizados del Vehiculo 1: %.2f %%",PorcV1);

getch(); /*Pausa*/
}


///////////////////////////////////////////////////////////////////////////////
int LeeControlRangoExpulsor (int min,int max,int expulsor)
{

	int dato,Band=0;

	do
	{

        if (Band==0)
			Band=1;
		else
		    printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",min,max);

		scanf("%d",&dato);


	}while ((dato<min || dato>max) && dato !=expulsor);


	return(dato);

}



/////////////////////////////////////////////////////////////////////////////////////

int LeeControlNroExpulsor (int target,int expulsor) //// target va a ser la cantidad de cifras que queremos que tenga el numero
{

	int max,min=1,i;

	for(i=1;i<target;i++)
	{
		min*=10;
	}

	
	max= min*10-1;

	return (LeeControlRangoExpulsor(min,max,expulsor));
	
}

/////////////////////////////////////////////////////////////////////////////////
int ControlMayor (int mayor)
{
	int dato,Band=0;

	do
	{
        if (Band==0)
			Band=1;
		else
			printf("\t\n El numero ingresado debe ser superior a %d \t\n Vuelva a Intentarlo: ",mayor);

	   	scanf("%d",&dato);
	   	
	}while (dato<=mayor);

	return (dato);
}

//////////////////////////////////////////////////////////////////////////////////////

void PrintadorAutos(int n,int viajes,int productos)
{

	printf("\t\n\n El Vehiculo %d hizo %d Viajes y Entrgo %d Productos",n,viajes,productos);

}

//////////////////////////////////////////////////////////////////////////////////////


float PORCENTAJE (int q,int Tot)
{
	if (Tot!=0)
		return (((float)q/Tot)*100);
	else
	{
		printf("\t\n\n No Hay Datos para el calculo del Porcentaje");

		return(0);
	}
}
