#ifndef FSE_H
#define FSE_H

#define endl printf("\n")

typedef struct NO {

  int info;
  struct NO *prox;
  
} NO;

typedef struct {

  int qtd;
  struct NO *ini,*fim;
 
}Fila;

Fila *cria_Fila();
void libera_Fila(Fila *fi);
void imprime(Fila *fi);

int inicio_Fila(Fila *fi, int *no);
int insere_Fila(Fila *fi, int val);
int remove_Fila(Fila *fi);
int tamanho_Fila(Fila *fi);
int Fila_vazia(Fila *fi);
int Fila_cheia(Fila *fi);



#endif