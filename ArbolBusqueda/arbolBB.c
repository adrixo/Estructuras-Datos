#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"


#ifdef SINREPETIDOS
/* Árboles Binarios de Búsqueda sin calves repetidas */

int insertar(tipoArbolBB *raiz,tipoClave clave)
{
	if (*raiz==NULL){
    *raiz = creaNodo(clave, 1);
		if(*raiz == NULL)
			return -1;
	}

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
	{
		*nodo = NULL;
		return 0;
	}

	else if (clave == raiz->clave)
		*nodo = raiz;

	else if (clave < raiz->clave)
		buscar(clave,raiz->izq,nodo);

	else if (clave > raiz->clave)
		buscar(clave,raiz->der,nodo);

	*nodo = raiz;
  return raiz->info;
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
	return 1;
}
#endif

#ifdef CONREPETIDOS
/* Árboles Binarios de Búsqueda con claves repetidas. */
int insertar(tipoArbolBB *raiz, tipoClave clave, tipoInfo info)
{
  tipoNodo *nuevo, *aux;

  if (*raiz==NULL){
    *raiz = creaNodo(clave, info);
		if(*raiz == NULL)
			return -1;
		return 0;
	}

  else if (clave == (*raiz)->clave)
  {
    nuevo = creaNodo(clave, info);
		if(nuevo == NULL)
			return -1;

    nuevo->izq = (*raiz)->izq;
		(*raiz)->izq = nuevo;
  }

  else if (clave < (*raiz)->clave)
    insertar(&((*raiz)->izq),clave, info);

  else if (clave > (*raiz)->clave)
    insertar(&((*raiz)->der),clave, info);

  return 0;
}


int eliminar(tipoArbolBB *raiz, tipoClave clave)
{
  tipoNodo *aux, *ant;
	int nVeces = 0;

  if (raiz == NULL)
    return 0;

  else if (clave < (*raiz)->clave)
    eliminar(&(*raiz)->izq, clave);

  else if (clave > (*raiz)->clave)
    eliminar(&(*raiz)->der, clave);

  else if (clave == (*raiz)->clave)
  {
    aux = *raiz;

		//while(){

		//}

    if(aux->der == NULL)
      *raiz = aux->izq;

    else if(aux->izq==NULL)
      *raiz = aux->der;

    else //dos hijos
		{
      ant = aux;
      aux = aux->izq;

      while( aux->der != NULL )
      {
        ant = aux;
        aux = aux->der;
      }
      (*raiz)->clave = aux->clave;
			strcpy((*raiz)->info,aux->info);


      if(ant == *raiz)
        ant->izq = aux->izq;

      else
        ant->der = aux->der;
		}
  }

  free(aux);
	return nVeces;
}

#endif
/* Funciones GENERALES adaptadas a los dos ejercicios mediante DIRECTIVAS DE COMPILACIÓN  */
tipoNodo *creaNodo(tipoClave clave, tipoInfo info){

  tipoNodo * nuevo;

  nuevo = (tipoNodo *) malloc(sizeof(tipoNodo));
  if (nuevo == NULL)
	 return NULL;

  nuevo->clave = clave;

	#ifdef SINREPETIDOS
    nuevo->info=info;
	#endif

	#ifdef CONREPETIDOS
    strcpy(nuevo->info,info);
	#endif

	nuevo->izq=NULL;
	nuevo->der=NULL;
  return nuevo;
}

void preOrden(tipoArbolBB a){
  if (a) {

    #ifdef SINREPETIDOS
  	 printf("%d %d \n", a->clave,a->info);
  	#endif

  	#ifdef CONREPETIDOS
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

  #ifdef SINREPETIDOS
	 printf("%d %d \n", a->clave,a->info);
  #endif

  #ifdef CONREPETIDOS
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

 	#ifdef SINREPETIDOS
    printf("%d %d \n", a->clave,a->info);
  #endif

	#ifdef CONREPETIDOS
	 printf("%d %s \n", a->clave,a->info);
  #endif
  }
}
