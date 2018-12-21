

#include <stdio.h>
#include <conio.h>

void Switch(float[],int, int);
void Orden(float [],int);

main()
	{

	int i;
	
	float Vx[6]={1,8,9,3,5,4};

	Orden(Vx,6);
	
	for(i=0;i<6;i++)
		{printf("\n %f",Vx[i]);}


	getch(); /*Pausa*/
	}


//////////////////////////////////////////////////////////////////////////////////////////////
void Orden(float V[],int n)
{

	int i,j;

	for (i=1;i<n;i++)
	{
	    j=i;

		while(j>0)
		{
			if (V[j]<V[j-1])
				Switch(V,j,j-1);

			j--;
		}

	}




}

///////////////////////////////////////////////////////////////////////////////
void Switch(float V[],int posA, int posB)

{
	float puente;

	puente = V[posA];
    V[posA] = V[posB];
    V[posB] = puente;

}

