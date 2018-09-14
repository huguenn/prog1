/* Listas ordenadas

Inisio -> (Lista) -> (Lista) -> (Lista) -> (Lista) \0

donde -> es un puntero
Desventaja es que el acceso es secuencial
Ventaja, flexibilidad de datos.
Es una estructura de pila

El nombre de una función sin parentesis es un puntero a función.

LIFO

Para ingresr datos al principio cambiamos la asignación de listas. Los punteros apuntan uno al valor anterior a comprar.

Pa agregar una lista en la siguiente:

inicio -> (Ana) -> (Ines) -> (Juan) -> (Raul) ->
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LNOM 32
struct n
{
  char nombre[LNOM]; //Nombre por ejemplo Ana
  struct n *pSig; //puntero que es el circulito negro
};

typedef struct n nodo; //
typedef nodo * pNodo; //pNodo es un puntero a nodo

int main(void)
{
  char nombre[LNOM]; //cadena de caracteres nombre que es temporal.
  pNodo inicio=NULL,nuevo,liberar,actual; //inicio es un puntero a nodo y es par que una lista este vacia ese NULL. nuevo es otra de tipo pnodo
  ingresarCadena(nombre,LNOM,"Nom: "); // variable temporal nombre que guarde con LNOM con el cartelito Nom:
  while(strlen(nombre)>0) //mientras la longotud que tiene nombre sea mayor a 0. porque si es un enter solamente ingresar cadena ingresarCadena
{
  nuevo=(pNodo) malloc(sizeof(nodo)); //aca guardo el puntero de donde está la lista
  if(nuevo==NULL)
  {
    printf("no hay memoria\n");
    nombre[0]='\0';
  }
  else
  {
    strcpy(nuevo->nombre,nombre); //copio lo que tiene nuevo a inicio en la primera iteracción. con eso copiamos el valor de nuestra cadena de caracteres.
    //nuevo->pSig=inicio; //lo que tenia en la lista y lo pongo atrás del nuevo
    //inicio=nuevo;
    inicio=insertarOrd(inicio,nuevo);
    ingresarCadena(nombre,LNOM,"Nom: ");
  }
}
actual=inicio;

while(actual!=NULL) /*mientras la lista no sea vacia */
{
  printf("%s\n", actual->nombre);
  actual=actual->pSig;
}
while(inicio!=NULL)
{
  liberar=inicio
  inicio=inicio->pSig;
  free(liberar);
}

pNodo insertarOrd(pNodo inicio,pNodo nuevo)
{
  pNodo act,ant;
  if(inicio==NULL) /*Lista vacia */
  {
    nuevo->pSig=NULL;
    inicio=nuevo; //inicio de la función no el total
    return inicio;
  }
  if(strcmp(nuevo->nombre,inicio->nombre)<0) /* insertar al inicio - Ana es menor que ines */
  {
    nuevo->pSig=inicio; //nuevo pSig
    inicio=nuevo;
    return inicio;
  }
  ant=NULL;
  act=inicio;
  while(act!=NULL&&strcmp(act->nombre,nuevo->nombre)<=0) //nuevo
  {
    ant=act;
    act=act->pSig;
  }
  if(act==NULL) /*insertar al final - encontre el lugar o cai de lista */
  {
    nuevo->pSig=NULL;
    ant->pSig=nuevo;
  }
  else
  {
    nuevo->pSig=act;
    ant->pSig=nuevo;
  }
  return inicio;
}
