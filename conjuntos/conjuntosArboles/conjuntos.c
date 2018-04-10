#include "conjuntos.h"
#include <stdio.h>

/* Tipos a manejar

typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;

*/

void crea(particion C){

	for(int i = 0; i<MAXIMO; i++){
		C[i] = 0;
	}
}

tipoElemento buscar(tipoElemento x, particion C){

	if(C[x]=0)
		return x;
	else
		return buscar(C[x],C);

}

void unir(tipoElemento x, tipoElemento y, particion C){

	C[y] = x;

}

void verParticion(particion C)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",C[i]);
    printf("| contenido del vector \n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices\n\n");
}
