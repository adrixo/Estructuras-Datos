
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"

int pilaCreaVacia(Pila *p)
{
	*p = (Pila) malloc(sizeof(*p));

	if(*p == NULL){
		printf("Error crear pila\n");
		return -1;
	}

	(*p)->elemento = NULL;
	(*p)->sig = NULL;

	return 0;
}

int pilaVacia(Pila *p)
{
	if( (*p)->sig == NULL ){
		return 1;
	}
	return 0;
}

int pilaInserta(Pila *p,tipoElementoPila elemento)
{
	Pila nuevaCelda;

	nuevaCelda = (Pila) malloc(sizeof(Pila*));

	if(nuevaCelda==NULL){
		printf("Error crear nodo insertar");
		return -1;
	}

	nuevaCelda->sig = *p;
	nuevaCelda->elemento = elemento;
	*p = nuevaCelda;

	return 0;

}

tipoElementoPila pilaSuprime(Pila *p)
{
	tipoElementoPila temp;

	Pila suprimido;

	if(pilaVacia(p)){
		printf("Error pila vacia\n");
		return NULL;
	}

	temp = (*p)->elemento;
	suprimido = (*p);
	*p = (*p)->sig;
	free(suprimido);

	return temp;
}
