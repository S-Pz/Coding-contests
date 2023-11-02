/*---------------- File: AVL.h  ------------------------+
|Arvore AVL, cadastro de funcionario                                            |
|					      		                        |
|					      		                        |
| Implementado com base no codigo disponibilizado       |
+-------------------------------------------------------+ */

#ifndef AVL_H
#define AVL_H

#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>

#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct Funcionario{
    char nome[100];
    double salario;
    int ano;

}Funcionario;

typedef struct NO{
    int fb, alt;
    Funcionario funcionario;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* AVL;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

AVL* criaAVL(){
    AVL* raiz = (AVL*) malloc (sizeof(AVL));
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

void destroiAVL(AVL* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(AVL* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

//Calcula FB
int altura(NO* raiz){
    
    if(raiz == NULL) return 0;
    
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        //printf("Calculando altura do (%d)..\n", raiz->info);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    
    if(raiz == NULL) return 0;
    printf("Calculando FB do (%s)..\n", raiz->funcionario.nome);
    
    return altura(raiz->esq) - altura(raiz->dir);
}

//Funcoes de Rotacao Simples
void avl_RotDir(NO** raiz){

   printf("Rotacao Simples a DIREITA!\n");
   NO *aux;
   aux = (*raiz)->esq;
   (*raiz)->esq = aux->dir;
   aux->dir = *raiz;
   
   //Acertando alturas e FB
   //dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);

   *raiz = aux;
}

void avl_RotEsq(NO** raiz){

   printf("Rotacao Simples a ESQUERDA!\n");
   NO *aux;
   aux = (*raiz)->dir;
   (*raiz)->dir = aux->esq;
   aux->esq = *raiz;
   
   //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);
   
   *raiz = aux;
}


//Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO** raiz){

    printf("Rotacao Dupla ESQUERDA-DIREITA!\n");
    NO *fe; //filho esquerdo
    NO *ffd; //filho filho direito
    
    fe = (*raiz)->esq;
    ffd = fe->dir;
    
    fe->dir = ffd->esq;
    ffd->esq = fe;
    
    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}


void avl_RotDirEsq(NO** raiz){

    printf("Rotacao Dupla DIREITA-ESQUERDA!\n");
    
    NO* fd; //filho direito
    NO* ffe; //filho filho esquerdo

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    printf("Rotacao Dupla 2 ESQUERDA-DIREITA!\n");
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    printf("Rotacao Dupla 2 DIREITA-ESQUERDA!\n");
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}


//Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz){
   NO* fe;
   fe = (*raiz)->esq;
   if(fe->fb == +1) /* Sinais iguais e positivo*/
     avl_RotDir(raiz);
   else /* Sinais diferentes*/
     avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
   NO* fd;
   fd = (*raiz)->dir;
   if(fd->fb == -1) /* Sinais iguais e negativos*/
     avl_RotEsq(raiz);
   else /* Sinais diferentes*/
     avl_RotDirEsq(raiz);
}

int insereRec(NO** raiz, Funcionario funcionario){
    
    int ok; //Controle para as chamadas recursivas
    
    if(*raiz == NULL){
        
        NO* novo = alocarNO();
        
        if(novo == NULL){ 
            return 0;
        }
        
        novo->funcionario = funcionario; novo->fb = 0, novo->alt = 1;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo; 
        
        return 1;
    }else{
        
        if((*raiz)->funcionario.salario == funcionario.salario){
            printf("Elemento Existente!\n");
            ok = 0;
        }
        if(funcionario.salario < (*raiz)->funcionario.salario){
            ok = insereRec(&(*raiz)->esq, funcionario);
            
            if(ok){
                switch((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0; ok = 0; 
                        break;
                    case 0:
                        (*raiz)->fb = +1; 
                        (*raiz)->alt++; 
                        break;
                    case +1:
                        avl_AuxFE(raiz); ok = 0; 
                        break;
                }
            }
        }else if(funcionario.salario > (*raiz)->funcionario.salario){
            ok = insereRec(&(*raiz)->dir, funcionario);
            
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0; ok = 0; 
                        break;
                    case 0:
                        (*raiz)->fb = -1; (*raiz)->alt++; 
                        break;
                    case -1:
                        avl_AuxFD(raiz); ok = 0; 
                        break;
                }
            }
        }
    }
    return ok;
}

int insereElem(AVL *raiz, Funcionario funcionario){
    if(raiz == NULL) return 0;
    return insereRec(raiz, funcionario);
}

int pesquisaRec(NO** raiz, Funcionario funcionario){
    
    if(*raiz == NULL) return 0;

    if((*raiz)->funcionario.salario == funcionario.salario){
        return 1;
    }
    
    if(funcionario.salario < (*raiz)->funcionario.salario){
        return pesquisaRec(&(*raiz)->esq, funcionario);
    
    }else {
        return pesquisaRec(&(*raiz)->dir, funcionario);
    }   
}

int pesquisa(AVL* raiz, Funcionario funcionario){
    
    if(raiz == NULL) return 0;
    
    if(estaVazia(raiz)) return 0;
    
    return pesquisaRec(raiz, funcionario);
}

int removeRec(NO** raiz, Funcionario funcionario){
    
    if(*raiz == NULL) return 0;
    int ok;
    
    if((*raiz)->funcionario.salario == funcionario.salario){
        NO* aux;
        
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            printf("Caso 1: Liberando %s..\n", (*raiz)->funcionario.nome);
            printf("Caso 1: Liberando %lf..\n", (*raiz)->funcionario.salario);
            printf("Caso 1: Liberando %d..\n", (*raiz)->funcionario.ano);
            
            liberarNO(*raiz);
            *raiz = NULL;

        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            
            printf("Caso 2.1: Liberando %s..\n", (*raiz)->funcionario.nome);
            printf("Caso 2.1: Liberando %lf..\n", (*raiz)->funcionario.salario);
            printf("Caso 2.1: Liberando %d..\n", (*raiz)->funcionario.ano);
            
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);

        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            
            printf("Caso 2.2: Liberando %s..\n", (*raiz)->funcionario.nome);
            printf("Caso 2.2: Liberando %lf..\n", (*raiz)->funcionario.salario);
            printf("Caso 2.2: Liberando %d..\n", (*raiz)->funcionario.ano);
            
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);

        }else{
            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            
            printf("Caso 3: Liberando %s..\n", (*raiz)->funcionario.nome);
            printf("Caso 3: Liberando %lf..\n", (*raiz)->funcionario.salario);
            printf("Caso 3: Liberando %d..\n", (*raiz)->funcionario.ano);
            
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;

            //Localiza o MAIOR valor da subarvore esquerda
            while(Filho->dir != NULL){
                Filho = Filho->dir;
            }
            
            (*raiz)->funcionario = Filho->funcionario;
            Filho->funcionario = funcionario;
            
            return removeRec(&(*raiz)->esq, funcionario);
        }
        return 1;

    }else if(funcionario.salario < (*raiz)->funcionario.salario){
        
        ok = removeRec(&(*raiz)->esq, funcionario); 
        
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); 
                    break;
            }
        }
    }else{ 
        
        ok = removeRec(&(*raiz)->dir, funcionario);
        
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); 
                    break;
            }
        }
    }
    return ok;
}
void maiorSalario(NO *raiz){

    if(raiz == NULL){
        return ;
    }

    while (raiz->dir != NULL){

        raiz = raiz->dir;
    }

    printf("Funcionario com maior salario:\n");
    printf("Nome: %s\n", raiz->funcionario.nome);
    printf("Salario: %.2f\n", raiz->funcionario.salario);
    printf("Ano de contratacao: %d\n", raiz->funcionario.ano);
    
}
void menorSalario(NO *raiz){

    if(raiz == NULL){
        return;
    }
    while (raiz ->esq != NULL){
        raiz = raiz->esq;
    }

    printf("Funcionario com menor salario:\n");
    printf("Nome: %s\n", raiz->funcionario.nome);
    printf("Salario: %.2f\n", raiz->funcionario.salario);
    printf("Ano de contratacao: %d\n", raiz->funcionario.ano);
}

