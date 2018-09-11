/*
Si se deseara imprimir los resultados de multiplicar un número fijo por otro que adopta valores entre 0 y 9 , la forma normal de programar esto sería crear una constante para el primer número y un par de variables para el segundo y para el resultado del producto. Una variable, en realidad , no es más que un nombre para identificar una (o varias) posiciones de memoria donde el programa guarda los distintos valores de una misma entidad . Un programa debe definir todas las variables que utilizará antes de comenzar a usarlas, a fin de indicarle al compilador de que tipo serán y, por tanto, cuánta memoria debe destinar para albergar a cada una de ellas. Veamos un ejemplo:
*/

#include <stdio.h>

main()
{
	int multiplicador;	/* defino multiplicador como un entero */
	int resultado;		/* defino resultado como un entero */
  int numero;	/* crea la variable numero, de tipo número entero */
  char letra;	/* crea la variable letra, de tipo carácter*/
  float a, b;	/* crea dos variables a y b, de tipo número de coma flotante */

	multiplicador = 1000 ;	/* le asigno valores */
	resultado = 2 * multiplicador ;
	printf("Resultado = %d\n", resultado);	/* muestro el resultado */

	return 0;
}
