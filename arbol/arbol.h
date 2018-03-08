#ifndef __ARBOL_H
#define __ARBOL_H

typedef char tipoInfo;

typedef struct tipoNodo {
        tipoInfo info;
        struct tipoNodo *izq,*der;
        } tipoNodo;

typedef tipoNodo * Arbol;


Arbol creaNodo(tipoInfo info);


void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitud(Arbol raiz);

void representacionArbolBinario(Arbol raiz);

int altura(Arbol raiz);
int numNodos(Arbol raiz);
Arbol anula(Arbol raiz);
int sustiuye(Arbol raiz, tipoInfo x, tipoInfo y);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);
int similares(Arbol r1,Arbol r2);
int equivalentes(Arbol r1,Arbol r2);
Arbol especular(Arbol raiz);
#endif
