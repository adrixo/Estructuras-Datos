#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"

void iniciaMonticulo(Monticulo *m){
	m->tamanno = 0;
}

int vacioMonticulo(Monticulo m){
	return (m.tamanno == 0);
}


int insertar(tipoElemento x, Monticulo *m){

	if(m->tamanno >= MAXIMO -1)
		return -1;

	m->tamanno++;
	m->elemento[m->tamanno] = x;
	filtradoAscendente(m,m->tamanno);

	return 0;
}

int eliminarMinimo(Monticulo *m, tipoElemento *minimo){

	if(m->tamanno <= 0)
		return -1;

	*minimo = m->elemento[1];
	m->elemento[1] = m->elemento[m->tamanno];

	filtradoDescendente(m,1);

	m->tamanno--;

	return 0;
}

void decrementarClave(int pos, int cantidad, Monticulo *m){
	if(pos <= 0 || pos > m->tamanno)
		return;

	m->elemento[pos].clave -= cantidad;
	filtradoAscendente(m,pos);
}

void incrementarClave(int pos, int cantidad, Monticulo *m){
	if(pos <= 0 || pos > m->tamanno)
		return;

	m->elemento[pos].clave += cantidad;
	filtradoDescendente(m,pos);
}

int esMonticulo(Monticulo m){
	int i;

	for(i=m.tamanno; i>1; i--)
		if(m.elemento[i/2].clave > m.elemento[i].clave)
			return 0;

	return 1;
}

void filtradoDescendente(Monticulo *m, int i){

	int hijo, finFiltrado = 0;
	tipoElemento ultimo = m->elemento[i];

	while(2*i <= m->tamanno && !finFiltrado){

		hijo = 2*i;

		if(	hijo+1 <= m->tamanno &&
			m->elemento[hijo+1].clave < m->elemento[hijo].clave){
				hijo++;
		}

		if(ultimo.clave > m->elemento[hijo].clave){
			m->elemento[i] = m->elemento[hijo];
			i = hijo;
		} else {
			finFiltrado = 1;
		}
	}

	m->elemento[i] = ultimo;

}

void filtradoAscendente(Monticulo *m, int i){
	tipoElemento ultimo = m->elemento[i];

	while(i>1 && m->elemento[i/2].clave > ultimo.clave){
		m->elemento[i] = m->elemento[i/2];
		i=i/2;
	}

	m->elemento[i] = ultimo;
}

void crearMonticulo(Monticulo *m){
	int i;

	for(i=m->tamanno/2; i>=1; i--){
		filtradoDescendente(m,i);
	}
}

void heapsort(Monticulo *m){
	int tam, i;
	tipoElemento e;

	tam = m->tamanno;

	crearMonticulo(m);

	for(i=1; i<=tam; i++){
		if(eliminarMinimo(m, &e))
			fprintf(stderr, "Error al eliminar mínimo");
		m->elemento[m->tamanno+1] = e;
	}

	m->tamanno = tam;

}
