#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100
#define LPAL 32
typedef enum { FALSO, VERDAD } bool;

struct n
{
	char pal[LPAL];
	int cant;
	struct n * pSig;
};

typedef struct n nodo;
typedef nodo* pNodo;

bool EsSeparador(char);
void convertirMay(char palabra[]);
pNodo estaEnLista(pNodo inicio, char pal[]);
pNodo liberarLista(pNodo inicio);

int main(void)
{
	bool EnPalabra = FALSO, fin = FALSO;
	char car, pal[LPAL];
	int i = 0, cantPal = 0, j = 0;
	pNodo inicio = NULL, nuevo, actual;
	FILE *pf = fopen("Palabras.txt", "rt");
	if (pf == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		return 1;
	}


	car = (char) fgetc(pf);
	while (!feof(pf) && !fin)
	{
		if (!EnPalabra)
		{
			if (!EsSeparador(car))/* inicio palabra */
			{
				EnPalabra = VERDAD;
				cantPal++;
				j = 0;
				pal[j] = car;
				j++;
			}
		}
		else
		{
			if (EsSeparador(car)) /* fin palabra */
			{
				EnPalabra = FALSO;
				pal[j] = '\0';
				convertirMay(pal);
				printf("%-*s\n", LPAL, pal);
				actual = estaEnLista(inicio, pal);
				if (actual != NULL)
					actual->cant++;
				else
				{
					nuevo = (pNodo)malloc(sizeof(nodo));
					if (nuevo == NULL)
					{
						printf("No hay memoria\n");
						fin = VERDAD;
					}
					else
					{
						/* completar datos de nuevo */
						strcpy(nuevo->pal, pal);
						nuevo->cant = 1;
						/* vincular nodo nuevo a la lista */
						nuevo->pSig = inicio;
						inicio = nuevo;
					}
				}
			}
			else
			{
				pal[j] = car;
				j++;
			}
		}
		car = (char)fgetc(pf);
	}
	fclose(pf);
	printf("Cantidad de palabras: %d\n", cantPal);

	printf("Cantidad de veces que aparece cada palabra\n");
	actual = inicio;
	while (actual != NULL)
	{
		printf("%-*s%4d\n", LPAL, actual->pal, actual->cant);
		actual = actual->pSig;
	}

	inicio = liberarLista(inicio);
	return 0;
}

bool EsSeparador(char c)
{
	static char separadores[] = " ,.-+*/#&=;:_\"\'?!()[]{}\n";
	if (strchr(separadores, c))
		return VERDAD;
	return FALSO;
}

void convertirMay(char palabra[])
{
	int i = 0;
	while (palabra[i] != '\0')
	{
		palabra[i] = toupper(palabra[i]);
		i++;
	}
}

pNodo estaEnLista(pNodo inicio, char pal[])
{
	while (inicio != NULL && strcmp(inicio->pal, pal) != 0)
		inicio = inicio->pSig;
	return inicio;
}

pNodo liberarLista(pNodo inicio)
{
	pNodo lib;
	while (inicio != NULL)
	{
		lib = inicio;
		inicio = inicio->pSig;
		free(lib);
	}
	return inicio;
}