int removeElem(AVL *raiz, Funcionario funcionario){
    
    if(pesquisa(raiz, funcionario) == 0){
        printf("Elemento inexistente!\n");
        
        return 0;
    }
    return removeRec(raiz, funcionario);
}

void em_ordem(NO* raiz, int nivel){
    
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        //printf("[%d, %d, %d] ", raiz->info, raiz->fb, nivel);
        printf("[%s, %lf, %d, %d, %d, %d] ", raiz->funcionario.nome, raiz->funcionario.salario, raiz->funcionario.ano, raiz->fb, nivel, raiz->alt);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    
    if(raiz != NULL){
        printf("[%s, %lf, %d, %d, %d, %d] ", raiz->funcionario.nome, raiz->funcionario.salario, raiz->funcionario.ano, raiz->fb, nivel, raiz->alt);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("[%s, %lf, %d, %d, %d, %d] ", raiz->funcionario.nome, raiz->funcionario.salario, raiz->funcionario.ano, raiz->fb, nivel, raiz->alt);
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

void imprime(AVL* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    //printf("\nEm Ordem: [INFO, FB, NIVEL]\n"); 
    printf("\nEm Ordem: [INFO, FB, NIVEL, altura]\n"); 
    em_ordem(*raiz, 0);
    //printf("\nPre Ordem: "); pre_ordem(*raiz, 0);
    //printf("\nPos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}


#endif