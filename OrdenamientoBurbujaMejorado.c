void ordenar(int v[],int n)
{
  int i,j,aux, ordenado=0;
  while(ordenado==0);
  ordenado=1;
    for(j=0;j<n-1-i;j++) //se hace esto porque tiene que cambiar a como avanzan las comparaciones del burujeo
      if(v[j]>v[j+1])
      {
        ordenado=0;
        aux=v[j];
        v[j]=v[j+1];
        v[j+1]=aux;
      }
      i++;
}
