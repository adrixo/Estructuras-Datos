#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"
#include "cola.c"
#define MAX 20

int main ()
{
	char cadena[MAX];

	Cola cola;

	int i, err, longitudCadena;

	printf("PORFAVOR, INTRODUZCA UNA CADENA DE CARACTERES MAX %d ELEMENTOS: ",MAX - 1);

	scanf("%s",&cadena);

	printf("Estado cola: %d \n", cola);

	err = colaCreaVacia(&cola);

	printf("Estado cola tras crear: %d  %d\n", cola, err);

	printf("Esta vacia : %d\n\n\nAnadimos:\n", colaVacia (&cola) );

	longitudCadena = strlen(cadena); 

	for(i = 0; i < longitudCadena; i++)
	{
		printf("insertamos elemento: %d ", i);
		err = colaInserta(&cola, cadena[i]); 
		printf("Da error: %d\n", err);
	}

	printf("Esta vacia : %d\n\n\nSuprimimos:\n", colaVacia (&cola) );

    for(i = 0; i < longitudCadena; i++)
        {
		printf("borramos elemento: %d ", i);
		err = colaSuprime(&cola);
		printf("Da error: %c\n", err);
        }

	printf("Supresion de prueba: %d\n", colaVacia (&cola) );
	err = colaSuprime(&cola);

	printf("Esta vacia: %d\n", colaVacia (&cola) );

}
