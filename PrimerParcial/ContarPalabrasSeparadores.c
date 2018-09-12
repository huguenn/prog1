/*
Ingresar una frase y contar la cantidad de palabras

Las palabras están separadas por los caracteres: ‘;,;.-’
Se pude usar la declaración de una cadena
Char separadores[ ]=” : , ; espacio . - \’ \” ”;


*/

#define MAX 33
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void quitarespacio(char cad[]);
int capicua (char cad[]);
int main (void)
{
	char frase[] = "cursando la materia prog 1: prueba, prueba 2"; //inicializo la cadena
  char separadores[ ]=”:,;.-\’\””;


	int a;
		a = strlen(frase);
	printf("La frase es %s\n", frase); //imprimo la cadena
	quitarespacio(frase);
	printf("La frase es %s\n", frase); //imprimo la cadena
	if (capicua(frase) == 0)
	{
		printf("No es capicua\n");
	}
	else
	{
		printf("Es capicua\n");
	}
return 0;
}

void quitarespacio(char cad[])
{
	int i, j;
	char cad2[MAX], *p;

		p = strchr(cad, ' '); //busco dirección del espacio
		while (p) //mientras tenga una dirección
		{
			strcpy(cad2, p + 1); //copio en aux la dirección del espacio + 1 en dirección
			*p = '\0';
			strcat(cad, cad2);
			p = strchr(cad, ' ');
		}

}

int capicua (char cad[])
{
            int x,y,z,capicua;
            for(y=0,z=MAX;y<=MAX/2;y++,z--)
            ;
            if(cad[y]==cad[z])
            {
                capicua=1;
            }
            else
            {
                capicua=0;
            }
            return capicua;

}
