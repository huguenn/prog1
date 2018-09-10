#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUP 'z' //comparando con el ejecicio de ran anterior la modificaicones son en esta linea y la siguiente,
#define INF 'a'
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
  printf("%4c",v[i]); //aqui cambiamos el tipo de dato que se muestra que pasaria de d a c de chart
}
