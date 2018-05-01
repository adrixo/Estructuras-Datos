#ifndef GRAFOS_H
#define GRAFOS_H

#define N 10
#define INF 999999 //check later

typedef struct tagarco{
  int v;
  int peso;
  struct tagarco *sig;
} arco;

typedef arco *pArco;

typedef struct{
  int alcanzado;
  int gradoEntrada;
  int ordenTop;
  int distancia;
  int peso;
  int anterior;
  pArco lista;
} vertices;

typedef struct {
  vertices directorio[N];
  int orden;
}tipoGrafo;

void verGrafo(tipoGrafo *g);

void liberarListas(tipoGrafo *g);

/* Ejercicio 1*/

void iniciar(tipoGrafo *g);
void profundidad(int v_inicio,tipoGrafo *grafo);
void profundidadMejorado(int v_inicio, tipoGrafo * grafo);
void amplitud(int v_inicio,tipoGrafo *grafo);
void amplitudMejorado(int v_inicio,tipoGrafo * grafo);

/* Ejercicio 2*/

int buscarVerticeGradoCeroNoOrdenTop(tipoGrafo *grafo);
int ordenTopologicoSimple(tipoGrafo *grafo);
int ordenTopologico(tipoGrafo *grafo);

/* Caminos mínimos en grafos dirigidos */
/* NO Ponderados */

void caminosBasico(int vInicio, tipoGrafo *grafo);
void caminos(int vInicio, tipoGrafo *grafo);

/* PONDERADOS */
int buscarVerticeDistanciaMinimaNoAlcanzado(tipoGrafo *grafo);
void dijkstraBasico(int vInicio, tipoGrafo *grafo);
void dijkstra(int vInicio, tipoGrafo *grafo);

int costeyTrayectoria(int vIni, int vFin, tipoGrafo *grafo);
void todosCaminosMin(int vIni, tipoGrafo *grafo);

/* Árbol de Expansión en grafos NO dirigidos */
/* Prim */
int buscarVerticeCostoMinimoNoAlcanzado(tipoGrafo * grafo);
tipoGrafo *crearArbolDeExpansion(tipoGrafo *grafo);
tipoGrafo * primBasico(tipoGrafo *grafo);
tipoGrafo * prim(tipoGrafo *grafo);

/* Kruskal*/
tipoGrafo * kruskal(tipoGrafo *grafo);

#endif
