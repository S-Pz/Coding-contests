#ifdef CATA_H
#define CATA_H

#define endl printf("\n")

struct Produto;
struct CatalogoProdutos ;
    
void criarCatalogo(struct CatalogoProdutos *c);

void adicionarProduto(struct CatalogoProdutos *c, char *nome, double preco, int quantidade);

int verificarEstoque(struct CatalogoProdutos *c, char *nome).

void imprimirCatalogo(struct CatalogoProdutos *c).

void limpaCatalogo(struct CatalogoProdutos *c)

#endif // CATA_H