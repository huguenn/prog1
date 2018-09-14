/*
Realizar una función que calcule y devuelva la cantidad de palabras (separadas por uno o más guiones) que
tiene una frase y escribir un programa que permita verificar su funcionamiento.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int funcion(char[]);

void main() {
	char cad[]  = "a--b-c";
	funcion(cad);
}

int funcion(char x[]) {
	int aux = 0, cant = 0, len = strlen(x);
	for (int i = 0; i < len; i++){
		if (!aux) {
			if (x[i] != '-') {
				aux = 1;
				cant++;
			}
		} else {
			if (x[i] == '-') {
				aux = 0;
			}
		}
	}
	printf("Cantidad de palabras: %d\n",cant);
}