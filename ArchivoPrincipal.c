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
int fileSize(FILE *pf)
{
  long int posAct,posFin;
  postAct=ftell(pf); //ftell devuevle un long int
  fseek(pf,0L,SEEKEND);
  posFin=ftell(pf);
  fseek(pf,postAct,SEEKSET);
  return posFin;
}



int leerArch(struct persona alu[])
{
  FILE *pf=fopen("Lista.dat","rb");
  int cant=0; //si no puede abrirlo o hay algun problema que el programa sepa que no pudo mediante un 0
  if(pf)
  {
    cant=filesize(pf)/sizeof(struct persona); //con esto saco la cantidad de registros
    fread(alu,sizeof(struct persona),cant,pf); //
    fclose(pf);
  }
  else
  {
    print("Error\n")
  }
  return cant;
}

void guardarArchivo(struct persona alu[], int cant)
{
  FILE *pf=fopen("Lista.dat", "wb"); //Puntero a file. Lo de binario acá es obligatorio
  if(pf)// si puedo abrir el archivo lo que quiero hacer es guardar los datos
  {
    fwrite(alu,sizeof(struct persona),cant,pf);//lleva 4 parametros. 1 donde están los datos. fwrite espera dirección de memoria. Alu es el nombre de un vector, que es su dirección. & no va. Copia directamente el registro del size of y lo copia en el destino (memoria o disco, en este caso como es write es de memoria al disco)
    fclose(pf);
  }
  else
  {
    print("No se pudo abrir el archivo\n");
  }
}
