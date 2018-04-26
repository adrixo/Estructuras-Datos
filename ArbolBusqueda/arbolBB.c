#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"


#ifdef EJERCICIO1
/* Árboles Binarios de Búsqueda sin calves repetidas */

int insertar(tipoArbolBB *raiz,tipoClave clave)
{
	if (*raiz==NULL)
    *raiz = creaNodo(clave, 1);

  else if (clave == (*raiz)->clave)
    ((*raiz)->info)++;

  else if (clave < (*raiz)->clave)
    insertar(&((*raiz)->izq),clave);

  else if (clave > (*raiz)->clave)
    insertar(&((*raiz)->der),clave);

  return 1;
}

int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo)
{
	if (raiz==NULL)
		return NULL;
	else if (clave == raiz->clave)
		*nodo = raiz;
	else if (clave < raiz->clave)
		buscar(clave,raiz->izq,nodo);
	else if (clave > raiz->clave)
		buscar(clave,raiz->der,nodo);
  return 1;
}

int eliminar(tipoArbolBB *raiz, tipoClave clave){
  tipoNodo *aux, *ant;

  if (raiz == NULL)
    return 0;
  else if (clave < (*raiz)->clave)
    eliminar((*raiz)->izq, clave);
  else if (clave > (*raiz)->clave)
    eliminar((*raiz)->der, clave);
  else if (clave == (*raiz)->clave){
    aux = raiz;
    if(aux->der == NULL)
      *raiz = aux->izq;
    else if(aux->izq==NULL)
      *raiz = aux->der;
    else
    { //dos hijos
      ant = aux;
      aux = aux->izq;

      while(aux->der != NULL)
      {
        ant = aux;
        aux = aux->der;
      }

      *raiz = aux;
      if(ant == raiz)
        ant->izq = aux->izq;
      else
        ant->der = aux->der;
    }
  }
  free(aux);
}
#endif

#ifdef EJERCICIO3
/* Árboles Binarios de Búsqueda con claves repetidas. */
int insertar(tipoArbolBB *raiz,tipoClave clave, tipoInfo info)
{
  tipoNodo *nuevo, *aux;

  if (*raiz==NULL)
    *raiz = creaNodo(clave, info);

  else if (clave == (*raiz)->clave)
  {
    nuevo = creaNodo(clave, info);

    nuevo->izq = (*raiz)->izq;
    nuevo->der = (*raiz)->der;

    (*raiz)->der = NULL;
    (*raiz)->izq = nuevo;
  }

  else if (clave < (*raiz)->clave)
    insertar(&((*raiz)->izq),clave);

  else if (clave > (*raiz)->clave)
    insertar(&((*raiz)->der),clave);

  return 0;
}


int eliminar(tipoArbolBB *raiz, tipoClave clave)
{
  tipoNodo aux, ant;

  if (raiz == NULL)
    return 0;

  else if (clave < (*raiz)->clave)
    eliminar((*raiz)->izq, clave);

  else if (clave > (*raiz)->clave)
    eliminar((*raiz)->der, clave);

  else if (clave == (*raiz)->clave)
  {
    aux = raiz;

    if(aux->der == NULL)
      *raiz = aux->izq;

    else if(aux->izq==NULL)
      *raiz = aux->der;

    else //dos hijos
      ant = aux;
      aux = aux->izq;

      while( aux->der == NULL )
      {
        ant = aux;
        aux = aux->der;
      }
      *raiz = aux;

      if(ant == raiz)
        ant->izq = aux->izq;

      else
        ant->der = aux->der;
  }
  free(aux);
}

#endif
/* Funciones GENERALES adaptadas a los dos ejercicios mediante DIRECTIVAS DE COMPILACIÓN  */
tipoNodo *creaNodo(tipoClave clave, tipoInfo info){

  tipoNodo * nuevo;
  nuevo = (tipoNodo *) malloc(sizeof(tipoNodo));
  if (nuevo == NULL)
	 return NULL;
  else
  {
    nuevo->clave = clave;
  	#ifdef EJERCICIO1
      nuevo->info=info;
  	#endif
  	#ifdef EJERCICIO3
      strcpy(nuevo->info,info);
  	#endif
  	nuevo->izq=NULL;
  	nuevo->der=NULL;
    return nuevo;
  }
}

void preOrden(tipoArbolBB a){
  if (a) {
    #ifdef EJERCICIO1
  	 printf("%d %d \n", a->clave,a->info);
  	#endif
  	#ifdef EJERCICIO3
      printf("%d %s \n", a->clave,a->info);
  	#endif
  	preOrden(a->izq);
  	preOrden(a->der);
  }
}

void enOrden(tipoArbolBB a)
{
  if (a) {
	 enOrden(a->izq);
  #ifdef EJERCICIO1
	 printf("%d %d \n", a->clave,a->info);
  #endif

  #ifdef EJERCICIO3
	 printf("%d %s \n", a->clave,a->info);
  #endif

  enOrden(a->der);
  }
}

void posOrden(tipoArbolBB a)
{
  if (a) {
  	enOrden(a->izq);
  enOrden(a->der);
 	#ifdef EJERCICIO1
    printf("%d %d \n", a->clave,a->info);
  #endif

	#ifdef EJERCICIO3
	 printf("%d %s \n", a->clave,a->info);
  #endif
  }
}
