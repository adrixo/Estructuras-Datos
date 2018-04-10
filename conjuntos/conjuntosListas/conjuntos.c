#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"



void crea(particion C){
	int i;

	for(i = 0; i<MAXIMO; i++){
		C[i]->primero = (tipoCelda *) malloc (1, sizeof(tipoCelda));
		C[i]->ultimo = C[i]->primero;
		C[i]->primero->elemento = i;
	}
}

tipoElemento buscar(tipoElemento x, particion C){
	int i;
	tipoCelda aux;

	for(i = 0; i<MAXIMO; i++){
		aux = C[i]->primero;

		while(aux!=NULL){
			if(aux->elemento == x)
				return i;
			else
				aux = aux->sig;
		}
	}
}

void unir(tipoElemento x, tipoElemento y, particion C){
	
	tipoElemento claseAUnir = buscar(x,C);
	tipoElemento claseBase = buscar(x,C);
	
	if(claseAUnir == claseBase)
		return;

	C[claseBase]->ultimo->sig = C[claseAUnir]->primero;
	C[claseBase]->ultimo = c[ClaseAUnir]->primero;

	C[claseAUnir]->primero = NULL;
	C[claseAUnir]->ultimo = NULL;

}



//funciones auxiliares
void verParticion(particion C)
{ int i;
   tipoCelda *aux;
    for (i =0;i<MAXIMO;i++) {
         aux = C[i].primero;
         if (aux!=NULL)  printf("\n\nClase equivalencia representante %d: ",i);
        while (aux!=NULL)
        { printf("%d ",aux->elemento);
         aux=aux->sig;
        }
    }
}

void verClaseEquivalencia(tipoElemento x,particion C)
{ int representante;
  tipoCelda *aux;
  
    representante = buscar(x,C);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
    aux = C[representante].primero;
    while (aux)
        { printf(" %d ",aux->elemento);
          aux=aux->sig;
        }
    printf("\n\n");
}


