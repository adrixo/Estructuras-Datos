#ifndef __COLA_H
#define __COLA_H


/*Cola preparada para el manejo de árboles/nodos */
#include "../Arbol/arbol.h"
typedef tipoNodo* tipoElemento;

typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
	} tipoCelda;

typedef struct {
        tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);

int colaInsertaC(Cola *c, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

#endif
