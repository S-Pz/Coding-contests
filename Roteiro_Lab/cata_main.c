#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cata.h"

int main(){

    int qtd_prod, qtd_itens, op;
    char nome[100];
    double preco;

    struct CatalogoProdutos *catalogo;

    catalogo = criarCatalogo(catalogo);

    printf("Quantos produtos deseja adicionar ao catalogo? ");
    endl;
    scanf("%d",&qtd_itens);

    for(int i=0; i<qtd_itens; i++){

        printf("_____________________________________");
        endl;

        printf("Digite o nome do produto: %d",i+1);
        endl;

        while (getchar() != '\n'); 
        fgets(nome, sizeof(nome), stdin);

        printf("Digite o preco do produto: %d",i+1);
        endl;
        scanf("%lf",&preco);

        printf("Digite a quantidade do produto: %d",i+1);
        endl;
        scanf("%d",&qtd_prod);

        adicionarProduto(catalogo, nome, preco, qtd_prod);
    }

    printf("Digite 1 para verificar o estoque de um produto ou 2 para imprimir o catalogo: ");
    endl;
    scanf("%d",&op);

    switch (op){

        case 1:
            printf("Digite o nome do produto que deseja verificar: ");
            endl;
            
            while (getchar() != '\n');
            fgets(nome, sizeof(nome), stdin);
            
            printf("Se possui: %d",verificarEstoque(catalogo, nome));
            endl;
        break;
        case 2:    
            imprimirCatalogo(catalogo); 
        break;   
        default:
            printf("Opcao invalida!");
            endl;
        break;
    }

    limpaCatalogo(catalogo);

    return 0;
}