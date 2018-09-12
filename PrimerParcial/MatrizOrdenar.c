//Cargar y mostrar una matriz de 3 digitos (que no es lo mismo a 3 números) con numeros generados al azar
#define _CRT_SECURE_NO_WARNINGS
#define C 5
#define F 4
#define SUP 999 // Para srand
#define INF 100 // para srand
void cargar(int m[F][C]);
void mostrar(int m[F][C]);
void orden(int m[F][C]);
void mostrarorden(int m[F][C]);
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int m[F][C];
	srand((unsigned int)time(NULL));
	cargar(m);
	mostrar(m);
	orden(m);
	printf("\n");
	mostrar(m);
	system("pause");
	return 0;
}

void cargar(int m[F][C])
{
	int f, c; //Declaro mis variables para la carga de la matriz
	for (f = 0; f < F; f++)
	{
		for (c = 0; c < C; c++)
		{
			m[f][c] = rand() % (SUP - INF + 1) + INF; //cargo la fórmula para los rand, se suma el INF para que no arranque en cero
		}
	}
}


void mostrar(int m[F][C])
{
	int f, c;
	for (f = 0; f < F; f++)
	{
		for (c = 0; c < C; c++)
		{
			printf(" %4d", m[f][c]);
		}
			printf("\n");

	}
}

void orden(int m[F][C])
{
	int f, c, aux, ordenado;
	ordenado = 0;
	while (!ordenado)
	{
		ordenado = 1;
		for (c = 0; c < C-1; c++)
		{
			if (m[0][c] > m[0][c + 1])
			{
				{
					for (f = 0; f < F; f++)
					{
						aux = m[f][c];
						m[f][c] = m[f][c + 1];
						m[f][c + 1] = aux;
						ordenado = 0;
					}
				}
			}
		}

	}

}
