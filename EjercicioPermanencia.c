#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int permanencia(int a, int b, int c, int d);
int main(void)
{
	int Hentrada, Mentrada, Hsalida, Msalida, hora, minutos;
	printf("Ingrese hora de entrada\n");
	scanf("%d:%d", &Hentrada, &Mentrada);
	printf("Ingrese hora de salida\n");
	scanf("%d:%d", &Hsalida, &Msalida);
	permanencia(Hentrada, Mentrada, Hsalida, Msalida);
	hora = permanencia(Hentrada, Mentrada, Hsalida, Msalida) / 60;
	minutos = permanencia(Hentrada, Mentrada, Hsalida, Msalida) % 60;
	printf("La persona estuvo presente durante %02d:%02d\n",hora, minutos);
	return 0;
}

int permanencia(int a, int b, int c, int d) // convertir todo a minutos, ojo que pueden ser 2 días consecutivos
{
	{
		int tiempo;
		tiempo = 1440 - (a * 60 + b) + (c * 60 + d);
		return tiempo;
	}

}
