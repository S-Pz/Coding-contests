#include <stdio.h>
#include "LSE.h"

int main(){
    
    Lista *L;
    NO *a;

    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 30);
    insereFim(L, 30);
    
    removeIni(L);
    endl;
    printf("Tamanho: %d\n", tamanhoLista(L));

    insereOrdenado(L, 15);
    insereOrdenado(L, 25);
    insereOrdenado(L, 25);
    insereOrdenado(L, 35);

    printf("Tamanho: %d\n", tamanhoLista(L));
    endl;
    //a = busca(L, 30);
    printf("Elemento: %d, encontrado.\n", busca(L, 30)->info);
    endl;

    printf("Elemento: %d, encontrado.\n", busca(L, 35)->info);
    endl;

    imprimeLista(L);

    removePrimOco(L, 30);
    endl;
    removePrimOco(L, 25);
    endl;

    imprimeLista(L);
    destroiLista(L);

    return 0;
}
