#include "conjuntos.h"
#include <stdio.h>

void crea(particion c)
{
	for(int i = 0; i<MAXIMO; i++)
		c[i] = 0;
}

tipoElemento buscar(tipoElemento x, particion c)
{
	if(c[x]==0)
		return x;
	else
		return buscar(c[x],c);
}

void unir(tipoElemento x, tipoElemento y, particion c)
{
	c[y] = x;
}

void verParticion(particion c)
{
	int i;

	printf("\n");
  for (i =0;i<MAXIMO;i++)
		printf("|%2d",c[i]);
  printf("| contenido del vector \n");

	for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");

  for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices\n\n");
}
