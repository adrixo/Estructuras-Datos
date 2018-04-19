#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"


tipoGrafo *creaGrafoT28();


int main(void)
{ tipoGrafo *gT28;
  

	gT28 = creaGrafoT28();
	verGrafo(gT28);

	//iniciar(gT28);
  	printf("\nProfundidad: ");
  	profundidad(1,gT28);
	//iniciar(gT28);
  	printf("\nProfundidad: ");
  	profundidadMejorado(6,gT28);
	//iniciar(gT28);
 	printf("\nAmplitud : ");
 	amplitud(1,gT28);
	verGrafo(gT28);



}
/********************************************************/
/* Creación del grafo de la figura 1 (transparecnia 28) */
/********************************************************/
tipoGrafo *creaGrafoT28()
{ int i;
  pArco  p;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

  g->orden=7;

  // Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 2;
  p->peso = 1;
  g->directorio[1].lista=p;
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 3;
  p->peso = 1;
  g->directorio[1].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 4;
  p->peso = 1;
  g->directorio[1].lista->sig->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 4;
  p->peso = 1;
  g->directorio[2].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
  p->v = 5;
  p->peso = 1;
  g->directorio[2].lista->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 6;
  p->peso = 1;
  g->directorio[3].lista=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 3;
  p->peso = 1;
  g->directorio[4].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
  p->v = 6;
  p->peso = 1;
  g->directorio[4].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 7;
  p->peso = 1;
  g->directorio[4].lista->sig->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 5
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 4;
  p->peso = 1;
  g->directorio[5].lista=p;
  p= (arco *)calloc(1,sizeof(arco));
  p->v = 7;
  p->peso = 1;
  g->directorio[5].lista->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 6
  g->directorio[6].lista=NULL;
// Lista de adyacencia del vértice 7
  p = (arco *)calloc(1,sizeof(arco));
  p->v = 6;
  p->peso = 1;
  g->directorio[7].lista=p;
  p->sig=NULL;

  return g;
  }

