#include "MEsparsaCSR.h"

/*
Input : 10  20  0  0  0  0
         0  30  0  4  0  0
         0   0 50 60 70  0
         0   0  0  0  0 80

Output :  A = [10 20 30 4 50 60 70 80],
         IA = [0 2 4 7 8]
         JA = [0  1 1 3 2 3 4 5]
*/

int main(){
    
    Matriz *M = criaMatriz(4, 6);

    insereElem(M, 10, 0, 0);
    insereElem(M, 20, 0, 1);
    insereElem(M, 30, 1, 1);
    insereElem(M, 4, 1, 3);
    insereElem(M, 50, 2, 2);
    insereElem(M, 60, 2, 3);
    insereElem(M, 70, 2, 4);
    insereElem(M, 80, 3, 5);

    imprime(M);

    MEsparsaCSR* MS;
    MS = transformarEmCSR(M);
    
    imprimeEsparsa(MS);

    printf("----------------\n\n");

    MEsparsaCSR* MS2;
    MS2 = criaMatrizEsparsa(4, 6, 0);
    
    insereElemEsparsa(MS2, 10, 0, 0);
    insereElemEsparsa(MS2, 20, 0, 1);
    insereElemEsparsa(MS2, 50, 2, 2);
    insereElemEsparsa(MS2, 60, 2, 3);
    insereElemEsparsa(MS2, 70, 2, 4);
    insereElemEsparsa(MS2, 80, 3, 5);
    insereElemEsparsa(MS2, 30, 1, 1);
    insereElemEsparsa(MS2, 4, 1, 3);
    imprimeEsparsa(MS2);

    removeElemEsparsa(MS2, 0, 0);
    removeElemEsparsa(MS2, 0, 1);
    removeElemEsparsa(MS2, 2, 2);
    removeElemEsparsa(MS2, 2, 3);
    removeElemEsparsa(MS2, 2, 4);
    removeElemEsparsa(MS2, 3, 5);
    removeElemEsparsa(MS2, 1, 1);
    removeElemEsparsa(MS2, 1, 3);
    imprimeEsparsa(MS2);

    insereElemEsparsa(MS2, 10, 0, 0);
    insereElemEsparsa(MS2, 20, 0, 1);
    insereElemEsparsa(MS2, 50, 2, 2);
    insereElemEsparsa(MS2, 60, 2, 3);
    insereElemEsparsa(MS2, 70, 2, 4);
    insereElemEsparsa(MS2, 80, 3, 5);
    insereElemEsparsa(MS2, 30, 1, 1);
    insereElemEsparsa(MS2, 4, 1, 3);
    imprimeEsparsa(MS2);

    destroiMatriz(M);
    destroiMatrizEsparsa(MS);
    destroiMatrizEsparsa(MS2);

    return 0;
}