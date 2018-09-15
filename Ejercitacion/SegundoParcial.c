#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LNOM 32

struct n
{
	int numero;
	struct n * pSig;
};

typedef struct n nodo;
typedef nodo* pNodo;

void liberoLista(pNodo inicio);
void guardaraTxt(pNodo inicio);
void imprimirLista(pNodo inicio);

typedef enum { FALSO, VERDAD } bool;

int main(void)
{
	int numero,cant=0;
	pNodo inicio = NULL, nuevo;
	printf("Ingresar Numero: ");
	scanf("%d", &numero);
	while (numero != -1)
	{
		cant++;
		nuevo = (pNodo)malloc(sizeof(nodo));
		if (nuevo == NULL)
		{
			printf("sin memoria\n");
		}
		else
		{
				nuevo->numero = numero;
				nuevo->pSig = inicio;
				inicio = nuevo;
				printf("Ingresar otro numero: ");
				scanf("%d", &numero);			
		}
	}

	printf("Mostrar Lista Obtenida con %d numeros\n",cant);

	imprimirLista(inicio);

	printf("---------------------------------------------\n");
	guardaraTxt(inicio);
	printf("Liberar Lista\n");
	liberoLista(inicio);
	printf("--------------------------------------------\n");


	return 0;
}

void liberoLista(pNodo inicio)
{
	pNodo lib;
	while (inicio != NULL)
	{

			lib = inicio;
			inicio = inicio->pSig;
			free(lib);

	}
	
}

void imprimirLista(pNodo inicio) 
{
		pNodo actual;
		actual = inicio;
		if (actual == NULL) 
		{ 
			printf("Lista no tiene nada\n");
		}
		else 
		{
			while (actual != NULL)
			{
				printf("%d\n", actual->numero);
				actual = actual->pSig;
			}
		}
}

void guardaraTxt(pNodo inicio)
{
	FILE *pf=fopen("Numeros.txt", "wt");
		if(pf)
		{
					pNodo actual;
					actual = inicio;
					if (actual == NULL)
					{
						printf("La lista no tiene elementos \n");
					}
					else
					{
							while (actual != NULL)
							{
								fprintf(pf, "%d\n", actual->numero);
								actual = actual->pSig;
							}
					}
					fclose(pf); //<- EL CLOSE!!
		}
		else
		{
			printf("No se puede abrir archvo\n");
		}
}