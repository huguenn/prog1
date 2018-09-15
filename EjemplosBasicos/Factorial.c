int factorial(int n)
{
  int f=1;
  while(n)
  {
    f=f*(n--);
  }
  return f;
}

int factorialR(int n)
{
  if(n==0)
  {
    return 1;
  }
  return n * factorialR(n-1);
}
