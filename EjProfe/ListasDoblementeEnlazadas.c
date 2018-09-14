typedef struct
{
  char onmbre[LNOM];
  char domicilio[LDOM];
  char telefono[LTEL];
  int legajo;
  fecha nacim;

}datos;

typedef struct n
{
  datos;
  struct n* pSig;
}nodo,* pNodo;
