//Ejercicio 15-5-2018 - Elementos de Programacion
//Autor: Lucas Serrenho
//Segunda Quincena se considera desde el 16 del mes en adelante

#include <stdio.h>
#include <conio.h>
#define QDias 30
#define QMeses 12
#define MesR 3 ///Para que el reporte sea del mes de Marzo
#define DiaR 15 /// Para que el reporte sea superior o igual al dia del mes que se selecciona
#define QCRemito 4
#define QCodProd 3
#define Max4Cifras 10000
#define Min4Cifras 999
#define Max3Cifras 1000
#define Min3Cifras 99
#define MinVeh 1
#define MaxVeh 4

//////////////////////////////////////////////////////////////////////////
main()
{
	int CRemito,Auto,Dia,Mes,CodProd,QEntrega, ReporDiaMes=0,CodMin,CodMinVal,Cont=0;
	int V1=0,V2=0,V3=0,V4=0; /// Declarados los 4 vechiculos
	int QV1=0,QV2=0,QV3=0,QV4=0; /// Declarados los 4 contadores de los vehiculos


	printf("\t\n Si desea salir del sistema ingresar 0 \t\n Ingrese el Nro de Remito:  ");
	scanf("%d",&CRemito);
	
	while((CRemito>Max4Cifras || CRemito<Min4Cifras )&& CRemito!=0)
	{
		printf("\t\n El numero ingresado debe tener %d Cifras: ",QCRemito);
        scanf("%d",&CRemito);
	}

	while(CRemito!=0)
	{	
        Cont++;
        
	    printf("\t\n Ingrese La Cantidad a entregar: ");
		scanf("%d",&QEntrega);
		while (QEntrega<=0)
		{
			printf("\t\n El numero ingresado debe ser superior a %d \t\n Vuelva a Intentarlo: ",0);
   			scanf("%d",&QEntrega);
		}
		
		printf("\t\n Ingrese el Numero de Vehiculo: ");
		scanf("%d",&Auto);
		while (Auto<MinVeh || Auto>MaxVeh)
		{
			printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",MinVeh,MaxVeh);
   			scanf("%d",&Auto);
		}

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
		scanf("%d",&Dia);
		while (Dia<1 || Dia>QDias)
		{
			printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",1,QDias);
   			scanf("%d",&Dia);
		}
		
		printf("\t\n Ingrese el Mes de Entrega: ");
		scanf("%d",&Mes);
		while (Mes<1 || Mes>QMeses)
		{
			printf("\t\n El numero ingresado debe ser superior o igual a %d e inferior o igual %d \t\n Vuelva a Intentarlo ",1,QMeses);
   			scanf("%d",&Mes);
		}

		if(Dia>DiaR && Mes == MesR)
		    ReporDiaMes++;

		printf("\t\n Ingrese el Codigo de Producto: ");
		scanf("%d",&CodProd);
		
		while(CodProd>Max3Cifras || CodProd<Min3Cifras )
		{
			printf("\t\n El numero ingresado debe tener %d Cifras: ",QCodProd);
        	scanf("%d",&CodProd);
		}
		
		if (Cont==1)
		{
			CodMin=CodProd;
			CodMinVal=QEntrega;
		}
		else
		    if(CodMinVal>QEntrega)
			{
                CodMin=CodProd;
				CodMinVal=QEntrega;
			}

		printf("\t\n -Pedido Procesado-");

		printf("\t\n\n\n Ingrese Un Nuevo Nro de Remito:  ");
		scanf("%d",&CRemito);

		  while((CRemito>Max4Cifras || CRemito<Min4Cifras) && CRemito!=0 )
		{
			printf("\t\n El numero ingresado debe tener %d Cifras: ",QCRemito);
        	scanf("%d",&CRemito);
		}

	}

	if(Cont>0)
	{	
		printf("\t\n El Vehiculo %d hizo %d Viajes y Entrego %d Productos",1,V1,QV1);
		printf("\t\n El Vehiculo %d hizo %d Viajes y Entrego %d Productos",2,V2,QV2);
		printf("\t\n El Vehiculo %d hizo %d Viajes y Entrego %d Productos",3,V3,QV3);
		printf("\t\n El Vehiculo %d hizo %d Viajes y Entrego %d Productos",4,V4,QV4);

		printf("\t\n\n Hubo %d entregas en la segunda quincena de marzo", ReporDiaMes);
	
		printf("\t\n\n El Codigo del Producto con menor Entrega es: %d", CodMin);
	}
	else
	    printf("\t\n No Hay Datos Ingresados.");
	    
	getch(); /*Pausa*/
}



