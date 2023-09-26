/*----------------- File: Lista.h ----------------------+
|Lista Sequencial Estatica                              |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 12/09/2023      |
+-------------------------------------------------------+ */
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int qtd;
    int dados[MAX];
}Lista;

Lista* criaLista(){
    Lista* li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void destroiLista(Lista *li){
    if(li != NULL)
        free(li);
}

int procura(Lista *li, int x){
    
    if(li == NULL) return -1;
    
    for(int i=0; i<li->qtd; i++){
        if(li->dados[i] == x)
            return i;
    }
}

int tamanhoLista(Lista *li){
    if(li == NULL)
        return -1;
    return li->qtd;
}

int listaCheia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int listaVazia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}
//errado
int insereOrder(Lista *li, int elem){

    if(li == NULL) return 0;
    if(!listaCheia(li)){
        int i, j;
        for(i=0; i<li->qtd; i++){
            if(li->dados[i] > elem){
                for(j=li->qtd; j>i; j--){
                    li->dados[j] = li->dados[j-1];
                }
                li->dados[i] = elem;
                li->qtd++;
                return 1;
            }
        }
        li->dados[li->qtd] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}
int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        li->dados[li->qtd] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        int i;
        for(i=li->qtd; i>0; i--){
            li->dados[i] = li->dados[i-1];
        }
        li->dados[0] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}

int procuraMenor(Lista *li){

    int menor = li->dados[0];

    for(int i=0; i<li->qtd; i++){
        if(li->dados[i] < menor)
            menor = li->dados[i];
    }
    return menor;
}

int removeOcorre(Lista *li, int elem){

    if(li == NULL) return 0;
    
    int indi, menor = 0;

    for(int i=0; i<li->qtd; i++){
        
        indi = procura(li, elem);

        if(indi < menor){
            menor = indi;
        }
    }

}
int removeElem(Lista *li, int elem){

    if(li == NULL) return 0;
    
    if(!listaVazia(li)){
        int i, indi;
        indi = procura(li, elem);
        if(indi == -1) return 0;
        for(i=indi; i<li->qtd-1; i++){
            li->dados[i] = li->dados[i+1];
        }
        li->qtd--;
        return 1;


}
int imprimeLista(Lista *li){
    if(li == NULL) return 0;
    int i;
    printf("Elementos:\n");
    for(i=0; i<li->qtd; i++){
        printf("%d ", li->dados[i]);
    }
    printf("\n");
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(!listaVazia(li)){
        li->qtd--;
        return 1;
    }else return 0;
}

int removeIni(Lista *li){
    if(li == NULL ) return 0;
    if(!listaVazia(li)){
        int i;
        for(i=0; i<li->qtd-1; i++)
            li->dados[i] = li->dados[i+1];
        li->qtd--;
        return 1;
    } else{
        return 0;
    }
}

#endif