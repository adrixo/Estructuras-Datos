#include "conjuntos.h"
#include <stdio.h>

/*
#define MAXIMO 16
typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;
*/


void crea(particion C){
	int i=0;

	for( i=0; i<MAXIMO; i++ ){
		C[i] = -1;
	}
}

tipoElemento buscar(tipoElemento x, particion C){

	while(C[x]!=-1){
			x = C[x];
	}

	return x;
}

void unir(tipoElemento x, tipoElemento y, particion C){
	C[x] = y;
}




//Funciones auxiliares
void verParticion(particion C)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",C[i]);
    printf("| contenido del vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices \n\n");
}

void verClaseEquivalencia(tipoElemento x,particion C)
{ int representante,i;
  representante = buscar(x,C);
  printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
  for (i=0;i<MAXIMO;i++) if (C[i]==representante) printf("%d ",i);
  printf("\n");

}
