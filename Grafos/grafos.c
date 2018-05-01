#include <stdio.h>
#include <stdlib.h>
#include "../Cola/cola.h"
#include "aux/Pila/pila.h"
#include "aux/Monticulo/monticulo.h"
#include "aux/ConjuntosArboles/conjuntos.h"

#include "grafos.h"

void verGrafo(tipoGrafo *g)
{

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

    while (p != NULL)
    {
      printf(" ->%2d", p->v);	// Grafos no ponderados
      //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
      p = p->sig;
    }
    printf("\n");
  }
  printf("     +----+----+----+----+----+----+\n\n");
}

/*Funcionalidades*/
void liberarListas(tipoGrafo *g)
{
  int i;
  pArco aBorrar;
  pArco arcoActual;

  for(i = 0; i<N;i++)
  {
    arcoActual = g->directorio[i].lista;
    g->directorio[i].lista = NULL;

    while(aBorrar!=NULL)
    {
        aBorrar = arcoActual;
        arcoActual = arcoActual->sig;
        free(aBorrar);
    }
  }
}

//Funcion que inicializa el directorio de vértices de un grafos
//gradoEntrada contiene la información sobre las aristas del grafo
void iniciar(tipoGrafo *g){
  int i, j, cont;
  pArco aux;

  for(i=1; i<= g->orden; i++)
  {
    cont = 0;

    for(j=1; j<= g->orden; j++)
    {
      aux = g->directorio[j].lista;
      while (aux != NULL)
      {
        if (aux->v == i)
          cont ++;
        aux = aux->sig;
      }
    }
    g->directorio[i].alcanzado = 0;
    g->directorio[i].gradoEntrada = cont;
    g->directorio[i].ordenTop = 0;
    g->directorio[i].distancia = INF;
    g->directorio[i].peso = INF;
    g->directorio[i].anterior = 0;
  }
}

/*Recorridos*/
void profundidad(int v_inicio,tipoGrafo * grafo)
{
  int w;
  pArco  p;

  printf("%d ",v_inicio);

  grafo->directorio[v_inicio].alcanzado=1;
  p = grafo->directorio[v_inicio].lista;

  while (p!=NULL)
  {
    w=p->v;

    if (!grafo->directorio[w].alcanzado)
      profundidad(w,grafo);
    p = p->sig;
  }
}

void profundidadMejorado(int v_inicio, tipoGrafo * grafo){
  int i;

  iniciar(grafo);

  profundidad(v_inicio, grafo);

  for(i=1; i <= grafo->orden; i++)
    if( !grafo->directorio[i].alcanzado)
      profundidad(i, grafo);
}

void amplitud(int v_inicio,tipoGrafo *grafo)
{
  int w;
  pArco  p;
  Cola c;

  colaCreaVacia(&c);

  colaInserta(&c,v_inicio);

  while (!colaVacia(&c)){
	   w = colaSuprime(&c);
     if (!grafo->directorio[w].alcanzado){
       printf("%d ",w);

       grafo->directorio[w].alcanzado=1;
       p =grafo->directorio[w].lista;

       while (p!=NULL)
       {
         w = p->v;
         colaInserta(&c,w);
         p = p->sig;
       }
     }
  }
}

void amplitudMejorado(int v_inicio,tipoGrafo * grafo)
{
  int i;
  iniciar(grafo);

  amplitud(v_inicio, grafo);

  for(i=1; i<= grafo->orden; i++)
    if(!grafo->directorio[i].alcanzado)
      amplitud(i, grafo);
}

/* Ordenación Topologoica */
int buscarVerticeGradoCeroNoOrdenTop(tipoGrafo *grafo)
{
  int i;

  for (i = 1; i <= grafo->orden; i++)
    if (grafo->directorio[i].gradoEntrada == 0
      && grafo->directorio[i].ordenTop == 0)
      return i;

  return -1;
}

/* Clasificación de los vértices de un grafo dirigido acíclico
 * Tal que si existe un camino de v a w, v aparece antes que w
 * en la clasificación.
 * Imposible si el grafo tiene ciclos. No es necesariamente única.
 */
 //Devuelve -1 si no es posible la clasificación topológica
int ordenTopologicoSimple(tipoGrafo *grafo){
  /* 1. encontrar un vértice cualquiera v, al que no llegan aristas
   * y asignarle el primer orden topológico.
   *
   * 2. Decrementar el grado de entrada de todos los vértices adyacentes
   * y aplicar la misma estrategia a aquellos vértices que todavía
   * no tengan asignado un orden.
   * El primer vértice cuyo grado de entrada se convierta en cero será
   * el siguiente vértice en orden topológico. (no podremos volver a
   * acceder a el desde v)
   */
   int orden, vInicial, w;
   pArco aux;

  iniciar(grafo);

  for(orden = 1; orden <= grafo->orden; orden++)
  {
    vInicial = buscarVerticeGradoCeroNoOrdenTop(grafo);

    if (vInicial == -1)
      return -1;

    grafo->directorio[vInicial].ordenTop = orden;
    aux = grafo->directorio[vInicial].lista;

    while(aux != NULL)
    {
      w = aux->v;
      grafo->directorio[w].gradoEntrada --;
      aux = aux->sig;
    }
  }
  return 0;

  /* ANALISIS DE TIEMPOS:
   * O(n^2) en la búsqueda del vértice inicial.
   */
}

