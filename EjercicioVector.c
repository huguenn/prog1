#include <stdin.h>
#define TAM 10

void cargar()
void mostrat()
int main(void)
{
  int v[TAM];
  cargar(v);
  mostrat(v);
  return 0;
}

void cargar(int v[])
{
  int i;
    for(i=0;i<TAM;i++)
    {
      print("[%d]: ",i+1);
      scanf("%d",&v[i]);
    }
}

void mostrat(int v[])
{
  int i;
  for(i=0;i<TAM;i++)
  printf("%4d\n",v[i]);
  printf("\n");
}
