#include "conjuntos.h"
#include <stdio.h>

void crea(particion c)
{
	int i;

	for(i = 0; i<MAXIMO; i++)
		c[i] = -1;
}

tipoElemento buscar(tipoElemento x, particion c)
{
	if(x<0 || x>= MAX)
		return -1;

	if(c[x]==0)
		return x;
	else
		return buscar(c[x],c);
}

void unir(tipoElemento x, tipoElemento y, particion c)
{
	if (x != -1 && y != -1 && x != y)
	{ //unión por altura
		if (c[x] < c[y])
			c[y] = x;
		if (c[x] > c[y])
			c[x] = y;
		else {
			c[x]--;
			c[y] = x;
		}
	}
		/*Unión arbitraria*/
		//c[y] = x;
}

void unirTamanno(tipoElemento x, tipoElemento y, particion c)
{
	if (x != -1 && y != -1 && x != y)
	{
		if (c[x]<=c[y])
		{
			c[x] += c[y];
			c[y] = x;
		} else {
			c[y] += c[x];
			c[x] = y;
		}
	}
}

/* Comprensión de caminos:
 * Técnica que se aplica a la operación de búsqueda para tratar
 * de conseguir que las op. sean más rápidas modificando el padre
 * de cada nodo del camino para que sea directamente la raiz
 */
void buscarComprensionCaminos(int x, particion c)
{
	if(x<0 || x>= MAX)
		return;

	if(c[x] <= 0)
		return x;
	else {
	  c[x] = buscarComprensionCaminos(c[x],c);
		return c[x];
	}
}

void verParticion(particion c)
{
	int i;

	printf("\n");
	for (i =0;i<MAXIMO;i++)
		printf("|%2d",c[i]);
	printf("| contenido del vector \n");

	for (i =0;i<MAXIMO;i++)
		printf("---");
  	printf("\n");

	for (i =0;i<MAXIMO;i++)
		printf(" %2d",i);
	printf("  índices\n\n");
}
