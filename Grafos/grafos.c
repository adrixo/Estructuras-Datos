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

/*Funcionalidades*/
void liberarListas(tipoGrafo *g){
  pArco aux;
  pArco arcoActual;
  arcoActual = g->directorio[N]->lista;

  for(int i = 0; i<N;i++)){
    if(arcoActual!=NULL)
      while(aux!=NULL){
          aux = arcoActual;
          free(aux);
          arcoActual = arcoActual->sig;
      }
  }
}

void iniciar(tipoGrafo *g){
  
}

/*Recorridos*/
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

/*  */
//int ordenTop1(tipoGrafo *grafo);
//int ordenTop2(tipoGrafo *grafo);

/* Caminos minimos */
//void caminos1(int vInicio, tipoGrafo *g);
//void caminos2(int vInicio, tipoGrafo *g);

/*Caminos ponderados*/
//void dijkstra1(int vInicio, tipoGrafo *g);
//void dijkstra2(int vInicio, tipoGrafo *g);

/*  */
//int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g); // Un camino!!
//void todosCaminosMin(int vIni, tipoGrafo *g);		 // Todos!!

/* prim */
//tipoGrafo * prim1(tipoGrafo *grafo);
//tipoGrafo * prim2(tipoGrafo *grafo);
/* Kruskal */
//tipoGrafo * kruskal(tipoGrafo *grafo);
