#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUP 99
#define INF 10
#define TAM 100
void cargar(int[],int);
void mostrar(int[],int);
int  main(void)
{
  int v[TAM];
  srand((unsigned int)time(NULL)); //puntero nulo porque necesita un puntero a un valor, aunque sea nulo
  cargar(v,TAM);
  mostrar(v,TAM);
  return 0;
}

void cargar(int v[], int c)
{
  int i;
  for(i=0;i<c;i++)
  v[i]=rand()%(SUP-INF+1)+INF;
}

void mostrar(int v[],int c)
{
  int i;
  for(i=0;i<c;i++)
  printf("%4d",v[i]);
}
