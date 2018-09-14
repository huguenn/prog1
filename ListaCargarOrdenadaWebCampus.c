#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//constantes
#define LNOM 32
//estructuras
struct n{
	char nombre[LNOM];
	struct n *pSig;
};
typedef struct n nodo, *pNodo;

//prototipos
int ingresarCadena(char cad[],int tam, char mensaje[]);
pNodo vaciarLista(pNodo inicio);
void imprimirLista(pNodo inicio);
pNodo insertarOrd(pNodo inicio, pNodo nuevo);

//main
int main(void)
{
	char nombre[LNOM];
	pNodo inicio,nuevo,liberar, actual; //actual una copia de inicio para no perder la lista.
	inicio=NULL;
	//cargarLista
	ingresarCadena(nombre,LNOM,"Nombre: ");
	while(strlen(nombre)>0){//para salir si ingresan un Enter.
		nuevo=(pNodo)malloc(sizeof(nodo));	 //malloc debo castearlo porque que tiene por defecto un void*, como ya definimos *pNodo,
		if(nuevo==NULL)						 //es por ello que arriba no hace falta el *, de no haber definido typedef *pNodo tendria que poner *nodo.
		{
			printf("No hay memoria disponible.\n");
			nombre[0]='\0';
		}
		else
		{
			strcpy(nuevo->nombre,nombre);
			nuevo->pSig=inicio;
			//inicio=nuevo;
			inicio=insertarOrd(inicio,nuevo);
			ingresarCadena(nombre,LNOM,"Nombre: ");
		}
	}
	//imprimir la lista:
		//actual=inicio; //me hago una copia de inicio en actual para no perderla.
		//while(actual!=NULL) //mientras la lista no sea vacia
		//{
		//	printf("%s\n",actual->nombre);
		//	actual=actual->pSig;
		//}
	imprimirLista(inicio);
	//vaciar la lista:
	inicio=vaciarLista(inicio);
		//while(inicio!=NULL)
		//{
		//	liberar=inicio;//lo copio dentro del while porque me sirve para tener la referencia del siguiente, sino no puedo avanzar
		//	inicio=inicio->pSig;
		//	free(liberar);
		//}
	imprimirLista(inicio);


}
//funciones
int ingresarCadena(char cad[],int tam, char mensaje[]){
	printf("%s",mensaje);
	fgets(cad,tam,stdin);
	if(strchr(cad,'\n')){//si el ultimo caracter valido es un '\n' (antes del '\0' (NULL))
		*strchr(cad,'\n')='\0'; //al contenido de '\n' le asignamos '\0' (NULL)
	}else
		while(fgetc(stdin)!='\n'){}
	return strlen(cad);
}

//char nombre para almacenar el ingreso.

//pNodo inicio //sera el 1er nodo de la lista.


//					strcpy((*nuevo).nombre,nombre);
//lo simplifico con	strcpy(nuevo->nombre,nombre)



void imprimirLista(pNodo inicio){
	pNodo actual;
	actual=inicio; //me hago una copia de inicio en actual para no perderla.
	if(actual==NULL){ //lista vacia
		printf("%s","Lista vacia.\n");
	}else{
		while(actual!=NULL) //mientras la lista no sea vacia
		{
			printf("%s\n",actual->nombre);
			actual=actual->pSig;
		}
	}
}

pNodo vaciarLista(pNodo inicio){
	pNodo liberar;
	while(inicio!=NULL)
	{
		liberar=inicio;//lo copio dentro del while porque me sirve para tener la referencia del siguiente, sino no puedo avanzar
		inicio=inicio->pSig;
		free(liberar);
	}
	return NULL;
}


//cuando ya tengo un nuevo nodo que le usuario ha ingresado, podremos usar la siguiente funcion:

pNodo insertarOrd(pNodo inicio, pNodo nuevo){ //para usar la funcion haré: inicio=inserartOrd(inicio, nuevo);
	pNodo act, ant;
	if(inicio==NULL)//si lista vacia.
	{
		nuevo->pSig=NULL;
		inicio=nuevo;
		return inicio;
	}
	if(strcmp(nuevo->nombre, inicio->nombre)<0)	//insertar al inicio
	{
		nuevo->pSig=inicio;
		inicio=nuevo;
		return inicio;
	}
	ant=NULL;
	act=inicio;
	while(act!=NULL && strcmp(act->nombre, nuevo->nombre)<=0)
	{
		ant=act;
		act=act->pSig;
	}
	if(act==NULL)								//insertar al final
	{
		nuevo->pSig=NULL;
		ant->pSig=nuevo;
	}
	else										//inserto entre nodos
	{
		nuevo->pSig=act;
		ant->pSig=nuevo;
	}
	return inicio;
}
