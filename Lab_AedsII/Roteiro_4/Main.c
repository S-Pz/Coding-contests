#include <stdio.h>
#include "Lista.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);

    removeIni(L);

    imprimeLista(L);

    destroiLista(L);
    return 0;
}