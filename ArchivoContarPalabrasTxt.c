#include <stdio.h>
#include <string.h>
//#define LEER_ARCHIVO "Origen.txt" //Agregado para que funcione con archivos
typedef enum { FALSO, VERDAD } boolean; //creamos el booleano donde typedef enum designa 0 para el primer valor y 1 para el segundo, 3 para el tercero y así sucesivamente
//en este caso para que FALSO sea 0 y VERDADERO 1 se coloca primero FALSO y después VERDADERO

bool EsSeparador(char); //Prototipo para EsSeparador
bool EsNumero(char);

int main(void)//Inicio función main ******************************
{
    bool EnPalabra = FALSO; //Inicializamos en Palabran en FALSO que gracias a lo que hicimos al principio es equivalente a 0
    FILE * pf; //Agregado para que funcione con archivos
    int cantPal = 0,i;
    char c,d,nombrearchivo[100], palabras[50]; //Inicio Agregado para que funcione con archivos
    printf("Ingresar Archivo a contar: ");
    scanf("%s", &nombrearchivo);
    pf=fopen(nombrearchivo, "rt");
    if(pf==NULL)
    {
        printf("No se puede abrir el archivo \n");
        return 1;
    }

    //while((c=fgetc(pf)) != EOF)
    c=fgetc(pf);
		i=0
    while(!feof(pf))
		{  //Fin Agregado para que funcione con archivos. Preguntar si el EOF está bien usado/es una buena practica

			if (!EnPalabra) //Hacer esto cuando EnPalabra sea FALSO es decir si no está en palabra hay que hacer buscar si el caracter es un separador
			{
				if (!EsSeparador(c))/* inicio palabra - Entramos en la supuesta palabra, utilizando la función EsSeparador vemos si el caracter es un separador */
				{
					EnPalabra = VERDAD; // en caso que lo sea, aplicamos VERDAD
					cantPal++; //Incrementamos el contador de palabras
					palabras[i]=c;				//Guarda en un string para que forme la palabra
					i++;
				}
			}
			else
			{
				if (EsSeparador(c)) /* fin palabra - Volvemos a usar EsSeparador para verificar que lo que tenemos como caracter sea un separador */
      	{
					EnPalabra = FALSO;  //Asignamos un FALSO y volvemos a empezar
					palabras[i]='\n';
					printf("%c",palabras);
					i=0;
				}
			}
                c=fgetc(pf);
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

bool EsNumero( int c)  //Inicio funcion EsSeparador, con un char de nombre c que se recibe como parámetro
{
	static int numero[] = "0123456789";  //Inicializamos un vector que tiene como contenido todos los separadores posibles
	if (strchr(numero, c))  //haciendonos de la función strchr buscamos en el vector separadores el caracter recibido como parámetro c
  {
  	return VERDAD; //si lo encontramos es decir que strchr devuelve un 1 por ser TRUE devolvemos un VERDADERO
  }
  return FALSO; //si no se cumple devolvemos un falso, esto tambien podría ser un else, pero no es necesario.
}
