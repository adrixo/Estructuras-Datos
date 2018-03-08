#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"

int main(void)
{ Arbol arbol;
  Arbol binario;

  binario = creaNodo('a');
  binario->izq = creaNodo('b');
  binario->der = creaNodo('c');
  binario->izq->izq = creaNodo('d');
  binario->izq->der = creaNodo('e');
  binario->der->izq = creaNodo('f');
  binario->der->der = creaNodo('g');

  char ex_postfija[10];

/* Generación del árbol algebraico */
  strcpy(ex_postfija,"AB+CDE+**\0");

  arbol = genArbol(ex_postfija);

/* Recorrido en amplitud o por niveles */
  printf("Recorrido en amplitud: ");
   amplitud(arbol);
  printf("\n");

  printf("estructura: ");
  representacionArbolBinario(arbol);
  printf("\n");

/* Aplicación de algunas operaciones y recorridos al árbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(arbol);
  printf("\n");

  printf("Recorrido en ORDEN: ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(arbol);
  printf("\n");
  printf("Debe coinicidir con la expresión postfija inicial\n");

  printf("El árbol tiene %d nodos \n", numNodos(arbol));
  printf("y altura: %d\n",altura(arbol));

  printf("El árbol tiene %d nodos\n", numNodos(arbol));
  arbol = anula(arbol);
  printf("Después de anula el arbol queda vacio, por tanto la altura será 0.\n");
  if (altura(arbol)!=-1)		// Cuidado con definición de altura
     printf("El árbol no se ha anulado correctamente\n");
  else
     printf("O.K. Parece que la operación anula funciona!!!\n");


/* Evaluación de un árbol algebraico: operandos entre '0' y '9'*/

  strcpy(ex_postfija,"23+713+**\0");
  arbol = genArbol(ex_postfija);
 // printf("evalua: %d\n", evaluar(arbol));
  printf("Recorrido en PRE_ORDEN (prefija): ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN(infija): ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN(postfija): ");
  postOrden(arbol);
  printf("\n");

/* comprobación operaciones */

  return 1;
}
