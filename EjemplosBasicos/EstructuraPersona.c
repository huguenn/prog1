/* VM alta baja y modificaciones de datos
Agenda
Lista socios
*/

#include <stdio.h>
#include <stdio.h>
#define MAX 100
#define ALTA  1
#define BAJA  2
#define MODIF 3
#define LISTA 4
#define SALIR 5
#define LNOM  32
#define LTEL  16


struct fecha
{
  int d,m,a;
};
struct persona
{
  char nombre[LNOM];
  char tel[LTEL]; //no utilizar variables numericas.
  int dni;
  struct fecha nacim;
};

/* Prototipos */

int main (void)
{
  struct persona alu[MAX]; //Alu es un vector porque tiene los [] de MAX elementos
  int cant=0 // lleva registro de cuantas personas están en el vector
  int cant=0,opcion;

      while((opcion=menu())!=SALIR) //llama a menu se fija si es distinto de opción y si no es sigue. Se usa asi para no olvidarnos de ponerlo al final del while
//los parentesis hacen que el compilador no se queje por el = ya que es de asignación cuando estamos haciendo comparaciones
    {
      switch(opcion)
      {
        case ALTA: //Esto es gracias al define que se hizo al principio. Es para que sea mas claro
                  cant=altas(alu,cant); //va a pedir todos los datos y un enter da como finalizada la carga. Le paso el vector en cual cargar. además le decimos la cantidad que tenemos con cant. La  funcin altas devuelve cant
                  ordenar(alu,cant); //para ordenar el vector
                  break; //para parar el case
        case BAJA:
                  cant=bajas(alu,cant); //bajas no desordena
                  break;
        case MODIF:
                  modifica(alu,cant);
                  ordenar(alu,cant);
                  break;
        case LISTA:
                  listar(alu,cant);

      }
    }
    return 0;
}

int menu(void)
{
  int opc;
  do {
    printf("1.Altas\n");
    printf("2.Bajas\n");
    printf("3.Modificaciones\n");
    printf("4.Listas\n");
    printf("5.Salir\n");
    printf("Opción: ");
    scanf("%d",&opc); sacarEnterCola(); // se saca en el enter del buffer de teclado
  }
  while(opc<ALTA||opc>SALIR);
  return opc;
}

void sacarEnterCola(void)
{
    while(fgetc(stdin)!='\n');
    ;
}

int buscar(struct persona l[], int desde, int hasta, char busc[])
{
    while(desde<hasta && strstr(l[desde].nombre,busc)==NULL)
        desde++;
    return desde<hasta?desde:-1; //si desde hasta es verdadero devuelve desde sino devuelve -1
}

int bajas(struct persona l[],int cant)
{
    char nom[LNOM]; int opc,j,desde;
    ingresarCadena(nom,LNOM,"Nom buscado: ");
    while(cant>=0&&strlen(nom)>0)
    {
        desde=buscar(l,0,cant,nom);
        while(desde!=-1)
        {
            printf("%s: ",l[desde].nom);
            printf("Desea darlo de baja? (S/N) ");
        }
    }
}



int bajas (struct persona l[], int cant)
{
	int opc,j,desde;
	char nom[LNOM];
	ingresarCadena(nom,LNOM,"Nom: ");
	while (cant>=0&&strlen(nom)>0)
	{
		desde=buscar (l,0,cant,nom);
		while(desde !=-1)
		{
			printf("%s"l[desde].nom);
			printf("desea darle la baja?(S/N)\n");
			scanf("%d",&opc);
			sacarEnterCola();
			if(toupper(opc)=='S')
			{
				cant--;
				for (j=desde;j<cant;j++)
					l[j]=l[j+1];
			}
			else
			{
				desde=buscar(l,desde+1,cant,nom);
			}
		}
		ingresarCadena(nom,LNOM,"Nom: ");
	}
	return cant;
}



void ordenar(struct persona l[], int n)
{
	int ordenado = 0, i = 0, j;
	struct persona aux;
	while (!ordenado) //mientras no este ordenado
	{
		ordenado = 1; //cambio el flag para salir del while si no hay que hacer cambios
		for (j = 0; j < n - 1 - i; j++) // n-1 por burbujeo ya que compara en 5 elementos vs 4. y se le resta i ya que al llegar al fondo el ordenamiento no toca más al más grande.
			if (strcmp(l[j].nombre, l[j + 1].nombre) > 0)
			{
				ordenado = 0; //cambia flag ya que hay cambios
				aux = l[j]; //guardo en auxiliar
				l[j] = l[j + 1]; //guardo en l (en indice j)
				l[j + 1] = aux; //guardo en l con j indice + 1
			}
		i++; //aumento el i para cumplir con lo comentado en for.
	}
}

int altas (struct persona l[], int cant)
{
  char nom[LNOM];
  ingresarCadena(num,LNOM,"Nonmbre: ");
  while(cant <MAX && strlen(nom)>0)
  {
    strcpy(l[cant].nombre,nom);
    ingresarCadena(f[cant].tel,LTEL,"TE: ");
    printf("DNI: ");
    scanf("%d", &l[cant].dni);sacarEnterCola();
    print("Fecha nac(d/m/a)");
    scanf("%d/%d/%d", &l[cant].nacim.d,&l[cant].nacim.m,&l[cant].nacim.a);
    fgetc(stdin);
    cant++;
    if(cant<MAX)
      ingresarCadena(nom,LNOM,"Nom: ");
    }
    return cant;
}

int ingresarCadena(char cad[],int tam,char mensaje[])
{
	int i;
	printf("%s",mensaje );
	fgets (cad,tam,stdin);
	i=0;
	while (cad[i]!='\n'&& cad[i] !='\0')
	i++;
	if (cad[i]=='\0')
		while(fgetc(stdin)!='\n');
	else
		cad[i]='\0';
	return i;
}
