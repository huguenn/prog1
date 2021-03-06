/*
sizeof(struct persona) es un tipo de dato y es lo importante a la hora de copiar los datos de memoria. Esto es lo que se pone a la hora del size of.
sizeof(struct persona alu[]) seria el tamaño de un puntero
Leer Arch
para leer el archivo hay que
fileSize
fseek mueve desde y hasta donde yo quiero pero tengo que tener cuidado de no pasarme del fin del archivo ni del principio.
parametros
*primer parametro para quien
*cuanto me quiero mover
*SEEKSET||SEEKCUR||SEEKEND en seek set se pueden poner numeros positivos y en end negativos, porque nos movemos del inicio para adelante en el caso de seekset y del fin para atras en el caso de
seek end. Si ponemos un valor positivo en seekend nos pasariamos del archivo y está mal.
Ejemplo
fseek(pf,oL,SEEKEND);
L
*/
// structuras abm de estructuras
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define ALTA 1
#define BAJA 2
#define MODIF 3
#define LISTA 4
#define SALIR 5
#define LNOM 32
#define LTEL 16

struct fecha
{
	int d,m,a;
};

struct persona
{
	char nombre [LNOM];
	char tel [LTEL];
	int dni;
	struct fecha nacim;
};

int menu();
int altas (struct persona l[], int cant);
int ingresarCadena(char cad[],int tam,char mensaje[]);
int buscar(struct persona l[], int desde, int hasta, char busc[]);
int bajas (struct persona l[], int cant);
void ordenar(struct persona l[], int n);
void sacarEnterCola(void);
void listar (struct persona l[],int n);
void modificar (struct persona l[], int n);
void remplazar(struct persona l[],int cant,int pos,char nom[]);
void guardararchivos(struct persona alu[], int cant);
long int filesize(FILE*pf);
int leerarchivos(struct persona alu[]);

int main (void)
{
	struct persona alu[MAX];
	int cant=0, opcion;

	while ((opcion =menu())!=SALIR)
	{
		switch (opcion)
		{
			case ALTA:
			//printf("hola entraste\n");
			cant=altas(alu,cant);
			guardararchivos(alu,cant);
			ordenar(alu,cant);
			break;
			case BAJA:
			cant=bajas(alu,cant);// bajas no desordena por que se mueve todo uno para arriba.
			break;
			case MODIF:
			modificar(alu,cant);
			ordenar(alu,cant);// si hace falta
			break;
			case LISTA:
			listar(alu,cant);
			break;
		}
	}
	return 0;
}

