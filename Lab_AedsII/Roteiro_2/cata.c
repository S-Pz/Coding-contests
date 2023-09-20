#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cata.h"

struct CatalogoProdutos *criarCatalogo(struct CatalogoProdutos *c) {
    
    c = (struct CatalogoProdutos *) malloc(sizeof(struct CatalogoProdutos));
    c->qtdProdutos = 0;
    
    printf("Catálogo criado com sucesso!");
    endl;

    return c;
}

void adicionarProduto(struct CatalogoProdutos *c, char *nome, double preco, int quantidade) {

    if(c->qtdProdutos < 100){
        strcpy(c->Produtos[c->qtdProdutos].nome,nome);

        c->Produtos[c->qtdProdutos].preco = preco;
        c->Produtos[c->qtdProdutos].quantidade = quantidade;
        
        c->qtdProdutos ++;

        printf("Produto adicionado com sucesso!");
        endl;
    }else{
        printf("Catálogo cheio!");
        endl;
    }
}

int verificarEstoque(struct CatalogoProdutos *c, char *nome) {
    
    for(int i = 0; i < c->qtdProdutos; i++){
        if(strcmp(c->Produtos[i].nome,nome) == 0){
            return c->Produtos[i].quantidade;
        }
    }

    return -1;
}

void imprimirCatalogo(struct CatalogoProdutos *c) {
        
    for(int i = 0; i < c->qtdProdutos; i++){

        printf("_________________________________________________________");
        endl;
        printf("Nome: %s",c->Produtos[i].nome);
        printf("Preco: %.2lf",c->Produtos[i].preco);
        endl;
        printf("Quantidade: %d",c->Produtos[i].quantidade);
        endl;
        printf("_________________________________________________________");
        endl;
    }
}

void limpaCatalogo(struct CatalogoProdutos *c){

    free(c);
}
