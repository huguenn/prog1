void ordenar(intv[],int n)
{
  int i,j,aux;
  for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++) //se hace esto porque tiene que cambiar a como avanzan las comparaciones del burujeo
      if(v[j]>v[j+1])
      {
        aux=v[j];
        v[j]=v[j+1];
        v[j+1]=aux;
      }
}
