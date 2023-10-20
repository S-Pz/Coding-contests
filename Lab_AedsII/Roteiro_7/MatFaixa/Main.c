#include "MFaixa.h"

int main(){

    MFaixa* M;

    M = criaMatriz(15);

    preencheAleatorio(M, 25, 90);
    imprimeFaixa(M);


    return 0;
}