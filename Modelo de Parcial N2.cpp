#include <stdio.h>
#include <conio.h>
#define QV 3
#define DIAS 7
#define QUINCENA 5


void ListCantidad(int [QV][3],int );
void ListRecau(int [QV][3],float [QV][DIAS],int ,int );
void NoViaje1(int [QV][3],float [QV][DIAS],int , int );
void InfMaximo(int ,int[QV][3],int , int , int );
int Maximo(int [QV][3],int ,int );
int BusquedaSec(int , int [QV][3],int );
void Carga(int[][3],int );
int LeeControl(int ,int );

main()
{

	float REC[QV][DIAS]={{0}},IMP;
	int POS,NV[QV][3],DF,NVS,MAX;
	
	Carga(NV,QV);
	
 	printf("\n INGRESE EL DIA DEL FLETE: ");
	DF=LeeControl(-1,DIAS+1);
	
	while(DF!=0)
	{
        printf("\n INGRESE EL NRO INTERNO DEL VEHICULO:  ");
		scanf(" %d",&NVS);
		
		POS=BusquedaSec(NVS,NV,QV);
		
		if (POS>=0)
		{
            printf("\n INGRESE EL IMPORTE DEL FLETE:  ");
			scanf(" %f",&IMP);

			if(DF>QUINCENA)
			    IMP*=0.95;

			REC[POS][DF-1]+=IMP;
			NV[POS][2]++;

		}
		else
		    printf("\n INTERNO INEXISTENTE \n");

        printf("INGRESE EL DIA DEL FLETE: ");
		DF=LeeControl(-1,DIAS);
	}
	
	MAX=Maximo(NV,2,QV);
	InfMaximo(MAX,NV,2,0,QV);
	NoViaje1(NV,REC,0,QV);
	ListRecau(NV,REC,QV,DIAS);
	ListCantidad(NV,QV);
	
	
	
getch(); /*Pausa*/
}
///////////////////////////////
void ListCantidad(int DONDEFILA[QV][3],int QFILAS)
{

	int i;

	printf("\n CANTIDAD DE VIAJES POR VEHICULO \n DNI PROPIETARIO \t CANTIDAD ");

	for(i=0;i<QFILAS;i++)
	{
		printf("\n \t %d \t\t\t  %d",DONDEFILA[i][1],DONDEFILA[i][2]);
	}


}




/////////////////////////
void ListRecau(int DONDEFILA[QV][3],float DONDEVALORES[QV][DIAS],int QFILAS,int QCOLUMNAS)
{

int i,j,k;

	printf("\n LISTADO DE RECAUDACION \n NRO. INTERNO VEHICULO / DIA \t");

	for(i=0;i<QCOLUMNAS;i++)
	{
		printf(" %d \t",i+1);
	}

	for(i=0;i<QFILAS;i++)
	{
		printf("\n %d 	",DONDEFILA[i][0]);

		for (j=0;j<QCOLUMNAS;j++)
		{
			printf(" %8.1f  ",DONDEVALORES[i][j]);
		}


	}
}


/////////////////////////
void NoViaje1(int DONDEREP[QV][3],float DONDEBUS[QV][DIAS],int COLBUSCAR, int QFILAS)
{
	int i,j;
	
	printf("\n LOS VEHICULOS SIN VIAJES EL DIA 1 SON: \n");

	for (i=0;i<QFILAS;i++)
	{   if(DONDEBUS[i][COLBUSCAR]==0)
	        printf("\n VEHICULO %d",DONDEREP[i][0]);
	}

}

/////////////////////////
void InfMaximo(int max,int DONDE[QV][3],int COLBUSCAR, int COLREPORTAR, int QFILAS)
{
	int i;

	printf("\n LOS VEHICULOS CON MAXIMO CANTIDAD DE VIAJES SON: \n");

	for(i=0;i<QFILAS;i++);
	{    if(max==DONDE[i][COLBUSCAR])
	        printf("\n VEHICULO %d",DONDE[i][COLREPORTAR]);
	}
}

/////////////////////////
int Maximo(int DONDE[QV][3],int COLUMNA,int QFILAS)
{
	int i,max=DONDE[0][2];

	for(i=1;i<QFILAS;i++)
	{
		if(max<DONDE[i][2]);
			max=DONDE[i][2];
	}
	return (max);
}



////////////////////////
int BusquedaSec(int QUE, int DONDE[QV][3],int QFILAS)
{
	int posi=-1,CONT=0;
	
	while(posi<0 && CONT<QFILAS)
	{
		if(DONDE[CONT][0]==QUE)
		    posi=CONT;
		else
		    CONT++;
	}


	
	return (posi);
}

/////////////////////////
void Carga(int MCARGA[QV][3],int q)
{
	int i;
	
	for(i=0;i<q;i++)
	{
	printf("INGRESE EL NRO DE VEHICULO %d: ",i+1);
	MCARGA[i][0]=LeeControl(999,10000);
	
    printf("INGRESE EL DNI DEL PROPIETARIO %d: ",i+1);
	scanf(" %d", &MCARGA[i][1]);
	
	MCARGA[i][2]=0;
	
	}

}

/////////////////////////
int LeeControl(int LI,int LS)
{
	int dato, band=0;

	do
	{
		if (band==0)
		    band=1;
		else
			printf("\n INTENTE NUEVAMENTE: ");
			
	scanf(" %d", &dato);

	}while(dato>LS || dato<LI);


return (dato);
}
