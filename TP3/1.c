/*
Realizar una función que invierta los caracteres de una cadena, sin utilizar vectores auxiliares y escribir un
programa que permita verificar su funcionamiento.
*/

#include <stdio.h>
#include <string.h>

#define MAX 50

void invertir(char[]);

void main() {
	int i, j;
	char cad[MAX]  = "holis";
	printf("Cadena original: %s\n", cad);
	invertir(cad);
	printf("Cadena invertida: %s\n", cad);
}

void invertir(char x[]) {
	int len = strlen(x), i = 0, j = len - 1;
	char aux;
	for (i; i < j; i++,j--) {
		aux = x[i];
		x[i] = x[j];
		x[j] = aux;
	}
}