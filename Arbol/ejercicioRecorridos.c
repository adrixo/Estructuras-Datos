#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbol.h"

int main(void)
{
  Arbol varArbol;

/* Creación arbol */
  varArbol = creaNodo('A');
  varArbol->izq=creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq=creaNodo('D');
  varArbol->izq->der=creaNodo('E');
  varArbol->der->izq=creaNodo('F');
  varArbol->der->der=creaNodo('G');

  printf("Recorrido PRE_ORDEN:\t");
  preOrden(varArbol);
  printf("\n");
  printf("Recorrido en ORDEN:\t");
  enOrden(varArbol);
  printf("\n");
  printf("Recorrido POST_ORDEN:\t");
  postOrden(varArbol);
  printf("\n");
  printf("Recorrido en AMPLITUD:\t");
  amplitud(varArbol);
  printf("\n");

  return 1;
}
