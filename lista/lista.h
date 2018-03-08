#ifndef __LISTA_H
#define __LISTA_H

typedef int tipoElemento;


typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
	
typedef struct {
	tipoCelda * raiz , *ultimo;
	} Lista;

typedef tipoCelda *tipoPosicion;

int creaVacia(Lista *l);
tipoPosicion primero(Lista *l);
tipoPosicion siguiente(tipoPosicion p, Lista *l);
tipoPosicion anterior(tipoPosicion p, Lista *l);
tipoPosicion fin(Lista *l);

int inserta(tipoElemento x, tipoPosicion p, Lista *l);
int suprime (tipoPosicion p, Lista *l);
int anula(Lista *l);

int vacia(Lista *l);
tipoPosicion localiza (tipoElemento x, Lista *l);
tipoElemento recupera(tipoPosicion p, Lista *l);
void imprime(Lista *l);
int destruye(Lista *l);

#endif 
