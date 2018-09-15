#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LPAT 10
#define LLOC 100
struct n{
	char patente[LPAT];
	int horauno,minuno,horados,mindos;
	char localidad[LLOC];
	int nlocal;
	struct n *psig;
};
typedef struct n nodo;
typedef nodo *pnodo;
pnodo armarlista(pnodo inicio, pnodo nuevo);
pnodo abrirArch(pnodo inicio ,pnodo nuevo);
void listar(pnodo inicio);

int main (void)
{
	pnodo inicio=NULL,nuevo=NULL;

	inicio=abrirArch(inicio,nuevo);
	listar(inicio);
	return 0;
}

pnodo abrirArch(pnodo inicio ,pnodo nuevo)
{
	FILE *pf=fopen("patente.txt","rt");
	  char pat[LPAT+1];
	  if(pf==NULL)
	  {
	    printf("No se puede abrir el archivo \n");
	    return 0;//return cant;
	  }
	  fgets(pat,LPAT,pf);
	  while(!feof(pf))
	  {
	  	nuevo=(pnodo)malloc(sizeof(nodo));
	    *strchr(pat,'\n')='\0';
	    strcpy(nuevo->patente,pat);
	    fscanf(pf,"%d:%d",&nuevo->horauno,&nuevo->minuno);
	    fgetc(pf);
	    fgets(nuevo->localidad,LLOC,pf);
	    fscanf(pf,"%d",&nuevo->nlocal);
	    fgetc(pf);
	    inicio=armarlista(inicio,nuevo);
	    fgets(pat,LPAT,pf);
	  }
	  printf("aca\n");
	  fclose(pf);
	  return inicio;
}
pnodo armarlista(pnodo inicio, pnodo nuevo)
{
	nuevo->psig=inicio;
	inicio=nuevo;
	return inicio;
}
void listar(pnodo inicio){

	while(inicio!=NULL)
	{
		printf("patente: %s\n",inicio->patente);
		inicio=inicio->psig;
	}

}


int Buscar(pnodo inicio,char patente)
{
  while(inicio!=NULL)
  {
    
  }
}
