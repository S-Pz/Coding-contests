#ifndef PSE_H
#define PSE_H

#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")

typedef struct NO {

  int info;
  struct NO *prox;

} NO;

typedef struct {

  int qtd;
  struct NO *topo;

} Pilha;

Pilha *cria_Pilha();
void libera_Pilha(Pilha *pi);
void imprime_Pilha(Pilha *pi);

int ver_Topo(Pilha *pi);
int insere_Pilha(Pilha *pi, int val);
int remove_Pilha(Pilha *pi);
int tamanho_Pilha(Pilha *pi);
int pilha_Vazia(Pilha *pi);
int pilha_Cheia(Pilha *pi);


#endif