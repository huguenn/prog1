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