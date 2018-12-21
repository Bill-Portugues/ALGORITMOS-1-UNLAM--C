//Ejercicio 5 Funciones - Elementos de Programacion
//Autor: Lucas Serrenho


#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define AnoMin 1950
#define AnoMax 2050
#define Nexit 0
#define CifrasTicket 4
#define MaxCodProd 500
#define MinCodProd 100
#define PresBols1 1
#define PresBols2 3
#define PresBols3 15
#define Tipo1 'P'
#define Tipo2 'G'


int LeeControlNro (int,int=-1);
float PORCENTAJEVal(int,int);
int LeeControlRango (int,int,int=-1);
int LeeControlPresentacion (int,int,int);
char LeeControlLetra2Op(char,char);
int ControlMayor(int,int=-1);
float ControlMayorFloat(float,int=-1);
void LeeFechaValida(int*,int*,int*);/// DECLARO PUNTEROS PARA QUE ME DEVUELVAN LOS DATOS
bool CheckB(int);
int ContadorDiaMes(int,bool);
void KgBolsas(int*,int*,int*,int,int);
void PrintadorPorcentajes(float,int);

/////////////////////////////

main()
{
int dia,mes,ano,NTicket,CodProd,NBolsa,Q,KgP1=0,KgP3=0,KgP15=0,KgG1=0,KgG3=0,KgG15=0,Perros,Gatos,TotalKg;
float Importe,SImporte=0;
char NTipo;

LeeFechaValida(&dia,&mes,&ano); ///ASIGNO LOS PUNTEROS PARA OBTENER LOS DATOS DE LA FUNCION




printf("\t\n Si desea salir del sistema ingresar %d \t\n Ingrese el Nro de Ticket:  ",Nexit);
NTicket=LeeControlNro(CifrasTicket,Nexit);

while(NTicket!=Nexit)
{
	printf("\t\n Codigo del Producto:  ");
	NTicket=LeeControlRango(MinCodProd,MaxCodProd);

	printf("\t\n Ingrese Presentacion de la Bolsa \t\n %d = un Kg \t\n %d = tres Kg \t\n %d = quince Kg \t\n  ",PresBols1,PresBols2,PresBols3);
    NBolsa=LeeControlPresentacion(PresBols1,PresBols2,PresBols3);

    printf("\t\n Ingrese El tipo de Alimento\t\n %c = Perro \t\n %c = Gato \t\n  ",Tipo1,Tipo2);
    NTipo=LeeControlLetra2Op(Tipo1,Tipo2);

	printf("\t\n Ingrese la cantidad de bolsas: ");
    Q=ControlMayor(0);

	printf("\t\n Ingrese el importe de la Recaudacion: ");
    Importe=ControlMayorFloat(0);
	SImporte+=Importe;

	if(NTipo=='G')
		KgBolsas(&KgG1,&KgG3, &KgG15, NBolsa,Q);
	else
	    KgBolsas(&KgP1,&KgP3, &KgP15, NBolsa,Q);

    printf("\t\n -VENTA PROCESADA- \t\n");

	printf("\t\n Ingrese un nuevo Nro de Ticket:  ");
	NTicket=LeeControlNro(CifrasTicket,Nexit);
}

Perros=KgP1+KgP3+KgP15;
Gatos=KgG1+KgG3+KgG15;
TotalKg=Perros+Gatos;

printf("\n\n\n\n RESUMEN DEL %d / %d / %d \n\n\n\n" ,dia,mes,ano);

if(TotalKg!=0)
{
	printf("\t\n KG DE PERROS: %d \t\n KG DE GATOS: %d",Perros,Gatos);
	PrintadorPorcentajes(PORCENTAJEVal(KgP1+KgG1,TotalKg),1);
	PrintadorPorcentajes(PORCENTAJEVal(KgP3+KgG3,TotalKg),3);
	PrintadorPorcentajes(PORCENTAJEVal(KgP15+KgG15,TotalKg),15);
	printf("\t\n RECAUDADO TOTAL: %.2f",SImporte);
}



getch(); /*Pausa*/
}










///////////////////////////
void PrintadorPorcentajes(float Por,int TipoBolsa)
{

	printf("\t\n PORCENTAJE DE BOLSAS DE %dKG: %.2f%%",TipoBolsa,Por);

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


float PORCENTAJEVal (int q,int Tot)
{
if (Tot!=0)
	return (((float)q/Tot)*100);
else
	{
		printf("No Hay Datos");
		return(0);
	}
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

int LeeControlPresentacion(int Op1, int Op2, int Op3)

{
	int dato;
	bool Fin=false;


	while(Fin!=true)
	{

		scanf(" %d",&dato);

		if(dato == Op1 || dato == Op2 || dato == Op3 )
		{
			Fin=true;
			return (dato);
		}


		printf("\t\n Vuelva a intentarlo, unicamente son validos las opciones %d - %d - %d: ",Op1,Op2,Op3);



	}
}

char LeeControlLetra2Op (char Op1,char Op2)
{
	char dato,datoM;
	bool Fin=false;


	while(Fin!=true)
	{

		scanf(" %c",&dato);
		datoM=toupper(dato);

		if(datoM == Op1 || datoM == Op2 )
		{
			Fin=true;
			return (datoM);
		}


		printf("\t\n Vuelva a intentarlo, unicamente son validos las opciones %c - %c : ",Op1,Op2);

	}

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

float ControlMayorFloat (float mayor, int expulsor)
{
	float dato;
	scanf("%f",&dato);

	while (dato<=mayor)
	{

        if(dato==expulsor)
		    return(dato);

		printf("\t\n El numero ingresado debe ser superior a %.2f \t\n Vuelva a Intentarlo: ",mayor);
   		scanf("%f",&dato);
	}

	return (dato);
}

void KgBolsas(int *k1,int *k3,int *k15,int Tbolsas,int Q)

{

switch(Tbolsas)
		{
			case 1:
				*k1+=(1*Q);
				break;
			case 3:
				*k3+=(3*Q);
				break;
			case 15:
				*k15+=(15*Q);
				break;
	}

}

void LeeFechaValida(int *dia,int *mes,int *ano) /// DECLARO LAS VARIABLES COMO PUNTEROS
{
	int DiasMes;
	

	printf("\t\n Ingrese el ano: ");
	*ano=LeeControlRango(AnoMin,AnoMax);
	
    printf("\t\n Ingrese el mes: ");
    *mes=LeeControlRango(1,12);
	DiasMes=ContadorDiaMes(*mes,CheckB(*ano));
	
	printf("\t\n Ingrese el dia: ");
	*dia=LeeControlRango(1,DiasMes);
	
}

bool CheckB(int ano)
{
	if((ano-2016)%4==0)
	    return (true);
	else
	    return (false);
}

int ContadorDiaMes (int mes,bool biciesto)
{
	if(mes==2)
	{
		if (biciesto==true)
		    return (29);
		else
		    return (28);
	}
	
	if (mes==4 || mes==6 || mes==9 || mes==11)
	    return (30);
	else
	    return (31);
	    
}
