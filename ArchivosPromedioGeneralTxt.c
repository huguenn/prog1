#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LNOM 50
#define MAX 10

struct persona {
  char nombre[LNOM];
  int promedio;
};

int promedios(struct persona alu[]);
void listar(struct persona alu[],int n);
int promedioGeneral(struct persona alu[],int n);
int main(void)
{
  int cant,promgeneral;
  struct persona alu[MAX]; //que es este max?
  cant=promedios(alu);
  listar(alu,cant);
  promgeneral=promedioGeneral(alu,cant);

  printf("\n Promedio General es: %d\n", promgeneral);
  return 0;
}

int promedios(struct persona alu[]) //porque acá no le ponemos nada?
{
  int cant=0,notas,nota;
  char nom[LNOM+1],digit,nombrearchivo[100]; //por si se guardó con enter o salto de LINEA
  printf("Archivo Promedios: ");
  scanf("%s",&nombrearchivo);
  FILE *pf=fopen(nombrearchivo,"rt");
  if(pf==NULL)
  {
    printf("No se encontró el archivo");
    return 1;
  }

  fgets(nom,LNOM,pf);
  while(!feof(pf))
  {
    alu[cant].promedio=0;
    notas=0; //Porque la linea siguiente tiene el *. Porque strchr devuelve un puntero y quiero colocar \0 en la posición de memoria donde me encuentra el caracter en cuestión?
    *strchr(nom,'\n')='\0'; //esto lo hago por si quiero una vez guardado poder controlar como se muestra
    strcpy(alu[cant].nombre,nom);
    while(fscanf(pf,"%d",&nota)==1) //magia: intenta mostrar un numero por el %d, si es nota devuelve la cantidad de caracteres que encontró, en este caso 1, sino devuelve 0
    {
      notas++;
      alu[cant].promedio=alu[cant].promedio+nota;
    }
    alu[cant].promedio=alu[cant].promedio/notas;
    fgets(nom,LNOM+1,pf);
    cant++;
  }
  fclose(pf);
  return cant;
}

int promedioGeneral(struct persona alu[],int n)
{
  int acumulador,promedio;
  for (int i = 0; i < n; ++i)
  {
  acumulador=alu[i].promedio+promedio;
  i++;
  }
  promedio=acumulador/n;
  return promedio;
}

void listar(struct persona alu[], int n)
{
  for(int i=0;i<n;++1)
  {
    printf("%s\n", l[i].nombre);
    printf("%d\n", l[i].promedio);
  }
}




  //leer el archivo
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  #include <string.h>
  #include<stdlib.h>
  #define LNOM 15
  #define MAX 10
  struct persona{
  	char nombre[LNOM];
  	int promedio;
  };
  int leerArchTxt(struct persona alu[]);
  void listar (struct persona l[],int n);
  int main (void)
  {
  	int cant;
  	struct persona alu[MAX];
  	cant=leerArchTxt(alu);
  	listar(alu,cant);
  	return  0;
  }

  int leerArchTxt(struct persona alu[])
  {
    int cant=0,notas,nota;
    char nom[LNOM+1],digit;//este +1 lo hace por que si se guardo con el enter o salto de linea
    FILE *pf=fopen("lista.txt","rt");
    if(pf==NULL)
    {
      printf("No se puede abrir el archivo \n");
      return 0;//return cant;
    }
    fgets(nom,LNOM,pf);
    while(!feof(pf))
    {
    	alu[cant].promedio=0;
    	notas=0;
      *strchr(nom,'\n')='\0';//esto lo hago por si quiero una vez guardado imprimir todo en una linea
      strcpy(alu[cant].nombre,nom);
      //printf("%d\n",fgetc(pf));
      while(fscanf(pf,"%d",&nota)==1)
      {
      	//printf("%d\n",pf);
      	notas++;
      	alu[cant].promedio=alu[cant].promedio+nota;

      }
      alu[cant].promedio=alu[cant].promedio/notas;
     /* fgets(alu[cant].tel,LTEL,pf);
      *strchr(alu[cant].tel,'\n')='\o';
      fscanf(pf,"%d",&alu[cant].dni);
      fgetc(pf); /* saco enter de arch
      fscanf(pf,"%d/%d/%d",&alu[cant].nacim.d,&alu[cant].nacim.m,&alu[cant].nacim.a):
      fgetc(pf);//saco enter del archivo*/
      fgets(nom,LNOM+1,pf);
      cant++;
    }
    fclose(pf);
    return cant;
  }

  void listar (struct persona l[],int n)
  {
  	for (int i = 0; i < n; ++i)
  	{
  		printf("%s\n", l[i].nombre);
  		printf("%d\n", l[i].promedio);
  	}
  }
