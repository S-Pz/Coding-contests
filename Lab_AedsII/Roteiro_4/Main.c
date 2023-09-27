#include <stdio.h>
#include "Lista.h"

#define endl printf("\n")

int main(){

    Lista *L;

    L = criaLista();

    //Insere do fim
    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 20);
    insereFim(L, 30);

    printf("O elemento procurado está na posi %d.", procura(L, 10));
    endl;

    //Insere Ordenando
    insereOrder(L,25);
    insereOrder(L,9);

    //Remove do inicio
    removeIni(L);
    
    //Remove a ocorrencia do elemento
    if(removeOcorre(L, 20)){
        printf("Elemento 20 removido.");
        endl;
    }
    
    imprimeLista(L);

    destroiLista(L);

    return 0;
}