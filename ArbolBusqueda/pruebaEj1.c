#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbolBB.h"

int main(void)
{ tipoArbolBB a=NULL;
  tipoNodo *buscado;
  int encontrado;

 insertar(&a,25);
 insertar(&a,35);
 insertar(&a,15);
 insertar(&a,20);
 insertar(&a,12);
 insertar(&a,13);
 insertar(&a,15);
 insertar(&a,15);
 insertar(&a,15);
 insertar(&a,45);
 insertar(&a,30);
 insertar(&a,10);
 printf("Secuencia de los nodos en orden: \n");
 enOrden(a);
 encontrado = buscar(15,a, &buscado); 
 if (encontrado)
	printf("\nEncontrado nodo con clave %d e información %d \n", buscado->clave,buscado->info);
 else  printf("No existe nodo o error (%d) \n", encontrado);

 encontrado = buscar(100,a, &buscado); 
 if (encontrado)
	printf("\nEncontrado nodo con clave %d e información %d \n", buscado->clave,buscado->info);
 else  printf("No existe nodo o error(%d) \n", encontrado);


 return 1;
}


