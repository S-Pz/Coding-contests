/*----------------- File: LSE.h  ----------------------+
|Lista Simplesmente Encadeada                           |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 14/09/2023      |
+-------------------------------------------------------+ */

#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>
#define endl printf("\n")

typedef struct NO{
    int info;
    struct NO* prox;    
}NO;

typedef struct NO* Lista;

Lista* criaLista(){
    Lista *li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;//True - Vazia!
    return 0;//False - tem elemento!
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int insereIni(Lista* li, int elem){
    
    if(li == NULL) {
        return 0;
    }
    
    NO* novo = alocarNO();
    
    if(novo == NULL){
        return 0;
    }
    novo->info = elem;
    
    novo->prox = *li;
    *li = novo;
    
    return 1;
}

int insereFim(Lista* li, int elem){
    
    if(li == NULL){
        return 0;
    }
    
    NO* novo = alocarNO();
    
    if(novo == NULL){
        return 0;
    }
    
    novo->info = elem;
    novo->prox = NULL;
    
    if(listaVazia(li)){
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}
int insereOrdenado(Lista* li, int elem){
    
    if(li == NULL) {
        return 0;
    }
    
    NO* novo = alocarNO();
    
    if(novo == NULL){
        return 0;
    }
    
    novo->info = elem;
    
    if(listaVazia(li)){
        novo->prox = (*li);
        *li = novo;
        return 1;
    }else{
        NO* ant, *atual = *li;
        
        while(atual != NULL && atual->info < elem){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            novo->prox = (*li);
            *li = novo;
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
        return 1;
    }
}
int removeIni(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    *li = aux->prox;
    liberarNO(aux);
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* ant, *aux = *li;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == *li)
        *li = aux->prox;
    else   
        ant->prox = aux->prox;
    liberarNO(aux);
    return 1;
}
int removePrimOco(Lista* li, int elem){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* ant, *aux = *li;
    while(aux != NULL && aux->info != elem){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL) return 0;
    if(aux == *li)
        *li = aux->prox;
    else   
        ant->prox = aux->prox;
    liberarNO(aux);
    return 1;
}
int tamanhoLista(Lista* li){

    if(li == NULL) return 0;
    int cont = 0;

    NO* aux = *li;

    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}
NO *busca(Lista *li, int elem){
    
    if(li == NULL) return NULL;
    NO* aux = *li;
    
    while(aux != NULL && aux->info != elem){
        aux = aux->prox;
    }
    
    return aux;
}

void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *li;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiLista(Lista* li){
    if(li != NULL){
        NO* aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}

#endif
