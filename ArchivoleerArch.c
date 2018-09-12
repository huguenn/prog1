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
