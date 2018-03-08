// Adrián Valera roman 17 - 2 - 2018

#ifndef __PILA_H
#define __PILA_H

#include "../arbol/arbol.h"

typedef tipoNodo* tipoElemento;


typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
typedef tipoCelda * Pila;

int pilaCreaVacia(Pila *p);


// En vacía no sería necesario el paso por referencia
// pero por mantener la misma interfaz con la implementación
// de matrices
int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);


#endif
