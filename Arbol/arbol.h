#ifndef __ARBOL_H
#define __ARBOL_H

typedef char tipoInfo;

typedef struct tipoNodo {
        tipoInfo info;
        struct tipoNodo *izq,*der;
        } tipoNodo;

typedef tipoNodo * Arbol;

//Recorridos
void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitud(Arbol raiz);

//Calculo
int altura(Arbol raiz);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
int numNodos(Arbol raiz);

//Operaciones
Arbol creaNodo(tipoInfo info);
Arbol anula(Arbol raiz);
int sustituye(Arbol raiz, tipoInfo x, tipoInfo y);

//Busqueda
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);

//Estructuras
int similares(Arbol r1,Arbol r2);
int equivalentes(Arbol r1,Arbol r2);
Arbol especular(Arbol raiz);
#endif