int ordenTopologico(tipoGrafo *grafo)
{
  /* 1. Todos los v con grado de entrada 0 se insertan en la cola
   * 2. Mientras la cola no esté vacía
   *    1. Se suprime un vértice de la cola
   *    2. Se decrementan los grados de todos los v adyacentes
   *    3. Si el grado de entrada de algun v se convierte en 0
   *      se inserta en la colaArbol
   * 3. La ordenación topológica coincide con el orden en que los
   *  vertices van saliendo de la cola
   */

  int orden, v, w;
  Cola c;
 	pArco aux;

 	iniciar(grafo);

 	colaCreaVacia(&c);

  //Ñapa que he hecho, no se por qué colaCreaVacía no me iniciaba
  //bien c
  c.frente = NULL;
  c.fondo = NULL;

  colaInserta(&c, 2);

 	for (v = 1; v <= grafo->orden; v++)
 	{
 		if (grafo->directorio[v].gradoEntrada == 0){
 			colaInserta(&c, v);
    }
    else
    {
      return -1;
    }
 	}


 	orden = 1;

 	while(!colaVacia(&c))
 	{
 		v = colaSuprime(&c);
 		grafo->directorio[v].ordenTop = orden;
 		orden++;
 		aux = grafo->directorio[v].lista;

 		while (aux != NULL)
 			{
 				w = aux->v;
 				grafo->directorio[w].gradoEntrada--;

 				if (grafo->directorio[w].gradoEntrada == 0)
 					colaInserta(&c, w);

 				aux = aux->sig;
 			}
 	}
 	return 0;

  /* ANALISIS DE TIEMPOS:
   * O(n+a)
   * O(n) -> op. encolar y desencolar una vez por v
   * O(a) -> bucle interior una vez por arista
   * La asignación de val iniciales toma un tiempo prop al tam. grafo
   */
}

/* Caminos minimos */
void caminosBasico(int vInicio, tipoGrafo *grafo)
{
  int distanciaActual;
	int v, w;
	pArco p;

  iniciar(grafo);

	grafo->directorio[vInicio].distancia = 0;
  grafo->directorio[vInicio].anterior = 0;

	for (distanciaActual = 0; distanciaActual < grafo->orden; distanciaActual++)
		for (v = 1; v <= grafo->orden; v++)
			if (!grafo->directorio[v].alcanzado
        && grafo->directorio[v].distancia == distanciaActual)
      {
				grafo->directorio[v].alcanzado = 1;
				p = grafo->directorio[v].lista;

				while (p != NULL) {
					w = p->v;

					if (grafo->directorio[w].distancia == INF)
          {
						grafo->directorio[w].distancia++;
						grafo->directorio[w].anterior = v;
					}

					p = p->sig;
				}
      }
}

void caminos(int vInicio, tipoGrafo *grafo){
  pArco p;
	int v, w;
	Cola c;

  iniciar(grafo);

	grafo->directorio[vInicio].distancia = 0;
  grafo->directorio[vInicio].anterior = 0;

	colaCreaVacia(&c);
	colaInserta(&c, vInicio);

	while (!colaVacia(&c))
  {
		v = colaSuprime(&c);
		p = grafo->directorio[v].lista;

		while (p != NULL) {
			w = p->v;

			if (grafo->directorio[w].distancia == INF)
      {
				grafo->directorio[w].distancia++;
				grafo->directorio[w].anterior = v;
				colaInserta(&c, w);
			}

			p = p->sig;
		}
  }
}

/*Caminos ponderados*/
int buscarVerticeDistanciaMinimaNoAlcanzado(tipoGrafo *grafo)
{
	int i;
  int distanciaMinima = INF + 1;
  int v = -1;

  iniciar(grafo);

	for (i = 1; i <= grafo->orden; i++)
		if (grafo->directorio[i].alcanzado == 0
      && grafo->directorio[i].distancia < distanciaMinima) {
			distanciaMinima = grafo->directorio[i].distancia;
			v = i;
		}

	return v;
}

