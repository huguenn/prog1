#define MAX 33
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void quitarespacio(char cad[]);
int capicua (char cad[]);
int main (void)
{
	char frase[] = "DABA EL ARROZ A LA ZORRA EL ABAD"; //inicializo la cadena
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



   /*
            for (i = 0; i < MAX/2 ; i++)
            {
                    for (j = MAX-1; j > MAX/2; j--)
                    {
                            if (cad[i] != cad[j])
                            {
                                    capicua = 0;
                            }
                            else
                            {
                            capicua = 1;
                            }

                   }
            }
    */
            return capicua;

}        
