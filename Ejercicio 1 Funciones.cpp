//Ejercicio 1 Funciones - Elementos de Programacion
//Autor: Lucas Serrenho

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define QAutos 4
#define QDias 30
#define QMeses 12
#define QCodProd 3
#define QCRemitos 4
#define MesR 3 ///Para que el reporte sea del mes de Marzo
#define DiaR 15 /// Para que el reporte sea superior o igual al dia del mes que se selecciona


int LeeControlNro (int,int=-1);
int LeeControlRango (int,int,int=-1);
int ControlMayor(int,int=-1);
void PrintadorAutos (int,int,int);
//////////////////////////////////////////////////////////////////////////
main()
{
	int CRemito,Auto,Dia,Mes,CodProd,QEntrega, ReporDiaMes=0;
	int V1=0,V2=0,V3=0,V4=0; /// Declarados los 4 vechiculos
	int QV1=0,QV2=0,QV3=0,QV4=0; /// Declarados los 4 contadores de los vehiculos


	printf("\t\n Si desea salir del sistema ingresar 0 \t\n Ingrese el Nro de Remito:  ");
	CRemito=LeeControlNro(QCRemitos,0);

	while(CRemito!=0)
	{

        printf("\nIngrese La Cantidad a entregar: ");
		QEntrega=ControlMayor(0);


		printf("\nIngrese el Numero de Vehiculo: ");

		Auto=LeeControlRango(1,QAutos);

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


		printf("\n Ingrese el Dia de Entrega: ");
		Dia=LeeControlRango(1,QDias);

		printf("\n Ingrese el Mes de Entrega: ");
		Mes=LeeControlRango(1,QMeses);

		if(Dia>DiaR && Mes == MesR)
		    ReporDiaMes++;

		printf("\nIngrese el Codigo de Progducto: ");
		CodProd=LeeControlNro(QCodProd);

		printf("\t\n -Pedido Procesado-");

		printf("\t\n\n\n Si desea salir del sistema ingresar 0 \t\n Ingrese un Nuevo Nro de Remito:  ");
		CRemito=LeeControlNro(QCRemitos,0);

	}


///Mejorar con printadores especiales por tipo de vehiculo
	printf("\t\n Hubo %d entregas en la segunda quincena de marzo", ReporDiaMes);
	PrintadorAutos(1,V1,QV1);
	PrintadorAutos(2,V2,QV2);
	PrintadorAutos(3,V3,QV3);
	PrintadorAutos(4,V4,QV4);


getch(); /*Pausa*/
}



int LeeControlNro (int target,int expulsor)
{

	int dato,max,min;


	min=pow(10, target-1); ///Siempre va a ser el numero entero mas chico posible con la 'x' cantidad de cifras q queramos
	max= min*10-1; ///Siempre va a ser el numero entero mas grande posible con la 'x' cantidad de cifras q queramos

	scanf("%d",&dato);

	while(dato>max || dato<min )
	{

		if(dato==expulsor)
		    return(dato);

		printf("\t\n El numero ingresado debe tener %d Cifras: ",target);
        scanf("%d",&dato);

	}

	return (dato);
}


int LeeControlRango (int min,int max,int expulsor)
{

	int dato;
	scanf("%d",&dato);


	while (dato<min || dato>max)
	{

        if(dato==expulsor)
		    return(dato);

		printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",min,max);
   		scanf("%d",&dato);
	}

	return (dato);
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

void PrintadorAutos(int n,int viajes,int productos)
{

printf("\t\n El Vehiculo %d hizo %d Viajes y Entrgo %d Productos",n,viajes,productos);

}
