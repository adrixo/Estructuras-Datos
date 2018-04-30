
#ifndef __PILA_H
#define __PILA_H

typedef int tipoElementoPila;

typedef struct tipoCeldaPila {
	tipoElementoPila elemento;
	struct tipoCeldaPila * sig;
} tipoCeldaPila;

typedef tipoCeldaPila * Pila;

int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElementoPila elemento);

tipoElementoPila pilaSuprime(Pila *p);


#endif
