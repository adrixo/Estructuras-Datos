#ifndef __CONJUNTOS_A_H
#define __CONJUNTOS_A_H

#define MAXIMO 16

typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;

void crea(particion C);
tipoElemento buscar(tipoElemento x, particion C);
void unir(tipoElemento x, tipoElemento y, particion C);
void unirTamanno(tipoElemento x, tipoElemento y, particion c);

void buscarComprensionCaminos(int x, particion c)

void verParticion(particion C);
#endif
