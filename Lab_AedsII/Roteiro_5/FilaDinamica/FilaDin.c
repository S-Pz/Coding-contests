#include <stdio.h>
#include <stdlib.h>

#include "FilaDin.h"

Fila *cria_Fila(){

    Fila *fi = (Fila*) malloc(sizeof(Fila));

    if(fi != NULL){
        fi->fim = NULL;
        fi->ini = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila *fi){

    if(fi != NULL){
        
        NO *elem;

        while(fi->ini != NULL){
            elem = fi->ini;
            fi->ini = fi->ini->prox;

            free(elem);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila *fi){
    
    if(fi == NULL){
        return 0;
    }
    return fi->qtd;
}

int Fila_vazia(Fila *fi){
    
    if(fi == NULL){
        return -1;
    }
    if(fi->ini == NULL){
        return 1;
    }
    return 0;
}

int Fila_cheia(Fila *fi){
    return 0;
}

int insere_Fila(Fila *fi, int val){
    
    if(fi == NULL){
        return 0;
    }

    NO *elem = (NO *) malloc(sizeof(NO));

    if(elem == NULL){
        return 0;
    }

    elem->info = val;
    elem->prox = NULL;

    if(fi->fim == NULL){ // Indica se a fila está vaiza
        
        fi->ini = elem;
    }else{
        fi->fim->prox = elem;
    }

    fi->fim = elem;
    fi->qtd ++;

    return 1; // Se a inserção aconteceu com sucesso
}

int remove_Fila(Fila *fi){
    
    if(fi == NULL){
        return 0;
    }
    if(fi->ini == NULL){ //Fila vazia
        return 0;
    }

    NO *elem = fi->ini;
    fi->ini = fi->ini->prox;

    free(elem);

    if(fi->ini == NULL){ //Fila ficou vazia
        fi->fim = NULL;
    }

    fi->qtd--;
    
    return 1; //Se o elemento foi removido com sucesso
}

int inicio_Fila(Fila *fi, int *val){ // 

    if(fi == NULL){
        return 0;
    }
    if(fi->ini == NULL){ // Fila vazia
        return 0;
    }

    *val = fi->ini->info; // Retoruna um ponteiro para o primeiro elemento da fila

    return 1;
}

void imprime(Fila *fi){

    if(fi == NULL){
        return;
    }

    if(Fila_vazia(fi)){
        printf("Pilha vazia");
        endl;
        return;
    }

    NO *atual = fi->ini;

    printf("Elementos:");
    
    while(atual != NULL){
        printf("%d ", atual->info);
        atual = atual->prox;
    }    
    endl;
}