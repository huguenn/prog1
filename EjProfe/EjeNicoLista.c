#define _CRT_SECURE_NO_WARNINGS
/*
Leer un archivo y contar las palabras del mismo, y cuantas veces aparecen.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LNOM 50

struct palabras {
	char palabra[LNOM];
	int cont;
	struct palabras *pSig;
};
typedef struct palabras nodo;
typedef nodo *pNodo;

int esSeparador(char);
pNodo existeEnLista(pNodo inicio, char palabra[]);
void imprimirLista(pNodo inicio);
void liberarLista(pNodo inicio);

int main() {
	char cad[LNOM];
	char i = 0, c, palabra=0;
	int cant = 0;

	FILE *pf;
	pNodo pInicio = NULL, pNuevo, pActual;

	pf = fopen("C:\\archivosProg\\palabras", "rt");

	if (!pf) {
		printf("Error abriendo archivo.\n\n");
		return -1;
	}
	else {
		c = fgetc(pf);
		while (!feof(pf)) {
			while (!esSeparador(c)) {
				palabra = 1;
				cad[i] = tolower(c);
				c = fgetc(pf);
				i++;
			}

			if (i != 0) {
				cad[i] = '\0';
				i = 0;
			}

			if (palabra) {
				pActual = existeEnLista(pInicio, cad);

				if (pActual == NULL) {
					pNuevo = (pNodo)malloc(sizeof(nodo));
					if (pNuevo == NULL) {
						printf("Error de memoria.");
						return -1;
					}
					strcpy(pNuevo->palabra, cad);
					pNuevo->cont = 1;
					pNuevo->pSig = pInicio;
					pInicio = pNuevo;
				}
				else {
					pActual->cont++;
				}
			}
			palabra = 0;
			c = fgetc(pf);
		}
		imprimirLista(pInicio);
		liberarLista(pInicio);
		fclose(pf);
	}
	printf("\n");
	return 0;
}

int esSeparador(char car) {
	static char separadores[] = { " ,.;:-+_@?!/*\'\"%#\n\t" };
	if (strchr(separadores, car))
		return 1;
	return 0;
}

pNodo existeEnLista(pNodo ini, char cadena[]) {
	while (ini != NULL && (strcmp(ini->palabra, cadena) != 0))
		ini = ini->pSig;
	return ini;
}

void imprimirLista(pNodo inic) {
	int p = 1;
	while (inic != NULL) {
		printf("Palabra%d: %s\n", p, inic->palabra);
		printf("    Apariciones: %d\n\n", inic->cont);
		p++;
		inic = inic->pSig;
	}
}

void liberarLista(pNodo inicio) {
	pNodo lib;
	while (inicio != NULL) {
		lib = inicio;
		inicio = inicio->pSig;
		free(lib);
	}
}
