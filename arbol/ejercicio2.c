#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"
#include "pila.h"
#include "cola.h"

void presionaTecla();

int main(void)
{ 
  Arbol arbol, arbol2, arbolNum; 
  char ex_postfija[10];
  char ex_postfija2[10];
  char ex_postfija3[10];
  char respuesta, elementoIn;

/* Generación del árbol algebraico */
  strcpy(ex_postfija,"AB+CDE+**\0");
  strcpy(ex_postfija2,"23+713+**\0");
  strcpy(ex_postfija3,"357924618\0");

  arbol = genArbol(ex_postfija);
  arbol2 = genArbol(ex_postfija2);
  arbolNum = genArbol(ex_postfija3);

/* USO DE LAS DIFERENTES OPERACIONES CON ARBOL BINARIO */

    printf("\n1) LA ALTURA DEL ARBOL ES: %d \n", altura(arbol));
    presionaTecla();
    
    printf("\n2) EL NUMERO DE NODOS DEL ARBOL ES: %d \n", numNodos(arbol));
	presionaTecla();
    	
    printf("\nINTRODUZCA EL ELEMENTO QUE DESEA SUSTITUIR EN EL ARBOL: ");
    scanf("%c",&elementoIn);
    printf("\n3) EL NODO (%c) SERA SUSTITUIDO POR @ \n", elementoIn);
    sustiuye(arbol, elementoIn, '@');
    printf("\nRECORRIDO EN ORDEN ARBOL BINARIO: ");
    enOrden(arbol);
    puts("");
    presionaTecla();
    
    
    printf("\n\n4) EL NUMERO DE NODOS HOJA DE SU ARBOL BINARIO ES: %d\n", numNodosHoja(arbol));
    presionaTecla();
    
    printf("\n5) EL NUMERO DE NODOS INTERNOS (NODOS CON HIJOS) DE SU ARBOL BINARIO ES: %d\n", numNodosInternos(arbol));
    presionaTecla();
    
    printf("\n6) EL NUMERO DE NODOS CON UN UNICO HIJO DE SU ARBOL BINARIO ES: %d\n", numHijoUnico(arbol));
    presionaTecla();
    
    printf("\n7) EL NODO CON MAYOR VALOR EN SU CAMPO INFO ES: %c\n", buscarMax(arbolNum)->info);
    presionaTecla();
    
    printf("\n8) EL NODO CON MENOR VALOR EN SU CAMPO INFO ES: %c\n", buscarMin(arbolNum)->info);
    presionaTecla();

    printf("\nRECORRIDO EN ORDEN ARBOL BINARIO 1: ");
    enOrden(arbol);
    printf("\nRECORRIDO EN ORDEN ARBOL BINARIO 2: ");
    enOrden(arbol2);
    puts("");
    presionaTecla();

    if (similares(arbol, arbol2) == 1)
    	printf("\n9) LOS ARBOLES BINARIOS 1 Y 2 SON SIMILARES!!!\n");
    else
    	printf("\n9) LOS ARBOLES BINARIOS 1 Y 2 NO SON SIMILARES\n");

	presionaTecla();

    if (equivalentes(arbol, arbol2) == 1)
    	printf("\n10) LOS ARBOLES BINARIOS 1 Y 2 SON EQUIVALENTES!!!\n");
    else
    	printf("\n10) LOS ARBOLES BINARIOS 1 Y 2 NO SON EQUIVALENTES\n");
	presionaTecla();
	
	
	arbol = especular(arbol);
    printf("\n11) RECORRIDO EN ORDEN ARBOL BINARIO ESPECULAR RESPECTO AL ARBOL BINARIO 1: ");
    enOrden(arbol);
    presionaTecla();
    
    printf("\n12) EL ARBOL BINARIO 1 VA A SER ANULADO...\n");
    arbol = anula(arbol);
	presionaTecla();
    if(numNodos(arbol) == 0)
    	printf("\nSE HA VACIADO CORRECTAMENTE SU ARBOL BINARIO!!!\n");
    else
    	printf("\nNO SE HA PODIDO VACIAR CORRECTAMENTE SU ARBOL BINARIO\n");
    	
	printf("\nNUMERO DE NODOS DE SU ARBOL BINARIO 1: %d\n", numNodos(arbol));
	presionaTecla();
	
    return 0;
}

void presionaTecla()
{
	printf("\nPresiona 'ENTER' para continuar: ...");
	while(getchar() != '\n')
	;
}
