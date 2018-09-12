#include <stdio.h>
#include <stdlib.h>
#define SUP 999
#define INF 100
#define FIL 4
#define COL 5

void cargar(int matriz[FIL][COL]);
void mostrar(int matriz[FIL][COL]);
int main (void)
{
  int matriz[FIL][COL];
  cargar(matriz);
  mostrar(matriz);
  return 0;
}

void cargar(int matriz[FIL][COL])
{
  int f,c;
  for (f=0;f<FIL;f++)
    for (c=0;c<COL;c++)
      matriz[f][c]=rand()%(SUP-INF+1)+INF;
}

void mostrar(int m[FIL][COL])
{
  int f, c;
  for (f=0;f<FIL;f++)
  {
    for(c=0;c<COL;c++)
      printf("%4d", m[f][c]);
    printf("\n");
  }
}
