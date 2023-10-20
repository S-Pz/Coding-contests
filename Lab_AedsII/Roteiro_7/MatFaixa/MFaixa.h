/*---------------- File: MFaixa.h  ------------------+
|Matriz de Faixa (malloc)                   |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 06/10/2023      |
+-------------------------------------------------------+ */

#ifndef MFAIXA_H
#define MFAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Matriz de Faixa (Tridiagonal)
3 vetores:
Diagonal (A) -> tamanho N
Superior (B) -> tamanho N-1 (acima da diagonal principal)
Inferior (C) -> tamanho N-1 (abaixo da diagonal principal)
A B 0 0 0
C A B 0 0
0 C A B 0
0 0 C A B
0 0 0 C A
*/

/*
Indices:
[0,0]	[0,1]	    0	    0	    0	    0	    0	    0	    0	    0	
[1,0]	[1,1]	[1,2]	    0	    0	    0	    0	    0	    0	    0	
    0	[2,1]	[2,2]	[2,3]	    0	    0	    0	    0	    0	    0	
    0	    0	[3,2]	[3,3]	[3,4]	    0	    0	    0	    0	    0	
    0	    0	    0	[4,3]	[4,4]	[4,5]	    0	    0	    0	    0	
    0	    0	    0	    0	[5,4]	[5,5]	[5,6]	    0	    0	    0	
    0	    0	    0	    0	    0	[6,5]	[6,6]	[6,7]	    0	    0	
    0	    0	    0	    0	    0	    0	[7,6]	[7,7]	[7,8]	    0	
    0	    0	    0	    0	    0	    0	    0	[8,7]	[8,8]	[8,9]	
    0	    0	    0	    0	    0	    0	    0	    0	[9,8]	[9,9]
*/

typedef struct{
    int *diagonal;
    int *superior;
    int *inferior;
    int tam;
}MFaixa;

void zeraMatriz(MFaixa *mf){
    
    for(int i=0; i<mf->tam; i++){
        mf->diagonal[i] = 0;
        if(i < mf->tam -1){
            mf->superior[i] = 0;
            mf->inferior[i] = 0;
        }
    }
}

MFaixa *criaMatriz(int t){
    
    MFaixa *mf;
    mf = (MFaixa*) malloc (sizeof(MFaixa));
    
    if(mf != NULL){
        
        if(t <= 1){
            printf("Dimensao deve ser > 1, matriz nao criada!");
            return NULL;
        }
        
        mf->tam = t;
        mf->diagonal = (int*) malloc (t*sizeof(int));
        mf->superior = (int*) malloc ((t-1)*sizeof(int));
        mf->inferior = (int*) malloc ((t-1)*sizeof(int));
        
        if(mf->diagonal == NULL || mf->superior == NULL || mf->inferior == NULL)
          return NULL;
        zeraMatriz(mf);
    }
    
    return mf;
}

void destroiMatriz(MFaixa* mf){
    
    if(mf != NULL){
        free(mf->diagonal);
        free(mf->superior);
        free(mf->inferior);
        free(mf);
    }
}

int preencheAleatorio(MFaixa* mf, int ini, int fim){
    
    if(mf == NULL) return 0;
    
    srand(time(NULL));
    
    for(int i=0; i<mf->tam; i++){
        mf->diagonal[i] = ini + rand() % (fim-ini + 1);
        
        if(i < mf->tam -1){
            mf->superior[i] = ini + rand() % (fim-ini + 1);
            mf->inferior[i] = ini + rand() % (fim-ini + 1);
        }
    }
    return 1;
}

int insereElem(MFaixa* mf, int elem, int i, int j){
  
  if(mf == NULL) return 0;
  
  if(i < 0 || j < 0 || i >= mf->tam || j >= mf->tam){
    printf("Valores invalidos, elem nao inserido!\n");
    return 0;
  }
  
  if(i == j) mf->diagonal[i] = elem;
  
  else if(i + 1 == j) mf->superior[i] = elem;
  
  else if(i == j + 1) mf->inferior[j] = elem;
 
  else{
    printf("Indices fora da faixa, elem nao inserido!\n");
    return 0;
  }
  
  return 1;
}

int consultaElem(MFaixa *mf, int i, int j){
  
  if(mf == NULL) return 0;
  
  if(i < 0 || j < 0 || i >= mf->tam || j >= mf->tam){
    printf("Valores invalidos, elem inexistente!\n");
    return 0;
  }
  
  if(i == j) return mf->diagonal[i];
  
  else if(i + 1 == j) return mf->superior[i];
  
  else if(i == j + 1) return mf->inferior[j];
  
  else return 0;
}

void imprimeFaixaVetores(MFaixa *mf){
  
  if(mf == NULL) return;
  
  
  printf("Matriz Faixa, Tam: %d x %d:\n", mf->tam, mf->tam);
  printf("Diagonal = [");
  
  for(int i=0; i<mf->tam; i++)
    printf("%d ", mf->diagonal[i]);
  
  printf("]\n");
  printf("Superior = [");
  
  for(int i=0; i<mf->tam-1; i++)
    printf("%d ", mf->superior[i]);
  
  printf("]\n");
  printf("Inferior = [");
  
  for(int i=0; i<mf->tam-1; i++)
    printf("%d ", mf->inferior[i]);
  
  printf("]\n\n");
}

void imprimeFaixa(MFaixa *mf){

  if(mf == NULL) return;
  
  imprimeFaixaVetores(mf);
  printf("Matriz Original:\n");

  for(int i=0; i<mf->tam; i++){
    for(int j=0; j<mf->tam; j++)
      printf("%d\t", consultaElem(mf, i, j));
    printf("\n");
  }
}

#endif