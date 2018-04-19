#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbolBB.h"

int main(void)
{ tipoArbolBB a=NULL;

 insertar(&a,25,"para");
 insertar(&a,35,"la");
 insertar(&a,15,"las");
 insertar(&a,20,"prácticas");
 insertar(&a,12,"necesario");
 insertar(&a,13,"implementar");
 insertar(&a,15,"(comprendiendo");
 insertar(&a,15,"la");
 insertar(&a,15,"abstracción)");
 insertar(&a,45,"teoría");
 insertar(&a,30,"entender");
 insertar(&a,10,"es");
 printf("Secuencia de los nodos en orden: \n");
 enOrden(a);
 printf("Eliminados %d nodos con clave %d\n", eliminar(&a,5),5);
 printf("Eliminados %d nodos con clave %d\n", eliminar(&a,15),15);
 printf("Eliminados %d nodos con clave %d\n", eliminar(&a,35),35);
 printf("Secuencia de los nodos en orden: \n");
 enOrden(a);
 return 1;
}


