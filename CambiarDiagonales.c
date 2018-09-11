#include  <stdio.h>
#include <stdlib.h>

int main ()
{

	int **array;
	int n, i, j, aux, contador=0;
	//Solicito el tamaño del array
	printf ("Introduce el tamanio del array: ");
	scanf ("%d",&n);
	//Reservo la memoria para el array de NxN
	array=(int**)malloc (n*sizeof (int*));
	for (i=0;i<n;i++)
		array[i]=(int*)malloc (n*sizeof (int));

	//Relleno el array
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			contador++;
			array[i][j]=contador;
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
