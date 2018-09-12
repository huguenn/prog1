//tenemos un archivo con la palabra hola
#include <stdio.h>

int main(void)
{
  FILE * pf; //File es una estructura que usa el sistema para manejarse con archivos
  int c;
  pf=fopen("Saludo.txt","rt") //fopen devuelve un puntero. Se abre como lectura y como texto
  if(pf!=NULL) //comparamos con un puntero NULL, porque es un puntero.
  {
    c=fgetc(pf); //guardamos lo que nos da fgetc. pf es un puntero a FILE y guarda el enterno en c que es ese puntero
    while(!feof(pf)) //Esto solo funciona cuando yo leo el end of file, y eso sucede cuando se hace el fgetc.
    {
      printf("%c", (char) c); //se pone la c para que imprima el caracter y no el codugo del mismo.
      c=fgetc(pf);
    }
    fclose(pf);
  }
  else
  {
    printf("No se pudo abrir el archivo \n");
    return 1;
  }
  return 0;
}
