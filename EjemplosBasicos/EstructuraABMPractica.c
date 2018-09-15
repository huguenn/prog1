#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define


struct fecha
{
		int dia,mes,anio;
}

struct productos
{
	char descripcion [MAX];
	int codigo, stockActual, stockMinimo;
	struct fecha ultCompra;
}

void altaProducto(struct producto prod);
void mostrar(struct producto prod,int n);
int main() {
	int cantprod;
	srand((unsigned int)time(NULL));
	struct productos prod[MAX];
	cantprod=altaProductos(prod):
	mostrar(prod,cantprod);
	return 0;
}


int altaProductos(struct productos *prod) //prod es un puntero a la estructura
{
	int i=0;
printf("Ingrese descripción: ");
scanf("%s", &prod[i].descripcion);
	while((prod[i].descripcion!='\n')&&(i<MAX))
	{
		printf("Ingrese Stock Minimo: ");
		scanf("%d", &prod[i].stockMinimo);
		printf("Ingrese Stock Actual: ");
		scanf("%d", &prod[i].stockActual);
		printf("Ingrese Codigo: ");
		scanf("%d", &prod[i].codigo);
		printf("Ingrese Fecha ultima Compra: ");
		scanf("%02d/%02d/%4d", &prod[i].ultCompra.dia,&prod[i].ultCompra.mes,&prod[i].ultCompra.anio);
		i++;

		printf("Ingrese descripción: ");
		scanf("%s", &prod[i].descripcion);
	}
	return i;
}

void mostrar(struct producto *prod, int n)
{
	int i;
	for(i=0;i<=n;++i)
	{
		int codigo, stockActual, stockMinimo;
		struct fecha ultCompra;
		printf("Descripcion: %s\n", prod[i].descripcion);
		printf("Codigo %d\n", prod[i].codigo);
		printf("stockMinimo %d\n", prod[i].stockMinimo);
		printf("stockActual %d\n", prod[i].stockActual);
		printf("ultCompra %d/%d/%d\n", prod[i].ultCompra.dia,prod[i].ultCompra.mes,prod[i].ultCompra.anio);
		printf("\n");
	}
}
