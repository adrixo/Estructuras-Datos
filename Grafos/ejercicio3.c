#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"


tipoGrafo *creaGrafoT47();


int main(void)
{ tipoGrafo *gT47;
  int ciclico,distancia,vIni,vFin;
  
	gT47 = creaGrafoT47();
	verGrafo(gT47);
  	printf("\nProfundidad: ");
	iniciar(gT47);
  	profundidadMejorado(5,gT47); 	// Se necesita profundidad mejorado!!!
 	printf("\nAmplitud : ");
 	amplitudMejorado(5,gT47);	// Se necesita amplitud mejorado!!
	ciclico = ordenTop2(gT47);
	if (ciclico==-1) printf("\nGrafo ciclico ¡ No es posible la ordenación topológica !");
	verGrafo(gT47);
  	printf("\nDijkstra: ");
  	dijkstra1(1,gT47);
	verGrafo(gT47);
        // Interpretación algoritmo de Dijkstra!!!
	vIni=1;
	vFin=6;
	distancia = costeyTrayectoria(vIni,vFin,gT47); // Debe mostrar la secuencia de vértices en el camino mínimo!!!!
	if (distancia!=INF) printf("Camino de coste %d \n", distancia);	
	else printf("No existe camino de %d a %d \n",vIni,vFin);
	printf("\nCaminos Mínimos desde %d\n",vIni);
	todosCaminosMin(vIni,gT47);	
	printf("\nCaminos Mínimos desde %d\n",vFin);
	dijkstra1(vFin,gT47);	
	todosCaminosMin(vFin,gT47);

//	liberarListas(g);
//	free(g);
}
/************************************************************/
/* Creación del grafo ponderado de la  1 (transparencia 47) */
/************************************************************/
tipoGrafo *creaGrafoT47()
{ int i;
  pArco  p,aux;
  tipoGrafo *g;

  g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

  g->orden=7;

  // Lista de adyacencia del vértice 1
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 2;
  	p->peso = 2;
  	g->directorio[1].lista=p;
  	aux = p;
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	  p->v = 4;
	  p->peso = 1;
	  aux->sig = p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 2
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
  	p->v = 4;
	p->peso = 3;
  	g->directorio[2].lista=p;
	aux = p;
  p= (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
  	p->v = 5;
	p->peso = 10;
	aux->sig = p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 3
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 1;
	p->peso = 4;
	g->directorio[3].lista=p;
	aux = p;
  p= (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 6;
	p->peso = 5;
	aux->sig=p;
  p->sig=NULL;
  // Lista de adyacencia del vértice 4
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 3;
	p->peso = 2;
	g->directorio[4].lista=p;
	aux = p;
  p= (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 5;
	p->peso = 2;
	aux->sig = p;
	aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 6;
	p->peso = 8;
	aux->sig = p;
	aux = aux->sig;
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 7;
	p->peso = 4;
	aux->sig = p;
  p->sig=NULL;
// Lista de adyacencia del vértice 5
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 7;
	p->peso = 6;
	g->directorio[5].lista=p;
	p->sig=NULL;
// Lista de adyacencia del vértice 6
  g->directorio[6].lista=NULL;
// Lista de adyacencia del vértice 7
  p = (arco *)calloc(1,sizeof(arco));	// if (!p) liberarListas(g);		Buenas prácticas de programación II
	p->v = 6;
	p->peso = 1;
	g->directorio[7].lista=p;
  p->sig=NULL;

  return g;
  }

