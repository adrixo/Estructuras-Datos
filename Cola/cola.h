// Adrián Valera roman 17 - 2 - 2018

#ifndef __COLA_H
#define __COLA_H

#include "../arbol/arbol.h"

typedef tipoNodo* tipoElemento;

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;

typedef struct {
        tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);

// En vacía no sería necesario el paso por referencia
// pero por mantener la misma interfaz con la implementación
// de matrices
int colaVacia(Cola *c);

int colaInsertaC(Cola *c, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

#endif
