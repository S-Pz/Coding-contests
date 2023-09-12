#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cata.h"

int main(){

    struct CatalogoProdutos *catalogo;

    catalogo = criarCatalogo(catalogo);

    adicionarProduto(catalogo,"Arroz",5.50,10);
    adicionarProduto(catalogo,"Feijao",4.50,10);
    adicionarProduto(catalogo,"Macarrao",3.50,10);
    adicionarProduto(catalogo,"Carne",30.50,10);
    adicionarProduto(catalogo,"Frango",20.50,10);


    imprimirCatalogo(catalogo);    

    limpaCatalogo(catalogo);

    return 0;
}