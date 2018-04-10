#ifndef __CONJUNTOS_H
#define __CONJUNTOS_H

#define MAXIMO 16

typedef int tipoElemento;

typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
	} tipoCelda;

typedef struct {
	tipoCelda * primero , *ultimo;
	} tipoLista;


typedef tipoLista particion[MAXIMO];
typedef int tipoConjunto;

void crea(particion C);
tipoElemento buscar(tipoElemento x, particion C);
void unir(tipoElemento x, tipoElemento y, particion C);

void verParticion(particion C);
void verClaseEquivalencia(tipoElemento x,particion P);

#endif
