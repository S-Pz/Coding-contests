#include <stdio.h>
#include "LDE.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 40);
    insereFim(L, 50);
    insereFim(L, 60);
    insereFim(L, 70);
    insereFim(L, 80);
    insereFim(L, 90);

    printf("Tamanho: %d\n", tamanhoLista(L));
    endl;

    imprimeLista(L);

    removeIni(L);
    removeFim(L);

    imprimeLista(L);
    
    endl;
    printf("Tamanho: %d\n", tamanhoLista(L));

    insereOrdenado(L, 15);
    insereOrdenado(L, 25);
    insereOrdenado(L, 25);
    insereOrdenado(L, 35);

    imprimeLista(L);

    printf("Elemento: %d, encontrado.\n", busca(L, 30)->info);
    endl;
    printf("Elemento: %d, encontrado.\n", busca(L, 35)->info);
    endl;

    removePrimOco(L, 30);
    removePrimOco(L, 25);
    imprimeLista(L);

    destroiLista(L);
    return 0;
}