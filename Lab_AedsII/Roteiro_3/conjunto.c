#include <stdio.h>
#include <stdlib.h>

#include "conjunto.h"

struct Conjunto *cria_conjunto_vazio(struct Conjunto *conjunto) {

    struct Conjunto *c = (struct Conjunto*) malloc(sizeof(struct Conjunto));
    
    c->qtd_elementos = 0;;

    return c;
}

struct Conjunto *uniao_conjunto(struct Conjunto *conjunto1, struct Conjunto *conjunto2){

    int aux = 0;
    struct Conjunto *uniao = (struct Conjunto*) malloc(2*sizeof(struct Conjunto));

    for(int i = 0; i < conjunto1->qtd_elementos; i++){
        uniao->elementos[i] = conjunto1->elementos[i];
        uniao->qtd_elementos++;
        aux ++;
    }
    for(int j = 0; j < conjunto2->qtd_elementos; j++){
        uniao->elementos[aux] = conjunto2->elementos[j];
        uniao->qtd_elementos++;
    }
    return uniao;
}

struct Conjunto *interseccao_conjunto(struct Conjunto *conjunto1, struct Conjunto *conjunto2){
    
    int aux = 0;
    struct Conjunto *interseccao = (struct Conjunto*) malloc(2*sizeof(struct Conjunto));

    for(int i = 0; i<conjunto1->qtd_elementos; i++){
        for(int j =0; j<conjunto2->qtd_elementos; j++){
            if(conjunto1->elementos[i] == conjunto2->elementos[j]){
                interseccao->elementos[aux] = conjunto1->elementos[i];
                interseccao->qtd_elementos++;
                aux++;
            }
        }
    }
    return interseccao;
}

struct Conjunto *diferenca_conjunto(struct Conjunto *conjunto1, struct Conjunto *conjunto2){

    int aux = 0;
    // fazer a diferença de conjunto1 - conjunto2
    // utilizar a funçao pertence_conjunto para verificar se o elemento pertence ao conjunto

    struct Conjunto *diferenca = cria_conjunto_vazio(diferenca);
    
    for(int i = 0; i<conjunto1->qtd_elementos; i++){
        
        int pertence = pertence_conjunto(conjunto2, conjunto1->elementos[i]);
        
        if(pertence == 0){
            diferenca->elementos[aux] = conjunto1->elementos[i];
            diferenca->qtd_elementos++;
            aux++;
        }
    }   
    
    return diferenca;
}

int pertence_conjunto(struct Conjunto *conjunto, int elemento) {

    for(int i = 0; i < conjunto->qtd_elementos; i++){
        if(conjunto->elementos[i] == elemento){
            return 1;
        }
    }

    return 0;
}

void insere_elemento(struct Conjunto *conjunto, int elemento){

    //Caso o elemento não pertença ao conjunto, ele é inserido
    if(pertence_conjunto(conjunto,elemento) == 0){
        conjunto->elementos[conjunto->qtd_elementos] = elemento;
        conjunto->qtd_elementos++;
    }else {
        printf("Elemento já pertence ao conjunto");
        endl;
    }
}

void remove_elemento(struct Conjunto *conjunto, int elemento){
    
    if(pertence_conjunto(conjunto, elemento) == 1){
        for(int i = 0; i < conjunto->qtd_elementos; i++){
            if(conjunto->elementos[i] == elemento){
                conjunto->elementos[i] = conjunto->elementos[conjunto->qtd_elementos-1];
                conjunto->qtd_elementos--;
            }
        }
    }
}

int menor_valor(struct Conjunto *conjunto){
    
    int menor = conjunto->elementos[0];
    
    for(int i = 0; i < conjunto->qtd_elementos; i++){
        if(conjunto->elementos[i] < menor){
            menor = conjunto->elementos[i];
        }
    }
    
    return menor;
}

int maior_valor(struct Conjunto *conjunto){
    
    int maior = conjunto->elementos[0];
    
    for(int i = 0; i< conjunto->qtd_elementos; i++){
        if(conjunto->elementos[i] > maior){
            maior = conjunto->elementos[i];
        }
    }
    
    return maior;
}

int conjunto_vazio(struct Conjunto *conjunto){
    
    if(conjunto->qtd_elementos == 0){
        return 1;
    }else{
        return 0;
    }
}


int conjunto_igual(struct Conjunto *conjunto1, struct Conjunto *conjunto2){
    
    int iguais = 0;
    
    if(conjunto1->qtd_elementos != conjunto2->qtd_elementos){
        return 0;
    }
    else{

        for(int i = 0; i<conjunto1->qtd_elementos;i++){
            if(conjunto1->elementos[i] == conjunto2->elementos[i]){
                iguais ++;
            }
        }
    }
    
    //Compara se a quantidade de elementos iguais é igual a quantidade de elementos do conjunto 1 ou 2 no caso e se for 
    //siginfica que todos os elementos são iguais e retorna 1, caso contrário retorna 0

    if(iguais == conjunto1->qtd_elementos){
        return 1;
    }else{
        return 0;
    }
}

int tamanho_conjunto(struct Conjunto *conjunto){
    
    return conjunto->qtd_elementos;
}

void imprime_conjunto(struct Conjunto *conjunto){
    
    for(int i = 0; i < conjunto->qtd_elementos; i++){
        printf("%d ", conjunto->elementos[i]);
    }
    endl;
}

void limpa_conjunto(struct Conjunto *conjunto){

    free(conjunto);
}