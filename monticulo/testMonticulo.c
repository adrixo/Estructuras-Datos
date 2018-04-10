#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"
int main(void)
{ Monticulo m;
  tipoElemento elemento;
  int i,n=10;

 iniciaMonticulo(&m);
 elemento.clave=12;
 elemento.informacion=0;

 i=insertar(elemento,&m);

srand(time(NULL));
 while (m.tamanno<n)
  { elemento.clave=rand()%100;
    i = insertar(elemento,&m);
  }

printf("\t");
 for (i=1;i<=m.tamanno;i++){
	printf("%d ",m.elemento[i].clave);
	if(i==1 | i==3 | i==7)
		printf("\n");
	if(i==2 | i== 5 )
		printf("\t\t");
}
 printf("\n");

 decrementarClave(6,10,&m);
 for (i=1;i<=m.tamanno;i++)
    printf("%d ",m.elemento[i].clave);
    printf("\n");
}




