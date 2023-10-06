#include "PilhaDin.h"

Pilha *cria_Pilha(){
    
    Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
    
    if(pi == NULL){
        return 0;
    }
    return pi;
}
void libera_Pilha(Pilha *pi){

    if(pi != NULL){

        NO *elem;

        while (pi->topo != NULL){

            elem = pi->topo;
            pi->topo = pi->topo->prox;

            free(elem);
        }
        free(pi);
    }
}
int tamanho_Pilha(Pilha *pi){
    
    if(pi == NULL){
        return 0;
    }
    return pi->qtd;
}
int pilha_Vazia(Pilha *pi){
    
    if(pi == NULL){
        return 1;
    }

    if(pi->topo == NULL){
        return 1;
    }
    return 0;
}
int pilha_Cheia(Pilha *pi){
    return 0;
}
int insere_Pilha(Pilha *pi, int val){
    
    if(pi == NULL){
        return 0;
    }

    NO *elem = (NO *) malloc(sizeof(NO));

    if(elem == NULL){
        return 0;
    }

    elem->info = val;
    elem->prox = pi->topo;
    pi->topo = elem;
    pi->qtd ++;

    return 1;
}
int remove_Pilha(Pilha *pi){

    if(pi == NULL){
        return 0;
    }
    if(pi->topo == NULL){
        return 0;
    }

    //Aqui remove o topo, crio uma cópia do topo, depois faço o topo ser o proximo
    // e desalco a copia criada.
    NO *elem = pi->topo;

    pi->topo = elem->prox;

    free(elem);

    return 1;
}

int ver_Topo(Pilha *pi){

    if(pi == NULL){
        return 0;
    }
    if(pi->topo == NULL){
        return 0;
    }

    return pi->topo->info;
}

void imprime_Pilha(Pilha *pi) {

   if (pi == NULL || pi->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }

    NO *elem = pi->topo;

    while (elem != NULL) {
        printf("%d ", elem->info);
        elem = elem->prox;
    }
    endl;
}