#ifndef __cONJUNTOS_H
#define __cONJUNTOS_H

#define MAXIMO 16

typedef int tipoElemento;

typedef struct tipocelda {
	tipoElemento elemento;
	struct tipocelda * sig;
	} tipocelda;

typedef struct {
	tipocelda *primero , *ultimo;
	} tipoLista;


typedef tipoLista * particion[MAXIMO];
typedef int tipoconjunto;

void crea(particion c);
tipoElemento buscar(tipoElemento x, particion c);
void unir(tipoElemento x, tipoElemento y, particion c);

void verParticion(particion c);
void verclaseEquivalencia(tipoElemento x,particion c);

#endif
