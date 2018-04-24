// Adrián Valera roman 17 - 2 - 2018

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "colaArbol.h"

int colaCreaVacia(Cola *c)
{
	c = (Cola *)malloc(sizeof(Cola));

   	if(c==NULL){
		printf("Fallo al crear cola.\n");
    		return 1;
	} else {

		c->frente = NULL;
		c->fondo = NULL;

		return 0;
	}
}

int colaVacia(Cola *c)
{
	if( c->frente == NULL && c->fondo ==NULL){
		return 1;
	} else {
		return 0;
	}
}

int colaInserta(Cola *c,tipoElemento elemento)
{

    tipoCelda * nuevaCelda;
    nuevaCelda = (tipoCelda *)malloc(sizeof(tipoCelda));
    if(nuevaCelda == NULL){
		printf("Error crear nodo cola.\n");
    	return 1;
	}
    nuevaCelda->elemento = elemento;
    nuevaCelda->sig = NULL;
    if(colaVacia(c)){
    	c->frente = nuevaCelda;
    	c->fondo = nuevaCelda;
	} else {
		c->fondo->sig = nuevaCelda;
		c->fondo = nuevaCelda;
	}

	return 0;
}

tipoElemento colaSuprime(Cola *c)
{

	tipoCelda * temp;
	tipoElemento elementoSuprimido;

	if(colaVacia(c)){
		printf("Fallo al suprimir en cola.\n");
		return 1;
	}

	temp = c->frente;
	elementoSuprimido = temp->elemento;
	c->frente = c->frente->sig;

	if(c->frente==NULL){
		c->fondo=NULL;
	}

	free(temp);
	return elementoSuprimido;

}
