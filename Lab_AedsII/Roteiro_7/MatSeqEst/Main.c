#include "Mat.h"
#include <stdio.h>

#define endl printf("\n")

int main(){
    
    Matriz *M, *M1, *M2;

    M = criaMatriz(2, 3);
    M1 = criaMatriz(6,6);
    M2 = criaMatriz(6,6);

    imprime(M);
    imprime(M1);
    imprime(M2);

    preencheAleatorio(M, 10, 50);
    preencheAleatorio(M1, 5, 60);
    preencheAleatorio(M2, 14, 25);

    imprime(M);
    imprime(M1);
    imprime(M2);


    Matriz *TS, *TI;
    
    TS = criaTriangularSup(M);
    TI = criaTriangularInf(M);

    printf("Triangular Sup:\n"); imprime(TS);
    printf("Triangular Inf:\n"); imprime(TI);

    Matriz* T;
    T = criaTransposta(M);
    
    printf("Transposta:\n"); imprime(T);

    Matriz *Soma, *Sub, *Mult;

    printf("Soma das matrizes M1 e M2");
    endl;
    Soma = somaMatrizes(M1,M2); imprime(Soma);
    
    printf("Subtracao das matrizes M1 e M2");
    endl;
    Sub  = subtraiMatrizes(M1,M2); imprime(Sub);
    
    printf("Multiplicacao das matrizes M1 e M2");
    endl;
    Mult = multiplicaMatrizes(M1,M2); imprime(Mult);

    destroiMatriz(M);
    destroiMatriz(M1);
    destroiMatriz(M2);
    destroiMatriz(Soma);
    destroiMatriz(Sub);
    destroiMatriz(Mult);
    destroiMatriz(TS);
    destroiMatriz(TI);
    destroiMatriz(T);

    return 0;
}