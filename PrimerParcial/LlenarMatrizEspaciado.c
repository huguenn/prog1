int f,c,cont=1;
for(f=0;f<4,f++)
{
  for(c=0;c<4;c++)
  {
    if(f+c%2==0)
    {
      matriz[f][c]=cont;
      cont=cont++;
    }
  }
}
