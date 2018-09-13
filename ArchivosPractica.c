#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NOTAS 50
#define ARCHIVO "Origen.txt"

typedef enum {FALSO,VERDADERO} boolean;

bool EsNumero(char);
bool EsSeparador(char);


int main(void)
{
  FILE *pf;
  int notas[NOTAS], promedio, total;
  pf=fopen(ARCHIVO, "rt");
  if (pf == NULL)
  {
    printf("No se puede abrir el archivo");
    return 1;
  }

  c[i]=fgets(pf);
  
}