void dijkstraBasico(int vInicio, tipoGrafo *grafo)
{
  pArco p;
  int i;
  int v, w;

  iniciar(grafo);

  grafo->directorio[vInicio].distancia = 0;
  grafo->directorio[vInicio].anterior = 0;

  for (i = 1; i <= grafo->orden; i++) {
    v = buscarVerticeDistanciaMinimaNoAlcanzado(grafo);
    grafo->directorio[v].alcanzado++;
    p = grafo->directorio[v].lista;

    while (p != NULL) {
      w = p->v;

      if (!grafo->directorio[w].alcanzado)
        if (grafo->directorio[v].distancia + p->peso < grafo->directorio[w].distancia)
        {
          grafo->directorio[w].distancia += p->peso;
          grafo->directorio[w].anterior = v;
        }

      p = p->sig;
    }
  }
  /* ANALISIS DE TIEMPOS:
   * O(a+n²)
   * O(n) -> buscarVerticeDistanciaMinimaNoAlcanzado
   *   se llaman n veces por lo tanto O(n²)
   * El tiempo en actualizar dw es constante y como mucho una
   *   vez por arista
   * Si el grafo es denso (a=n²) el algoritmo es sencillo y óptimo
   * Si el grafo es disperso (a<<n²) es un algoritmo demasiado lento
   */
}

void dijkstra(int vInicio, tipoGrafo *grafo)
{
  pArco p;
	int i, v, w, coste;
	Monticulo m;
	tipoElementoMonticulo x;

  iniciar(grafo);

	grafo->directorio[vInicio].distancia = 0;
  grafo->directorio[vInicio].anterior = 0;

	iniciaMonticulo(&m);

	x.clave = 0;
	x.informacion.v = vInicio;
	insertar(x,&m);

	while (!vacioMonticulo(m))
  {
		eliminarMinimo(&m, &x);

		if (!grafo->directorio[x.informacion.v].alcanzado)
    {
			v = x.informacion.v;
			grafo->directorio[v].alcanzado = 1;
			p = grafo->directorio[v].lista;

			while (p != NULL) {
				w = p->v;

				if (!grafo->directorio[w].alcanzado)
        {
					coste = grafo->directorio[v].distancia + p->peso;

					if (coste < grafo->directorio[w].distancia)
          {
						grafo->directorio[w].distancia = coste;
						grafo->directorio[w].anterior = v;
						x.clave = grafo->directorio[w].distancia;
						x.informacion.v = w;
						insertar(x,&m);
					}
				}

				p = p->sig;
			}
		}
  }
  /* ANALISIS DE TIEMPOS:
   * O(a logn)
   * buscarVerticeDistanciaMinimaNoAlcanzado debe convertirse en un
   *   ciclo que se ejecutará eliminar mín hasta que aparezca un vertice
   *   no alcanzado.
   * - eliminaMin toma un tiempo en O(log t) t=tamaño del monticulo
   * - El tamaño del monticulo puede coincidir con el n de aristas
   *  el tiempo de ejecución está en  O(a logn) ya que para Grafos
   *  dispersos a<n² y por tanto loga < 2logn
   */
}

/* Arbool de expansión de coste mínimo */
int costeyTrayectoria(int vIni, int vFin, tipoGrafo *grafo)
{
  int w;
  Pila p;

  if (grafo->directorio[vFin].distancia != INF)
  {
    pilaCreaVacia(&p);
    w = vFin;

    while (w) {
      pilaInserta(&p, w);
      w = grafo->directorio[w].anterior;
    }

    while(!pilaVacia(&p))
      printf (" -> %d", pilaSuprime(&p));
  }

  return grafo->directorio[vFin].distancia;
}

void todosCaminosMin(int vIni, tipoGrafo *grafo)
{
  int i, distancia;

	for (i = 1; i <= grafo->orden; i++)
  {
		printf("\nDe %d a %d:", vIni, i);
		distancia = costeyTrayectoria(vIni, i, grafo);

		if (distancia != INF)
			printf(" | Camino de coste %d.", distancia);
		else
			printf("No existe camino.");
  }
}

/* prim */
int buscarVerticeCostoMinimoNoAlcanzado(tipoGrafo * grafo)
{
  int i;
  int costoMin = INF +1;
  int v = -1;

  for(i = 1; i<= grafo->orden; i++)
  {
    if(!grafo->directorio[i].alcanzado
      && grafo->directorio[i].peso < costoMin)
    {
      costoMin = grafo->directorio[i].peso;
      v = i;
    }
  }
  return v;
}

