/*
 * ejercicio4.c		Prueba del algoritmo de Prim y Kruskal
 *
 *  Created on: 19/04/2016
 *      Author: MJ Polo
 */

#include <stdlib.h>
#include "grafos.h"


tipoGrafo *creaGrafoT57();

int main(void)
{
  tipoGrafo *grafoT57, *arbolExp;

  int i;

  grafoT57 = creaGrafoT57();
  verGrafo(grafoT57);
  //arbolExp=prim?(grafoT57);
  arbolExp=kruskal(grafoT57);
  verGrafo(arbolExp);
}

/************************************************************************/
/* Creación del grafo ponderado NO DIRIGIDO de la  1a transparencia 57  */
/************************************************************************/

tipoGrafo *creaGrafoT57()
{
  int i;
  pArco  p;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

  g->orden = 7;

// Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 2;
	  p->peso = 2;
	  g->directorio[1].lista=p;
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 3;
	  p->peso = 4;
	  g->directorio[1].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 4;
	  p->peso = 1;
	  g->directorio[1].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 1;
	  p->peso = 2;
	  g->directorio[2].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 4;
	  p->peso = 3;
	  g->directorio[2].lista->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 5;
	  p->peso = 10;
	  g->directorio[2].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 1;
	  p->peso = 4;
	  g->directorio[3].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 4;
	  p->peso = 2;
	  g->directorio[3].lista->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 6;
	  p->peso = 5;
	  g->directorio[3].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 1;
	  p->peso = 1;
	  g->directorio[4].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 2;
	  p->peso = 3;
	  g->directorio[4].lista->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 3;
	  p->peso = 2;
	  g->directorio[4].lista->sig->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 5;
	  p->peso = 7;
	  g->directorio[4].lista->sig->sig->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 6;
	  p->peso = 8;
	  g->directorio[4].lista->sig->sig->sig->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 7;
	  p->peso = 4;
	  g->directorio[4].lista->sig->sig->sig->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 5
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 2;
	  p->peso = 10;
	  g->directorio[5].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 4;
	  p->peso = 7;
	  g->directorio[5].lista->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 7;
	  p->peso = 6;
	  g->directorio[5].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 6
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 3;
	  p->peso = 5;
	  g->directorio[6].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 4;
	  p->peso = 8;
	  g->directorio[6].lista->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 7;
	  p->peso = 1;
	  g->directorio[6].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 7
  p = (arco *)calloc(1,sizeof(arco));
	  p->v = 4;
	  p->peso = 4;
	  g->directorio[7].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 5;
	  p->peso = 6;
	  g->directorio[7].lista->sig=p;
  p= (arco *)calloc(1,sizeof(arco));
	  p->v = 6;
	  p->peso = 1;
	  g->directorio[7].lista->sig->sig=p;
  p->sig=NULL;

  return g;
  }
