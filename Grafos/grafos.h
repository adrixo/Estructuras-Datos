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
void amplitud(int v_inicio,tipoGrafo *grafo);

/* Ejercicio 2*/

int ordenTop1(tipoGrafo *grafo);
int ordenTop2(tipoGrafo *grafo);

/* Ejercicio 3: Caminos mínimos en grafos dirigidos */
/* a) NO Ponderados */

void caminos1(int vInicio, tipoGrafo *g);
void caminos2(int vInicio, tipoGrafo *g);

/* b) PONDERADOS */
void dijkstra1(int vInicio, tipoGrafo *g);
void dijkstra2(int vInicio, tipoGrafo *g);

/* Interpretación de los algoritmos ¡Secuencia de vértices en caminos mínimos y distancias !!! */

int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g); // Un camino!!
void todosCaminosMin(int vIni, tipoGrafo *g);		 // Todos!!

/* Ejercicio 4: Árbol de Expansión en grafos NO dirigidos */
/* a) Prim  ¡ Algoritmo e interpretación del resultado!!! */
tipoGrafo * prim1(tipoGrafo *grafo);
tipoGrafo * prim2(tipoGrafo *grafo);
/* c) Kruskal*/
tipoGrafo * kruskal(tipoGrafo *grafo);

#endif
