#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "../Cola/cola.h"


// Reserva de memoria para un nuevo nodo de árbol binario
Arbol creaNodo(tipoInfo info) {
  tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  { 	nuevo->info=info;
    	nuevo->izq=NULL;
    	nuevo->der=NULL;
    	return nuevo;
   }
}

//
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{
  if (raiz!=NULL)
  { printf(" %c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}

void enOrden(Arbol raiz)
{
  if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf(" %c ",raiz->info);
    enOrden(raiz->der);
  }
}

void postOrden(Arbol raiz)
{
  if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf(" %c ",raiz->info);
  }
}

void amplitud(Arbol raiz)
{
    Cola c;
    Arbol nodo;

    colaCreaVacia(&c);

    nodo = raiz;
    c.frente = NULL;
    c.fondo = NULL;

    if (raiz != NULL)
        colaInserta(&c,nodo);

    while (!colaVacia(&c))
    {
        nodo = (Arbol) colaSuprime(&c);
        printf(" %c ", nodo->info);
        if (nodo->izq != NULL) colaInserta(&c,nodo->izq);
        if (nodo->der != NULL) colaInserta(&c,nodo->der);
    }
}

//
// Operaciones Arbol Binario
//

int altura(Arbol raiz)
{

	if (raiz == NULL)
		return -1;

	int alturaIzq, alturaDer;
  alturaIzq = altura(raiz->izq);
	alturaDer = altura(raiz->der);

	if ( alturaIzq > alturaDer )
		return alturaIzq + 1;
	else
		return alturaDer + 1;
}

int numNodos(Arbol raiz)
{
	int nodosIzq = numNodos(raiz->izq);
	int nodosDer = numNodos(raiz->der);

	return nodosIzq + nodosDer + 1;
}

Arbol anula(Arbol raiz)
{
	if(raiz == NULL)
		return NULL;

	raiz->izq = anula(raiz->izq);
	raiz->der = anula(raiz->der);

	free(raiz);
	return NULL;
}

int sustiuye(Arbol raiz, tipoInfo x, tipoInfo y)
{
	if(raiz == NULL)
		return 0;

	int cambios = 0;

	cambios += sustiuye(raiz->izq, x, y);
	cambios += sustiuye(raiz->der, x, y);

	if(raiz->info == x)
	{
		raiz->info = y;
		return cambios + 1;
	}

	return cambios;
}

int numNodosHoja(Arbol raiz)
{
	if(raiz == NULL)
		return 0;

	if(raiz->izq == NULL && raiz->der == NULL)
		return 1;

	int total = 0;

	total += numNodosHoja(raiz->izq);
	total += numNodosHoja(raiz->der);

	return total;
}

int numNodosInternos(Arbol raiz)
{

	if(raiz == NULL)
		return 0;

	int total = 0;

	total += numNodosInternos(raiz->izq);
	total += numNodosInternos(raiz->der);

	if(raiz->izq != NULL || raiz->der != NULL)
		return total += 1;

	return total;
}

int numHijoUnico(Arbol raiz)
{
	if(raiz == NULL)
		return 0;

	int total = 0;

	total += numHijoUnico(raiz->izq);
	total += numHijoUnico(raiz->der);

	if(	raiz->izq != NULL && raiz->der == NULL ||
		raiz->izq == NULL && raiz->der != NULL)
			return total += 1;

	return total;
}

Arbol buscarMax(Arbol raiz)
{

	if(raiz == NULL)
		return NULL;

	Arbol nodoIzq, nodoDer;

	nodoIzq = buscarMax(raiz->izq);
	nodoDer = buscarMax(raiz->der);

	if( nodoIzq !=NULL && raiz->info < nodoIzq->info ){
		raiz = nodoIzq;
	}

	if( nodoDer !=NULL && raiz->info < nodoDer->info ){
		raiz = nodoDer;
	}

	return raiz;

}

Arbol buscarMin(Arbol raiz)
{
	if(raiz == NULL)
		return NULL;

	Arbol nodoIzq, nodoDer;

	nodoIzq = buscarMax(raiz->izq);
	nodoDer = buscarMax(raiz->der);

	if( nodoIzq!=NULL && raiz->info > nodoIzq->info ){
		raiz = nodoIzq;
	}

	if( nodoDer!=NULL && raiz->info > nodoDer->info ){
		raiz = nodoDer;
	}

	return raiz;
}

int similares(Arbol r1,Arbol r2)
{
	if(r1 == NULL && r2 == NULL)
		return 1;

	if(r1 != NULL && r2 != NULL){
		return (
				similares (r1->izq,r2->izq) &&
				similares (r1->der,r2->der));
	}

	return 0;
}

int equivalentes(Arbol r1,Arbol r2)
{
	if(r1 == NULL && r2 == NULL)
		return 1;

	if ((r1 != NULL && r2 != NULL)){
		return (
				r1->info == r2->info &&
				equivalentes (r1->izq,r2->izq) &&
				equivalentes (r1->der,r2->der)
			);
	}

	return 0;
}

Arbol especular(Arbol raiz)
{
	if(raiz == NULL)
		return NULL;

	Arbol nuevoNodo = creaNodo(raiz->info);

	nuevoNodo->der = especular(raiz->izq);
	nuevoNodo->izq = especular(raiz->der);

	return nuevoNodo;
}
