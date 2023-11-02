/*---------------- File: ABP.h  ------------------------+
|Arvore Binaria de Pesquisa (ABP) Modificada            |
|					      		                        |
|					      		                        |
| Implementado com base no código de Guilherme C. Pena  |
|                                                       |
+-------------------------------------------------------+ */

#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ALUNO{

    char nome[150];
    int mat;
    double nota;

}Aluno;

typedef struct NO{
    
    Aluno aluno;
    struct NO* esq;
    struct NO* dir;

}NO;

typedef struct NO* ABP;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

int comparaAluno(Aluno a1, Aluno a2) {
    return strcmp(a1.nome, a2.nome);
}

int insereRec(NO** raiz, Aluno aluno){
    
    if(*raiz == NULL){

        NO* novo = alocarNO();
        
        if(novo == NULL){ 
            return 0;
        }
        
        novo->aluno = aluno;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
    
    }else{

        int cpm = comparaAluno(aluno, (*raiz)->aluno);

        //se for zero significa que o nomes são iguais
        if(cpm == 0){
            printf("Elemento Existente!\n"); 
            return 0;
        }
        //o aluno no qual se encontra na raiz é maior que o elemento que desja inserir
        if(cpm < 0){
            return insereRec(&(*raiz)->esq, aluno);
        
        }else{//o elemento no qual quero inserir é maior que minha raiz, então a inserção é feita na direta
            return insereRec(&(*raiz)->dir, aluno);
        }
    }
    return 1;
}

int insereIte(NO** raiz, Aluno aluno){
    NO *aux = *raiz, *ant = NULL;
    
    while (aux != NULL){
        ant = aux;

        int cpm = comparaAluno(aluno, aux->aluno);
        
        if(cpm == 0){
            printf("Elemento Existente!\n"); 
            return 0;
        }
        if(cpm < 0) {
            aux = aux->esq;
        }else {
            aux = aux->dir;
        }
    }
    
    NO* novo = alocarNO();
    
    if(novo == NULL) return 0;
    
    novo->aluno = aluno;
    novo->esq = NULL;
    novo->dir = NULL;
    
    if(ant == NULL){
        *raiz = novo;
    
    }else{

        int cpm = comparaAluno(aluno, ant->aluno);

        if(cpm < 0) {
            ant->esq = novo;
        } else {
            ant->dir = novo;
        }
    }
    return 1;
}

int insereElem(ABP* raiz, Aluno aluno){

    if(raiz == NULL) return 0;
    
    return insereRec(raiz, aluno);
    //return insereIte(raiz, elem);
}

int pesquisaRec(NO** raiz, Aluno aluno){

    if(*raiz == NULL) return 0;

    int cpm = comparaAluno(aluno, (*raiz)->aluno);

    if(cpm == 0) {
        return 1;
    }
    if(cpm < 0){
        return pesquisaRec(&(*raiz)->esq, aluno);
    }else{
        return pesquisaRec(&(*raiz)->dir, aluno);
    }
}

int pesquisaIte(NO** raiz, Aluno aluno){
    NO* aux = *raiz;
    
    while(aux != NULL){
        
        int cpm = comparaAluno(aluno, aux->aluno);

        if(cpm == 0){
            return 1;
        }
        if(cpm < 0){
            aux = aux->esq;
        
        }else{
            aux = aux->dir;
        }
    }
    return 0;
}
void maiorNota(NO *raiz){

    if(raiz == NULL){
        return ;
    }

    while (raiz->dir != NULL){

        raiz = raiz->dir;
    }

    printf("Aluno com a maior nota:\n");
    printf("Nome: %s\n", raiz->aluno.nome);
    printf("Matrícula: %d\n", raiz->aluno.mat);
    printf("Nota: %.2f\n", raiz->aluno.nota);
    
}
void menorNota(NO *raiz){

    if(raiz == NULL){
        return;
    }
    while (raiz ->esq != NULL){
        raiz = raiz->esq;
    }

    printf("Aluno com a menor nota:\n");
    printf("Nome: %s\n", raiz->aluno.nome);
    printf("Matrícula: %d\n", raiz->aluno.mat);
    printf("Nota: %.2f\n", raiz->aluno.nota);
}

int pesquisa(ABP* raiz, Aluno aluno){
    
    if(raiz == NULL) return 0;
    
    if(estaVazia(raiz)) return 0;
    
    return pesquisaRec(raiz, aluno);
    //return pesquisaIte(raiz, elem);
}

