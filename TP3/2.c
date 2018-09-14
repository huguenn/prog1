/*
Realizar una función que determine si una cadena de caracteres es capicúa, sin utilizar vectores auxiliares y
escribir un programa que permita verificar su funcionamiento.
*/

#include <stdio.h>
#include <string.h>

#define MAX 50

int palindromo(char[]);

void main() {
	int i, j;
	char cad[MAX]  = "mm";
	if (palindromo(cad))
		printf("Es palindromo");
	else
		printf("No es palindromo");
}

int palindromo(char x[]) {
	int j = strlen(x) - 1, i = 0, palindromo = 1;
	char aux;
	for (i; i < j; i++, j--) {
		if (x[i] != x[j])
			palindromo = 0;
	}
	return palindromo;
}