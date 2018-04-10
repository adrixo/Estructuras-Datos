#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"

int main(){
  particion C;
  int i;


crea(C);
printf("Situacion INICIAL: ");
verParticion(C);

// {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}


unir(13,15,C);		// Mejor unir(buscar(13,C),buscar(15,C),C);
unir(7,0,C);		// Mejor unir(buscar(7,C),buscar(0,C),C);
unir(7,13,C);		// Mejor unir(buscar(7,C),buscar(13,C),C);

unir(8,12,C);		// Mejor ...
unir(3,8,C);		// Mejor ...
unir(2,3,C);		// Mejor ...

unir(6,1,C);		// Mejor ...
unir(6,4,C);		// Mejor ...
unir(11,14,C);		// Mejor ...
unir(11,6,C);		// Mejor ...

unir(5,10,C);		// Mejor ...
unir(9,5,C);		// Mejor ...

printf("Situaci�n FINAL:   ");

verParticion(C);

printf("\n\nEl elemento 5 pertenence a la clase de equivalencia con representante %d\n",buscar(5,C));

#ifdef LISTAS
verClaseEquivalencia(5,C);
#endif

// �Qu� operaci�n ser�a necesaria para relacionar el elemento 12 con el 15?


}
