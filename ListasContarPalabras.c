#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findKey(char,char,int);

int main (void){
  char nombrearchivo[50];

  printf("Ingresar nombre archivo: ");
  scanf("%s",&nombrearhivo);
  findKey(nombrearchivo,)
}

int findKey(char *in, char *key, int buf){
int count = 0;
FILE *f;
f = fopen(in,"r");
char temp[buf];
while(fgets(temp,buf,f) != NULL){
    char *p = temp;
    while((p=(strstr(p,key)))!= NULL){
        count++;
        ++p;
    }
}
fclose(f);
return count;
}
