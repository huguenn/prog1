#include <stdio.h>
#include <stdlib.h>

void cargarVector(int v[],int cant); //prototipo
void ordenar(int [],int);
void mostrar(int[],int);

//prototipo
int main(void)
{
  //boligatorio decir a que tipo de datos apuntamos
    int *pv,cant; //*pv es un puntero a
    print("Ingresar cantidad de elementos: ");
    scanf("%d",&cant);
    pv=(int *) malloc(cant*sizeof(int)); //cast del puntero.
    if(pv!=NULL)
    {
        cargarVector(pv,cant);
        mostrar(pv,cant);
        ordenar(pv,cant);
        mostrar();
        free(pv);
    }
    else
    {
        print("Insuf memoria\n");
    }
    return 0;
  }
