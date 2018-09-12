int ingresarCadena(char cad[],int tam, char mensaje[]) //cambiamos de void a int
{

  printf("%s",mensaje);
  fgets(cad,tam,stdin);
  i=0;
  while(cad[i]!='\n'&&cad[i]!='\o') //posicion 0 d ela cadena y hacemos mientras esto pase
    i++
  if(cad[i]!='\o') //
    while(fgetc(stdin)!='\n')
    ;//Esto es necesario para leer el buffer del teclado  ir vaciandolo
    else
      cad[i]='\o' //se supone que lo que nos sacó del while es el \n entonces se reemplaza el \n con un null para borrarlo.
      return i; // aca devolveriamos el final de la cadena
}
