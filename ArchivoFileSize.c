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
