#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LNOM 32

struct n
{
  char nombre[LNOM];
  struct n* psig;
};

typedef struct n nodo;
typedef nodo * pNodo;

int main(void)
{
  char nombre[LNOM];
  pNodo inicio=NULL,nuevo,liberar,actual;
  ingresarCadena(nombre,LNOM,"texto a guardar (nombre de nodo): ");
  while(strlen(nombre)>0)
  {
    nuevo=(pNodo)malloc(sizeof(nodo));
    if(nuevo==NULL)
    {
      printf("No hay memoria\n");
      nombre[0]='\0';
    }
    else
    {
      strcpy(nuevo->nombre,nombre);
      nuevo->pSig=inicio;
      inicio=nuevo;
      ingresarCadena(nombre,LNOM,"Nombre que quiero para el nodo");
    }

  }
  actual=inicio;
  while(inicio!=NULL)
  {
    printf("%s\n",actual->nombre);
    actual=actual->pSig;
  }
  while(inicio!=NULL)
  {
    liberar=inicio;
    inicio=inicio->pSig;
    free(liberar);
  }
  return 0;
}

pNodo insertarOrdenado(pNodo inicio,pNodo nuevo)
{
  pNodo actual, anterior;
  if (inicio==NULL)
  {
    nuevo->pSig=NULL;
    inicio=nuevo;
    return inicio;
  }
  if (strcmp(nuevo->nombre, inicio->nombre)<0)
  {
    nuevo->pSig=inicio;
    inicio=nuevo;
    return inicio;
  }
  anterior=NULL;
  actual=inicio;
  while(actual!=NULL&& strcmp(actual->nombre,nuevo->nombre)<=0)
  {
    anterior=actual;
    actual=actual->pSig;
  }
  if (actual==NULL)
  {
    nuevo->pSig=NULL;
    anterior->pSig=nuevo;
  }
  else
  {
    nuevo->pSig=actual;
    anterior->pSig=nuevo;
  }
  {
    nuevo->pSig=actual;
    anterior->pSig=nuevo;
  }
  return inicio;
}
