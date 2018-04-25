#include <stdio.h>
#include <stdlib.h>

#ifdef MATRICES
#include "conjuntosMatrices/conjuntos.h"
#endif
#ifdef LISTAS
#include "conjuntosListas/conjuntos.h"
#endif
#ifdef ARBOLES
#include "conjuntosArboles/conjuntos.h"
#endif

int main(){
  particion C;
  int i;
  int aBuscar;

  crea(C);
  printf("Situacion INICIAL: ");
  verParticion(C);

// creamos los siguientes conjuntos:
// {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}
  unir(13,15,C);
  unir(7,0,C);
  unir(7,13,C);

  unir(8,12,C);
  unir(3,8,C);
  unir(2,3,C);

  unir(6,1,C);
  unir(6,4,C);
  unir(11,14,C);
  unir(11,6,C);

  unir(5,10,C);
  unir(9,5,C);

// Mostramos el resultado
  printf("Situacion FINAL:   ");
  verParticion(C);

  printf("Comprobar clase del elemento: ");
  scanf("%d", &aBuscar);
  printf("\n\nEl elemento %d pertenence a la clase de equivalencia con representante %d\n",aBuscar, buscar(aBuscar,C));

  #ifdef LISTAS
    verClaseEquivalencia(aBuscar,C);
  #endif

}
