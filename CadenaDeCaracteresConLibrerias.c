#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUP 99
#define INF 10
#define tam 10
void ingresarCadena(char,int,char);


void ingresarCadena(char cad[],int tam,char mensaje[])
{
  printf("%s",mensaje);
  fgets(cad,tam,stdin);
  if(cad[strlen(cad)-2]=='\n') //posicion longitud d ela cadena menos uno y sin incluir el null
    *strchr(cad,'\n')='\o'; //buscamos el caracter en la cadeja con el * se pone el contenido que es donde se pone el null  con la variable de asingacion =. Esto es porque strlen devuelve un puntero
  else
    while(fgets(stdin)!='\n')
    ;
  return strlen(cad);
}
