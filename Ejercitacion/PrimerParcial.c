#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX 100

struct fecha
{
    int dia,mes,anio;
};

struct productos
{
	char descripcion [MAX];
	int codigo, stockActual, stockMinimo;
	struct fecha ultCompra;
};

int altaProducto(struct productos l[]);
//void mostrar(struct productos prod,int n);
void mostrar(struct productos l[],int n);
int main() {
	int cantprod=0;
	//srand((unsigned int)time(NULL));
	struct productos prod[MAX];
        printf("Main Alta producto\n");
	cantprod=altaProducto(prod);
        printf("Main Mostrar producto\n");
	mostrar(prod,cantprod);
	return 0;
}


int altaProducto(struct productos l[MAX])
{
int i=0;
printf("Ingrese descripción: ");
fgets(l[i].descripcion,MAX,stdin);

	while(strlen(l[i].descripcion)>1)
	{
        printf("Ingrese Stock Minimo: ");
        scanf("%d", &l[i].stockMinimo);
        printf("Ingrese Stock Actual: ");
        scanf("%d", &l[i].stockActual);
        printf("Ingrese Codigo: \n");
        scanf("%d", &l[i].codigo);
        printf("Ingrese Fecha ultima Compra: ");
        scanf("%02d/%02d/%4d", &l[i].ultCompra.dia,&l[i].ultCompra.mes,&l[i].ultCompra.anio);
        fgetc(stdin);
        printf("\n");
        i++;

        printf("Ingrese descripción: ");
        fgets(l[i].descripcion,MAX,stdin);

        }
	return i;
}

void mostrar(struct productos l[],int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		int codigo, stockActual, stockMinimo;
		struct fecha ultCompra;
		printf("Descripcion: %s\n", l[i].descripcion);
		printf("Codigo %d\n", l[i].codigo);
		printf("stockMinimo %d\n", l[i].stockMinimo);
		printf("stockActual %d\n", l[i].stockActual);
		printf("ultCompra %d/%d/%d\n", l[i].ultCompra.dia,l[i].ultCompra.mes,l[i].ultCompra.anio);
		printf("\n");

                if(l[i].stockActual<l[i].stockMinimo)
                {
                    printf("Stock Faltante de %d \n",(l[i].stockMinimo-l[i].stockActual));
                }
	}
}
