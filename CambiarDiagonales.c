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
  printf("\n");
  intercambiarDiagonal(m);
  mostrar(m);
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

void intercambiarDiagonal(int m[F][C])
{
  int f, c, col,aux;
  for (f = 0; f < F; f++)
  {
    for (c = 0; c < C; c++)
    {
      for(f=0; f<F; f++)
      {
          col = f;
          temp = A[f][col];
          A[f][col] = A[f][(size-col) - 1];
          A[f][(C-col) - 1] = aux;
      }


    }
}
