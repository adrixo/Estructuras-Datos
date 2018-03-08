#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pila.h"
#include "pila.c"
#define MAX 20

int main ()
{
	char cadena[MAX];

	Pila pila;

	int i, err, longitudCadena;

	printf("PORFAVOR, INTRODUZCA UNA CADENA DE CARACTERES MAX %d ELEMENTOS: ",MAX - 1);

	scanf("%s",&cadena);

	printf("Estado pila: %d \n", pila);

	err = pilaCreaVacia(&pila);

	printf("Estado pila tras crear: %d  %d\n", pila, err);

	printf("Esta vacia : %d\n\n\nAnadimos:\n", pilaVacia (&pila) );

	longitudCadena = strlen(cadena); 

	for(i = 0; i < longitudCadena; i++)
	{
		printf("insertamos elemento: %d ", i);
		err = pilaInserta(&pila, cadena[i]); 
		printf("Da error: %d\n", err);
	}

	printf("Esta vacia : %d\n\n\nSuprimimos:\n", pilaVacia (&pila) );

    for(i = 0; i < longitudCadena; i++)
        {
		printf("borramos elemento: %d ", i);
		err = pilaSuprime(&pila);
		printf("Da error: %c\n", err);
        }

	printf("Supresion de prueba: %d\n", pilaVacia (&pila) );
	err = pilaSuprime(&pila);

	printf("Esta vacia: %d\n", pilaVacia (&pila) );

}