void aceptarArista(tipoGrafo *grafo, tipoElementoMonticulo x)
{
	pArco p;
	int i;
  p = malloc(sizeof(arco));
	if (p==NULL)
  {
		liberarListas(grafo);
		free(grafo);
		grafo = NULL;
	} else {
		p->v = x.informacion.w;
		p->peso = x.clave;
		p->sig = grafo->directorio[x.informacion.v].lista;
		grafo->directorio[x.informacion.v].lista = p;

    p = malloc(sizeof(arco));
		if (p==NULL) {
			liberarListas(grafo);
			free(grafo);
			grafo = NULL;
		} else {
			p->v = x.informacion.v;
			p->peso = x.clave;
			p->sig = grafo->directorio[x.informacion.w].lista;
			grafo->directorio[x.informacion.w].lista = p;
		}
	}
}

tipoGrafo *crearArbolDeExpansion(tipoGrafo *grafo)
{
	tipoGrafo *arbol;
	tipoElementoMonticulo x;
	int i;

  arbol = calloc(1, sizeof(tipoGrafo));
	if (arbol == NULL )
		return NULL;

	arbol->orden = grafo->orden;

	for (i = 1; i <= grafo->orden; i++)
  {
		x.clave = grafo->directorio[i].peso;
		x.informacion.v = i;
		x.informacion.w = grafo->directorio[i].anterior;

		if (x.informacion.w)
    {
			aceptarArista(arbol, x);

			if (arbol == NULL)
				return NULL;
		}
	}
	return arbol;
}

tipoGrafo * primBasico(tipoGrafo *grafo)
{
  pArco p;
  int i, v, w;
  int vIni = 1;

  grafo->directorio[vIni].peso = 0;
  grafo->directorio[vIni].anterior = 0;

  for(i = 1; i <= grafo->orden; i++)
  {
    v = buscarVerticeCostoMinimoNoAlcanzado(grafo);
    grafo->directorio[v].alcanzado++;
    p = grafo->directorio[v].lista;

    while(p != NULL)
    {
      w = p->v;

      if(!grafo->directorio[w].alcanzado)
        if(grafo->directorio[w].peso > p->peso)
        {
          grafo->directorio[w].peso = p->peso;
          grafo->directorio[w].anterior = v;
        }

      p = p->sig;
    }
  }
  return crearArbolDeExpansion(grafo);
}

tipoGrafo * prim(tipoGrafo *grafo)
{
  pArco p;
	int i, v, w;
	Monticulo m;
	tipoElementoMonticulo x;
	int vInicio = 1;

	grafo->directorio[vInicio].peso = 0;
  grafo->directorio[vInicio].anterior = 0;

	iniciaMonticulo(&m);
	x.clave = 0;
	x.informacion.v = vInicio;
	insertar( x, &m);

	while (!vacioMonticulo(m)) {
		eliminarMinimo(&m, &x);

		if (!grafo->directorio[x.informacion.v].alcanzado) {
			v = x.informacion.v;
			grafo->directorio[v].alcanzado++;
			p = grafo->directorio[v].lista;

			while (p != NULL) {
				w = p->v;

				if (!grafo->directorio[w].alcanzado) {
					if (p->peso < grafo->directorio[w].peso) {
						grafo->directorio[w].peso = p->peso;
						grafo->directorio[w].anterior = v;
						x.clave = p->peso;
						x.informacion.v = w;
						insertar(x, &m);
					}
				}

				p = p->sig;
			}
		}
	}

  return crearArbolDeExpansion(grafo);
}

/* Kruskal */
void construirMonticuloDeAristas(tipoGrafo *grafo, Monticulo *m)
{
  int i;
  pArco p;
  tipoElementoMonticulo x;

  iniciaMonticulo(m);

  for (i = 1; i <= grafo->orden; i++)
  {
    p = grafo->directorio[i].lista;

    while (p != NULL)
    {
      x.clave = p->peso;
      x.informacion.v = i;
      x.informacion.w = p->v;
      insertar(x, m);
      p = p->sig;
    }
  }
}

tipoGrafo * kruskal(tipoGrafo *grafo)
{
  Monticulo m;
	int nAristasAceptadas = 0;
	particion c;
	tipoConjunto conjuntoV, conjuntoW;
	tipoElementoMonticulo x;
	tipoGrafo *arbolExp;

  arbolExp = calloc(1, sizeof(tipoGrafo));
	if (arbolExp == NULL)
		return NULL;

	arbolExp->orden = grafo->orden;

	crea(c);
	construirMonticuloDeAristas(grafo, &m);

	while (nAristasAceptadas < grafo->orden - 1)
  {
		if (-1 == eliminarMinimo(&m, &x))
    {
			liberarListas(arbolExp);
			free(arbolExp);
			return NULL;
		}

		conjuntoV = buscar(x.informacion.v, c);
		conjuntoW = buscar(x.informacion.w, c);

		if (conjuntoV != conjuntoW)
    {
			unir(conjuntoV, conjuntoW, c);
			nAristasAceptadas++;
			aceptarArista(arbolExp, x);

			if (arbolExp == NULL)
				return NULL;
		}
	}

  return arbolExp;
}
