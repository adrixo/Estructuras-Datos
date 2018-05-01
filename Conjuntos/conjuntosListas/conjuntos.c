#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

/* cada clase de equivalencia es una lista enlazada que contiene sus elementos */
void crea(particion c){
	int i;

	for(i = 0; i<MAXIMO; i++){
		c[i].primero = (tipoCelda *) calloc (1, sizeof(tipoCelda));
		c[i].ultimo = c[i].primero;
		c[i].primero->sig = NULL;
		c[i].primero->elemento = i;
	}
}

tipoElemento buscar(tipoElemento x, particion c){
	int i;
	tipoCelda * aux;

	for(i = 0; i < MAXIMO; i++){
		aux = c[i].primero;

		while(aux!=NULL){
			if(aux->elemento == x)
				return i;
			else
				aux = aux->sig;
		}
	}
	return -1;
}

void unir(tipoElemento x, tipoElemento y, particion c){
	if(x != -1 && y != -1 && x != y){
		c[x].ultimo->sig = c[y].primero;
		c[x].ultimo = c[y].ultimo;
		c[y].primero = c[y].ultimo = NULL;
	}
}

//funciones auxiliares
void verParticion(particion c)
{
	int i;
  tipoCelda *aux;

  for (i =0;i<MAXIMO;i++) {
     	aux = c[i].primero;

      if (aux!=NULL)
			 	printf("\nClase de equivalencia representante %d: ",i);

	    while (aux!=NULL)
      {
				printf("%d ",aux->elemento);
        aux=aux->sig;
      }
  }
}

void verClaseEquivalencia(tipoElemento x,particion c)
{
	int representante;
  tipoCelda *aux;

    representante = buscar(x,c);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);
    aux = c[representante].primero;
    while (aux)
        {
					printf(" %d ",aux->elemento);
          aux=aux->sig;
        }
    printf("\n\n");
}
