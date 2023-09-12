#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cata.h"

struct Produto {

    char nome[50];
    char codigo[10];
    float preco;
    int quantidade;
};

struct CatalogoProdutos {

    struct Produto Produtos[100];
    int qtdProdutos;
};

void criarCatalogo(struct CatalogoProdutos *c){
    
}