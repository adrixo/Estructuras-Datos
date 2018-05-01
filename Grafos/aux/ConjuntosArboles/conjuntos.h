#ifndef __CONJUNTOS_A_H
#define __CONJUNTOS_A_H

#define MAXCONJUNTOS 100

typedef int particion[MAXCONJUNTOS];
typedef int tipoConjunto;
typedef int tipoElementoConjunto;

void crea(particion C);
tipoElementoConjunto buscar(tipoElementoConjunto x, particion C);
void unir(tipoElementoConjunto x, tipoElementoConjunto y, particion C);

void verParticion(particion C);
#endif
