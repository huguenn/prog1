//suponemos que queremos ingresar una fecha desde teclado
#include <stdio.h>
int main(void)
{
  struct fecha hoy;
  printf("Fecha (dd/mm/aaaa): ");
  scanf("%d"/"%d"/"%d", &hoy.dia, &hoy.mes, &hoy.ano); //se pone el & para que sepa en que dirección guardarlo
  printf("%02d/%02d/%4d",hoy.dia,hoy.mes,hoy.ano,);// no se pone el 0 para que no haga 0018
  return 0;
}