int removeRec(NO** raiz, Aluno aluno){

    if(*raiz == NULL) return 0;
    
    int cpm = comparaAluno(aluno, (*raiz)->aluno);

    if(cpm == 0){
        
        NO* aux;

        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            
            printf("Caso 1: Liberando %s..\n", (*raiz)->aluno.nome);
            printf("Caso 1: Liberando %d..\n", (*raiz)->aluno.mat);
            printf("Caso 1: Liberando %lf..\n", (*raiz)->aluno.nota);
            
            liberarNO(*raiz);
            *raiz = NULL;
        
        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            
            printf("Caso 2.1: Liberando %s..\n", (*raiz)->aluno.nome);
            printf("Caso 2.1: Liberando %d..\n", (*raiz)->aluno.mat);
            printf("Caso 2.1: Liberando %lf..\n", (*raiz)->aluno.nota);
            
            aux = *raiz;
            *raiz = (*raiz)->dir;
            
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            
            printf("Caso 2.2 Liberando %s..\n", (*raiz)->aluno.nome);
            printf("Caso 2.2 Liberando %d..\n", (*raiz)->aluno.mat);
            printf("Caso 2.2 Liberando %lf..\n", (*raiz)->aluno.nota);
            
            aux = *raiz;
            *raiz = (*raiz)->esq;
            
            liberarNO(aux);
        }else{

            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            
            printf("Caso 3: Liberando %s..\n", (*raiz)->aluno.nome);
            printf("Caso 3: Liberando %d..\n", (*raiz)->aluno.mat);
            printf("Caso 3: Liberando %lf..\n", (*raiz)->aluno.nota);
            
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            
            while(Filho->dir != NULL){//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            }
            
            (*raiz)->aluno = Filho->aluno;
            Filho->aluno = aluno;
            
            return removeRec(&(*raiz)->esq, aluno);
        }
        return 1;

    }else if(cpm  < 0){
        return removeRec(&(*raiz)->esq, aluno);
    }
    else{
        return removeRec(&(*raiz)->dir, aluno);
    } 
}

NO* removeAtual(NO* atual){

    NO* no1, *no2;
    //Ambos casos no if(atual->esq == NULL)
    //Caso 1 - NO sem filhos
    //Caso 2.1 - Possui apenas uma subarvore direita
    
    if(atual->esq == NULL){
        no2 = atual->dir;
        liberarNO(atual);
        return no2;
    }
    
    //Caso 3 - Possui as duas subarvores (esq e dir)
    //Estrategia: 

    no1 = atual;
    no2 = atual->esq;
    
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    
    liberarNO(atual);
    
    return no2;
}

int removeIte(NO** raiz, Aluno aluno){
    
    if(*raiz == NULL) return 0;
    
    NO* atual = *raiz, *ant = NULL;

    int cpm = comparaAluno(aluno, atual->aluno);

    while(atual != NULL){
        
        if(cpm == 0){

            if(atual == *raiz){
                *raiz = removeAtual(atual);

            }else{

                if(ant->dir == atual){
                    ant->dir = removeAtual(atual);
                }
                else{
                    ant->esq = removeAtual(atual);
                }
            }
            return 1;
        }
        ant = atual;
        
        if(cpm < 0){
            atual = atual->esq;

        }else{
            atual = atual->dir;
        }
    }
    return 0;
}

int removeElem(ABP *raiz, Aluno aluno){

    if(pesquisa(raiz, aluno) == 0){
        printf("Elemento inexistente!\n");
        return 0;
    }
    //return removeRec(raiz, elem);
    return removeIte(raiz, aluno);
}

void em_ordem(NO *raiz, int nivel){

    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%s, %d, %lf, %d] ", raiz->aluno.nome, raiz->aluno.mat, raiz->aluno.nota, nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){

    if(raiz != NULL){
        printf("[%s, %d, %lf, %d] ", raiz->aluno.nome, raiz->aluno.mat, raiz->aluno.nota, nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

int qtd_elementos(NO *raiz, int *cont){
    
    if(raiz != NULL){
        (*cont)++;
        qtd_elementos(raiz->esq, cont);
        qtd_elementos(raiz->dir, cont);
    }

    return *cont;
}

void pos_ordem(NO* raiz, int nivel){

    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("[%s, %d, %lf, %d] ", raiz->aluno.nome, raiz->aluno.mat, raiz->aluno.nota, nivel);
    }
}

void imprime(ABP* raiz){

    if(raiz == NULL) return;
    
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    
    printf("\nEm Ordem: "); em_ordem(*raiz, 0);
    printf("\nPre Ordem: "); pre_ordem(*raiz, 0);
    printf("\nPos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}

#endif