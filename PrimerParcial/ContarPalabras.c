#include <stdio.h>
#include <string.h>

#define TAM 100
typedef enum { FALSO, VERDAD } bool; //creamos el booleano donde typedef enum designa 0 para el primer valor y 1 para el segundo, 3 para el tercero y así sucesivamente
//en este caso para que FALSO sea 0 y VERDADERO 1 se coloca primero FALSO y después VERDADERO

bool EsSeparador(char); //Prototipo para EsSeparador

int main(void)//Inicio función main ******************************
{
	bool EnPalabra = FALSO; //Inicializamos en Palabran en FALSO que gracias a lo que hicimos al principio es equivalente a 0
	char cad[TAM]; //Declaramos el vector/string con tamaño TAM
	int i = 0, cantPal=0; //Declaramos el contador i e inicializamos cantPal en 0 para arrancar la cuenta en 0

	printf("Ingresar texto: ");
	fgets(cad, TAM, stdin); //Utilizamos fgets para obtener los datos de teclado (stdin) con un tamaño TAM y en vector/string cad
	while (cad[i] != '\0') //Loop para que se repita mientras el valor obtenido no sea null (gracias a fgets siempre tendremos un \0 cuando se termine de ingresar los datos)
	{
		if (!EnPalabra) //Hacer esto cuando EnPalabra sea FALSO es decir si no está en palabra hay que hacer buscar si el caracter es un separador
		{
			if (!EsSeparador(cad[i]))/* inicio palabra - Entramos en la supuesta palabra, utilizando la función EsSeparador vemos si el caracter es un separador */
			{
				EnPalabra = VERDAD; // en caso que lo sea, aplicamos VERDAD
				cantPal++; //Incrementamos el contador de palabras
			}
		}
		else
		{
			if (EsSeparador(cad[i])) /* fin palabra - Volvemos a usar EsSeparador para verificar que lo que tenemos como caracter sea un separador */
			{
				EnPalabra = FALSO;  //Asignamos un FALSO y volvemos a empezar
			}
		}
		i++; //salimos del if e incrementamos para seguir comparando
	}
	printf("Cantidad de palabras: %d\n", cantPal);  //mostramos la magia de cuantas palabras obtenemos
	return 0; //Importante. debe devolver algo porque main tiene un int en la declaración
} //Fin función main **********************************************

bool EsSeparador( char c)  //Inicio funcion EsSeparador, con un char de nombre c que se recibe como parámetro
{
	static char separadores[] = " ,.-+*/#&=;:_\"\'?!()[]{}\n";  //Inicializamos un vector que tiene como contenido todos los separadores posibles
	if (strchr(separadores, c))  //haciendonos de la función strchr buscamos en el vector separadores el caracter recibido como parámetro c
  {
  	return VERDAD; //si lo encontramos es decir que strchr devuelve un 1 por ser TRUE devolvemos un VERDADERO
  }
  return FALSO; //si no se cumple devolvemos un falso, esto tambien podría ser un else, pero no es necesario. 
}
