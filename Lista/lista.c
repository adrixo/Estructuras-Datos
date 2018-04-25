#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

int creaVacia(Lista *l) {
  if (l == NULL)
    return -1;
  else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
    return -1;
  else {
        l->raiz->sig = NULL;
        return 0;
    }
}

int vacia(Lista *l){

    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int destruye(Lista *l) {
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}

void imprime(Lista *l) {
    tipoCelda *aImprimir;
    int posicion;

    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion anterior(tipoPosicion p, Lista *l) {
    tipoCelda *anterior;

    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion primero(Lista *l) {


}



tipoPosicion fin(Lista *l) {




}




int inserta(tipoElemento x, tipoPosicion p, Lista *l) {










}


int sumprime (tipoPosicion p, Lista *l) {







}



tipoPosicion siguiente(tipoPosicion p,Lista *l) {



}




tipoPosicion localiza (tipoElemento x, Lista *l) {




}



tipoElemento recupera(tipoPosicion p, Lista *l) {





}


int anula(Lista *l) {





}
