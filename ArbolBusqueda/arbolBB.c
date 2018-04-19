#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"


#ifdef EJERCICIO1
/******************************************************************
* Árboles Binarios de Búsqueda SIN CLAVES REPETIDAS
* Se incluye un poco de código para mostrar la diferencia entre   *
* insertar (paso por referencia) y buscar                         *
*******************************************************************/

int insertar(tipoArbolBB *raiz,tipoClave clave)
{
  tipoNodo *nuevo;

	if (*raiz==NULL){
    raiz = ;
	}
  else if (clave == (*raiz)->clave){
           insertar(&((*raiz)->izq),clave);
  }
  else if (clave < (*raiz)->clave){
           insertar(&((*raiz)->izq),clave);
  }
  else if (clave > (*raiz)->clave){

  }
}

int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo)
{
  if (raiz==NULL)
    return 0;
  else if (clave == raiz->clave)
    nodo = raiz;
  else if (clave < raiz->clave)
    buscar(clave,raiz->izq,nodo);
	else if (clave > raiz->clave)
    buscar(clave,raiz->der,nodo);
}

#endif

#ifdef EJERCICIO3
/******************************************************
* Árboles Binarios de Búsqueda CON CLAVES REPETIDAS   *
******************************************************/
int insertar(tipoArbolBB *raiz,tipoClave clave, tipoInfo info)
{ tipoNodo *nuevo;

}

int eliminar(tipoArbolBB *raiz, tipoClave clave)
{

}

#endif
/*****************************************************************************************
* Funciones GENERALES adaptadas a los dos ejercicios mediante DIRECTIVAS DE COMPILACIÓN  *
/*****************************************************************************************/
tipoNodo *creaNodo(tipoClave clave, tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  {	nuevo->clave = clave;
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

void preOrden(tipoArbolBB a)
{ if (a) {
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
{ if (a) {
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
{ if (a) {
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