/*int menu(void)
{
	int opc;
		printf("1_Alta\n2_Baja\n3_Modif\n4_Listar\n5_Salir\n");
		scanf("%d",&opc);//siempre hay que sacar la cola del teclado
		fgetc("")
		printf("\n");
	return opc;
}*/
int menu(void)
{
  int opc;
  do {
    printf("1.Altas\n");
    printf("2.Bajas\n");
    printf("3.Modificaciones\n");
    printf("4.Listas\n");
    printf("5.Salir\n");
    printf("Opcion: ");
    scanf("%d",&opc); sacarEnterCola(); // se saca en el enter del buffer de teclado
  }
  while(opc<ALTA||opc>SALIR);
  return opc;
}
int altas (struct persona l[], int cant)
{
  char nom[LNOM];
  ingresarCadena(nom,LNOM,"Nombre: ");
  while(cant <MAX && strlen(nom)>0)
  {
    strcpy(l[cant].nombre,nom);
    ingresarCadena(l[cant].tel,LTEL,"TE: ");
    printf("DNI: ");
    scanf("%d", &l[cant].dni);sacarEnterCola();
    printf("Fecha nac(d/m/a)");
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
int buscar(struct persona l[], int desde, int hasta, char busc[])
{
    while(desde<hasta && strstr(l[desde].nombre,busc)==NULL)
        desde++;
    return desde<hasta?desde:-1; //si desde hasta es verdadero devuelve desde sino devuelve -1
}
int bajas(struct persona l[], int cant)
{
	int j, desde;
	char nom[LNOM], opc;
	ingresarCadena(nom, LNOM, "Nom: ");
	while (cant > 0 && strlen(nom) > 0)
	{
		desde = buscar(l, 0, cant, nom);
		while (desde != -1 && desde < cant)
		{
			printf("%s", l[desde].nombre);
			printf("desea darle la baja?(S/N)\n");
			scanf("%c", &opc);
			sacarEnterCola();
			if (toupper(opc) == 'S')
			{
				cant--;
				for (j = desde; j < cant; j++)
					l[j] = l[j + 1];
				desde = buscar(l, desde, cant, nom);
			}
			else
			{
				desde = buscar(l, desde + 1, cant, nom);
			}
		}
		ingresarCadena(nom, LNOM, "Nom: ");
	}
	return cant;
}
void ordenar(struct persona l[], int n)
{
    int ordenado=0,i=0,j;
    struct persona aux;
    while(!ordenado)
    {
        ordenado=1;
        for(j=0;j<n-1-i;j++)
            if(strcmp(l[j].nombre,l[j+1].nombre)>0)
            {
                ordenado=0;
                aux=l[j];
                l[j]=l[j+1];
                l[j+1]=aux;
            }
        i++;
    }
}
void sacarEnterCola(void)
{
    while(fgetc(stdin)!='\n');
}
void listar (struct persona l[],int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%s\n", l[i].nombre);
		printf("%s\n", l[i].tel);
		printf("%d\n", l[i].dni);
		printf("%d/%d/%d\n", l[i].nacim.d,l[i].nacim.m,l[i].nacim.a);

	}
}
void modificar (struct persona l[], int n)
{
	int esta;
	char nom[LNOM];
  	ingresarCadena(nom,LNOM,"Nombre: ");
	esta=buscar(l, 0, n, nom);
	if (esta!=-1)
	{
		remplazar(l,n,esta,nom);
	}
	else
	{
		printf("el nombre no se encuentra\n");
	}
}

void remplazar(struct persona l[],int cant,int pos,char nom[])
{

    strcpy(l[pos].nombre,nom);
    ingresarCadena(l[pos].tel,LTEL,"TE: ");
    printf("DNI: ");
    scanf("%d", &l[pos].dni);sacarEnterCola();
    printf("Fecha nac(d/m/a)");
    scanf("%d/%d/%d", &l[pos].nacim.d,&l[pos].nacim.m,&l[pos].nacim.a);
    printf("se remplazo correctamente");

    fgetc(stdin);
}
void guardararchivos(struct persona alu[], int cant)
{
	FILE *pf;
	pf = fopen("lista.dat", "wb"); //abro el archivo lista.dat donde voy a escribir (para guardarlo) y es binario por el .dat
	if (pf) //Si pude abrir el archivo quiere decir esto. Si pude, voy a guardar mis datos en el archivo.
	{
		fwrite(alu, sizeof(struct persona), cant, pf); //le paso: donde esta la info a guardar(le paso el vector, es decir, la dirección del vector, le paso el tamaño, para eso uso SIZEOF, le paso la cantidad de registros que los saco de CANT Y por último el archivo pf
		fclose(pf); //Cierro el archivo
	}
	else
	{
		printf("No se pudo abrir el archivo\n");
	}
}

int leerarchivos(struct persona alu[])
{
	FILE * pf = fopen("Lista.dat", "rb"); // inicializo y abro mi archivo
	int cant = 0; //variable para guardar la cantidad de registros.  Lo inicializa en cero, por que si no pude abrir el archivo, va a devolver cero
	if (pf) //esto pregunta SI PUDE ABRIR EL ARCHIVO
	{
		cant = filesize(pf) / sizeof(struct persona); //esto da la cantidad de registros que hay.
		fread(alu, sizeof(struct persona), cant, pf); //primer parametro la dirección deonde lo guardo (el vector), el tamaño de la estructura el segundo, la cantidad de registros y el archivo
		fclose(pf);
	}
	else
	{
		printf("No se pudo leer el archivo\n");
	}
	return cant;
}

long int filesize(FILE*pf) //recibe un puntero a FILE
{
	long int posicionactual, posicionfinal; //Long INT por que esto va a devolver eso el ftell (devuelve long int)
	posicionactual = ftell(pf); //me dice a donde esta el indicador del archivo (que posición)
	fseek(pf,0L,SEEK_END); //función que permite mover la posición dentro del archivo, le tengo que decir cuantos lugares me quiero mover y respecto de quien. Se permite mover al comienzo, posición actual o al final (byte que le sigue a lo último escrito). Se puede usar seekend, seekcur o seekset. La "L" es por ser LONG INT.
	posicionfinal = ftell(pf); //le pregunto la posición actual que es la final, ahora tnego inicio y fin.
	fseek(pf, posicionactual, SEEK_SET); //lo vuelvo a mover al inicio, lo muevo hacia el inicio desde "poisicionesactuales
	return posicionfinal;
}
