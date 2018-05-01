#include "conjuntos.h"
#include <stdio.h>

void crea(particion c){
	int i;

	for( i=0; i<MAXIMO; i++ )
		c[i] = i;
}

tipoElemento buscar(tipoElemento x, particion c){
	return c[x];
}

void unir(tipoElemento x, tipoElemento y, particion c){
	int i;
	tipoElemento aux = c[y];

	for(i=0; i < MAXIMO ; i++)
		if( c[i] == aux)
			c[i] = c[x];
}

//Funciones auxiliares
void verParticion(particion c)
{
	int i;

  printf("\n");
  for (i =0;i<MAXIMO;i++)
		printf("|%2d",c[i]);
  printf("| contenido del vector\n");

  for (i =0;i<MAXIMO;i++)
		printf("---");
  printf("\n");

  for (i =0;i<MAXIMO;i++)
		printf(" %2d",i);
  printf("  índices \n\n");
}

void verClaseEquivalencia(tipoElemento x,particion c)
{
	int representante,i;

  representante = buscar(x,c);
  printf("\n\nclase de Equivalencia de %d cuyo representante es %d: ", x,representante);

  for (i=0;i<MAXIMO;i++)
		if (c[i]==representante)
			printf("%d ",i);
  printf("\n");

}
