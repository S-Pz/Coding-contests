#include <stdio.h>
#include "LCSE.h"

int main(){

    Lista *L;

    L = criaLista();
    NO *a;

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 40);
    insereFim(L, 50);
    insereFim(L, 60);
    insereFim(L, 70);
    insereFim(L, 80);
    insereFim(L, 90);

    removeIni(L);
    removeFim(L);

    printf("Tamanho: %d\n", tamanhoLista(L));
    endl;

    printf("Elemento: %d, encontrado.\n", busca(L, 30)->info);
    endl;

    printf("Elemento: %d, encontrado.\n", busca(L, 40)->info);
    endl;

    imprimeLista(L);


    destroiLista(L);

    return 0;
}