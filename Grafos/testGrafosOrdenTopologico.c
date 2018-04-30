#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"


tipoGrafo *creaGrafoT28();


int main(void)
{
  tipoGrafo *gT28;
  int ciclico;

	gT28 = creaGrafoT28();
	verGrafo(gT28);
  printf("\nProfundidad desde 1: ");
  profundidadMejorado(1,gT28);

	//iniciar(gT28);
  printf("\nProfundidad desde 6: ");
  profundidadMejorado(6,gT28);

	//iniciar(gT28);
 	printf("\nAmplitud : ");
 	amplitudMejorado(1,gT28);

	printf("\nAmplitud : ");
	amplitudMejorado(6,gT28);

	verGrafo(gT28);

  ciclico = ordenTopologico(gT28);
	if (ciclico==-1)
    printf("\nGrafo ciclico ¡ No es posible la ordenación topológica !");

	verGrafo(gT28);
//	liberarListas(g);
//	free(g);
}
/********************************************************/
/* Creación del grafo de la figura 1 (transparecnia 28)
/********************************************************/
tipoGrafo *creaGrafoT28()
{
  int i;
  pArco  p;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));



  // Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 2;
  p->peso = 5;
  g->directorio[1].lista=p;
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 3;
  p->peso = 4;
  g->directorio[1].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 4;
  p->peso = 2;
  g->directorio[1].lista->sig->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 4;
  p->peso = 1;
  g->directorio[2].lista=p;
  p= (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 5;
  p->peso = 17;
  g->directorio[2].lista->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 6;
  p->peso = 4;
  g->directorio[3].lista=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 3;
  p->peso = 2;
  g->directorio[4].lista=p;
  p= (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 6;
  p->peso = 1;
  g->directorio[4].lista->sig=p;
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 7;
  p->peso = 2;
  g->directorio[4].lista->sig->sig=p;

  p->sig=NULL;
// Lista de adyacencia del vértice 5
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 4;
  p->peso = 17;
  g->directorio[5].lista=p;
  p= (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 7;
  p->peso = 15;
  g->directorio[5].lista->sig=p;
  p->sig=NULL;
// Lista de adyacencia del vértice 6
  g->directorio[6].lista=NULL;
// Lista de adyacencia del vértice 7
  p = (arco *)calloc(1,sizeof(arco));// if (!p) liberarListas(g);		Buenas prácticas de programación II
  p->v = 6;
  p->peso = 1;
  g->directorio[7].lista=p;
  p->sig=NULL;

  g->orden=7;


  return g;
  }
