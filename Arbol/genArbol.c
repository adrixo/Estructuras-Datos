
#include <stdlib.h>
#include <stdio.h>

#include "../Pila/pila.c"
#include "genArbol.h"

Arbol genArbol(char *exPostfija){
	
	Pila pila;
	pilaCreaVacia(&pila);

	Arbol arbol;

	int i = 0;

	while(exPostfija[i] != '\0'){
		switch (exPostfija[i])
			{
				case '*':
				case '+':
					arbol = creaNodo(exPostfija[i]);

					arbol->der = pilaSuprime(&pila);
					arbol->izq = pilaSuprime(&pila);

					pilaInserta(&pila, arbol);
					break;
				default:
					arbol = creaNodo(exPostfija[i]);
					pilaInserta(&pila, arbol);
					break;
			}
		i++;
	}
	arbol = pilaSuprime(&pila);
	return arbol;
}

