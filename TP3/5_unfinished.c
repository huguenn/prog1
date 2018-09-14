/*
Realizar una función que convierta un número entero entre 0 y 999 en un número romano y escribir un
programa que permita verificar su funcionamiento. ¿En qué cambiaría la función si el rango de valores fuese
diferente?
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void romanizar(int);

void main() {
	int num;
	printf("Ingresar numero: ");
	scanf(%d",num);
	romanizar(num);
}

num romanizar(int x) {
	char nro[10];
	for(int i=0;x/1==1;i++){
		if (x>500) {
		x=x-500;
		x[i
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
	printf("Numero romano: %s\n",nro);
}



-----------------------------------------------------------------------------


/*
Realizar una función que convierta un número entero entre 0 y 999 en un número romano y escribir un
programa que permita verificar su funcionamiento. ¿En qué cambiaría la función si el rango de valores fuese
diferente?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int romanizar(int);

void main() {
	int num;
	printf("Ingresar numero: ");
	scanf("%d",num);
	romanizar(num);
}

int romanizar(int x) {
	char nro[10];

	char D[] = { "", "D" };
	char C[] = { "", "C", "CC", "CCC", "CM" };
	char X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	char I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	nro = D[x / 500] + C[(x % 500) / 100] + X[(x % 100) / 10] + I[(x % 10)];
	printf("%s", nro);
}