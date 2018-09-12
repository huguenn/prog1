#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int **array;
	int n, i, j, aux, contador=0;
	//Solicito el tamaño del array
	printf ("Introduce el tamaño del array: ");
	scanf ("%d",&n);
	//Reservo la memoria para el array de NxNs
	array=(int**)malloc (n*sizeof (int*));
	for (i=0;i<n;i++)
		array[i]=(int*)malloc (n*sizeof (int));



    int f, c; //Declaro mis variables para la carga de la matriz
  	for (f = 0; f < F; f++)
  	{
  		for (c = 0; c < C; c++)
  		{
  			m[f][c] = rand() % (SUP - INF + 1) + INF; //cargo la fórmula para los rand, se suma el INF para que no arranque en cero
  		}
  	}




	//Relleno el array
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
      m[f][c] = rand() % (SUP - INF + 1) + INF; //cargo la fórmula para los rand, se suma el INF para que no arranque en cero
		}
	}

	//Muestro el array

	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("%4i", array[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");

	//Intercambio las diagonales
	for (i=0, j=n-1; i<n && j>=0;i++, j--){
		aux=array[i][i];
		array[i][i]=array[i][j];
		array[i][j]=aux;
	}

	//Muestro el array
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("%4i", array[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
