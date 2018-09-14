/*
Realizar una función que reciba una cadena y coloque en mayúscula la primera letra siguiente a un espacio
eliminando dichos espacios. Escribir un programa que permita verificar su funcionamiento. Ejemplo:
Cadena original:
Platero es pequeño, peludo, suave; tan blando por fuera, que se diría todo de algodón, que no lleva huesos. Sólo los espejos de azabache
de sus ojos son duros cual dos escarabajos de cristal negro.
Cadena final:
PlateroEsPequeño,Peludo,Suave;TanBlandoPorFuera,QueSeDiríaTodoDeAlgodón,QueNoLlevaHuesos.SóloLosEspejosDeAzabacheDeSu
sOjosSonDurosCualDosEscarabajosDeCristalNegro.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int funcion(char[]);

void main() {
	char cad[]  = "Platero es pequeno, peludo, suave; tan blando por fuera, que se diria todo de algodon, que no lleva huesos. Solo los espejos de azabache de sus ojos son duros cual dos escarabajos de cristal negro.";
	printf("Cadena original: %s\n", cad);
	funcion(cad);
	printf("\nCadena modificada: %s\n", cad);
}

int funcion(char x[]) {
	int aux = 0, len = strlen(x) - 1;
	for (int i = 0; i < len; i++){
		if (x[i] == ' ') {
			x[i] = toupper(x[i + 1]);
			aux = 1;
		}
		if (aux) {
			for (int j = i; j < len; j++) {
				x[j+1] = x[j + 2];
			}
			aux = 0;
		}
	}
}