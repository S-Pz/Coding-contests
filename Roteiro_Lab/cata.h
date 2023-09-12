#ifndef CATA_H
#define CATA_H

#define endl printf("\n")

struct Produto {

    char nome[50];
    float preco;
    int quantidade;
};

struct CatalogoProdutos {

    struct Produto Produtos[100];
    int qtdProdutos;
};
    
struct CatalogoProdutos *criarCatalogo(struct CatalogoProdutos *c);

void adicionarProduto(struct CatalogoProdutos *c, char *nome, double preco, int quantidade);

int verificarEstoque(struct CatalogoProdutos *c, char *nome);

void imprimirCatalogo(struct CatalogoProdutos *c);

void limpaCatalogo(struct CatalogoProdutos *c);

#endif // CATA_H