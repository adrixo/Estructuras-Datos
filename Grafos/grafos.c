#include <stdio.h>
#include "../Cola/cola.h"
#include "grafos.h"

void verGrafo(tipoGrafo *g) {

  int i;
  pArco p;

  printf("\nGrafo  (Orden %d)\n\n",g->orden);
  printf("       alc gEnt oTop dist peso ant \n");
  printf("     +----+----+----+----+----+----+\n");

  for(i=1;i<=g->orden;i++){
    printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
          g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);

    if (g->directorio[i].distancia == INF)
      printf("  * |");
    else
      printf(" %2d |", g->directorio[i].distancia);

    if (g->directorio[i].peso == INF)
      printf("  * |");
    else
      printf(" %2d |", g->directorio[i].peso);

    printf(" %2d |",g->directorio[i].anterior);
    p = g->directorio[i].lista;

    while (p != NULL){
      printf(" ->%2d", p->v);	// Grafos no ponderados
      //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
      p = p->sig;
    }
    printf("\n");
  }
  printf("     +----+----+----+----+----+----+\n\n");
}

void liberarListas(tipoGrafo *g){

}

void iniciar(tipoGrafo *g){

}

void profundidad(int v_inicio,tipoGrafo * grafo){
  int w;
  pArco  p;

  printf("%d ",v_inicio);

  grafo->directorio[v_inicio].alcanzado=1;
  p = grafo->directorio[v_inicio].lista;

  while (p!=NULL){
    w=p->v;
    if (!grafo->directorio[w].alcanzado)
      profundidad(w,grafo);
    p = p->sig;
  }
}

void amplitud(int v_inicio,tipoGrafo *grafo){
  int w;
  pArco  p;
  Cola c;

  colaCreaVacia(&c);
  colaInserta(&c,v_inicio);

  while (!colaVacia(&c)){
	   w =colaSuprime(&c);
     if (!grafo->directorio[w].alcanzado){
       printf("%d ",w);

       grafo->directorio[w].alcanzado=1;
       p =grafo->directorio[w].lista;

       while (p!=NULL){
         w = p->v;
         colaInserta(&c,w);
         p = p->sig;
       }
     }
  }
}
