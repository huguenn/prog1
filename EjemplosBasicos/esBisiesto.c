int esBisiesto(int a)
{
  return ((a%4==0&&a%100!=0)||(a%400==0));
}
int esGregoriano(struct fecha f)
{
  if(f.d>=1&&f.d<=diasMes(f.m,f.a))
    return 1;
  else
    return 0;
}
int diasMes(int m,int a)
{
  static int d.m[]={31,28,31,30,31,30,31,31,30,31,30,31}
  if(m==2&&esBiciesto(a))
    return dm[m-1]+1;
  else
    return dm[m-1];
}
