#include "MatDin.h"

int main(){

    Matriz *M, *M1;
    
    M = criaMatriz(2, 2);
    imprime(M);
    
    preencheAleatorio(M, 25, 70);
    imprime(M);

    M1 = criaMatriz(5, 5);
    imprime(M1);
    
    preencheAleatorio(M1, 5, 25);
    imprime(M1);

    Matriz *A;
    A = criaMatriz(3, 3);
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int e;
            scanf("%d", &e);
            insereElem(A, e, i, j);
        }
    }
    imprime(A);

    if(e_Simetrica(A)){ 
        printf("Simetrica!\n");
    
    }else{
        printf("Nao eh Simetrica!\n");
    }

    Matriz *TS, *TI;

    TS = criaTriangularSup(M);
    TI = criaTriangularInf(M);

    printf("Triangular Sup:\n"); imprime(TS);
    printf("Triangular Inf:\n"); imprime(TI);

    Matriz *T, *T1;
    T = criaTransposta(M);
    printf("Transposta:\n"); imprime(T);

    T1 = criaTransposta(M1);
    printf("Transposta:\n"); imprime(T1);
    
    destroiMatriz(M);
    destroiMatriz(M1);
    destroiMatriz(T1);
    destroiMatriz(T);
    //destroiMatriz(A);
    destroiMatriz(TS);
    destroiMatriz(TI);
    
    return 0;
}