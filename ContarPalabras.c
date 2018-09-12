#include <stdio.h>
#include <string.h>

#define TAM 100
typedef enum { FALSO, VERDAD } bool;

bool EsSeparador(char );

int main(void)
{
	bool EnPalabra = FALSO;
	char cad[TAM];
	int i = 0, cantPal=0;

	printf("Ingresar texto: ");
	fgets(cad, TAM, stdin);
	while (cad[i] != '\0')
	{
		if (!EnPalabra)
		{
			if (!EsSeparador(cad[i]))/* inicio palabra */
			{
				EnPalabra = VERDAD;
				cantPal++;
			}
		}
		else
		{
			if (EsSeparador(cad[i])) /* fin palabra */
			{
				EnPalabra = FALSO;
			}
		}
		i++;
	}
	printf("Cantidad de palabras: %d\n", cantPal);
	return 0;
}

bool EsSeparador( char c)
{
	static char separadores[] = " ,.-+*/#&=;:_\"\'?!()[]{}\n";
	if (strchr(separadores, c))
		return VERDAD;
	return FALSO;
}
