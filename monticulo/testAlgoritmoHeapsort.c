#include <stdlib.h>
#include "monticulo.h"

int main(void){

  Monticulo m;
  int i,n=10;
  tipoElemento elemento;

  iniciaMonticulo(&m);
  srand(time(NULL));
  m.tamanno=n;

  for (i=1;i<=n;i++)
    m.elemento[i].clave=rand()%100;

  heapsort(&m);
  
  for (i=1;i<=m.tamanno;i++)
    printf("%d ",m.elemento[i].clave);
  printf("\n");
}
