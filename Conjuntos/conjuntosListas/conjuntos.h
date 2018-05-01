#ifndef __cONJUNTOS_H
#define __cONJUNTOS_H

#define MAXIMO 16

typedef int tipoElemento;

typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
} tipoCelda;

typedef struct {
	tipoCelda *primero , *ultimo;
	} tipoLista;


typedef tipoLista particion[MAXIMO];
typedef int tipoconjunto;

void crea(particion c);
tipoElemento buscar(tipoElemento x, particion c);
void unir(tipoElemento x, tipoElemento y, particion c);

void verParticion(particion c);
void verClaseEquivalencia(tipoElemento x,particion c);

#endif
