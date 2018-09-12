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

int main(void)
{
  struct presona alu[MAX];
  int cant,opc;
    cant=leerArch();
  while((opc=menu())!=SALIR)
  {
    switch(opc)



  }
  guardarArchivo(alu,cant);
  return 0;
}


/*
La logica de esto es enviar a fseek al final y preguntar con ftell donde está.
*/
long int filesize(FILE*pf) //recibe un puntero a FILE
{
	long int posicionactual, posicionfinal; //Long INT por que esto va a devolver eso el ftell (devuelve long int)
	posicionactual = ftell(pf); //me dice a donde esta el indicador del archivo (que posición)
	fseek(pf,0L,seekend); //función que permite mover la posición dentro del archivo, le tengo que decir cuantos lugares me quiero mover y respecto de quien. Se permite mover al comienzo, posición actual o al final (byte que le sigue a lo último escrito). Se puede usar seekend, seekcur o seekset. La "L" es por ser LONG INT.
	posicionfinal = ftell(pf); //le pregunto la posición actual que es la final, ahora tnego inicio y fin.
	fseek(pf, posicionactual, seekset); //lo vuelvo a mover al inicio, lo muevo hacia el inicio desde "poisicionesactuales
	return posicionfinal;
}



int leerArch(struct persona alu[])
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
void guardarArchivos(struct persona alu[], int cant)
{
	FILE *pf;
	*pf = fopen("lista.dat", "wb"); //abro el archivo lista.dat donde voy a escribir (para guardarlo) y es binario por el .dat
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
