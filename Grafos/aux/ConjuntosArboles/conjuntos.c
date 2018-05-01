#include "conjuntos.h"
#include <stdio.h>

void crea(particion c)
{
	int i;

	for(i = 0; i<MAXCONJUNTOS; i++)
		c[i] = -1;
}

tipoElementoConjunto buscar(tipoElementoConjunto x, particion c)
{
	if(x<0 || x>= MAXCONJUNTOS)
		return -1;

	if(c[x]==0)
		return x;
	else
		return buscar(c[x],c);
}

void unir(tipoElementoConjunto x, tipoElementoConjunto y, particion c)
{
	if (x != -1 && y != -1 && x != y)
		if (c[x] < c[y])
			c[y] = x;
		if (c[y] < c[x])
			c[x] = y;
		else {
			c[x]--;
			c[y] = x;
		}
}

void verParticion(particion c)
{
	int i;

	printf("\n");
	for (i =0;i<MAXCONJUNTOS;i++)
		printf("|%2d",c[i]);
	printf("| contenido del vector \n");

	for (i =0;i<MAXCONJUNTOS;i++)
		printf("---");
  	printf("\n");

	for (i =0;i<MAXCONJUNTOS;i++)
		printf(" %2d",i);
	printf("  índices\n\n");
}
