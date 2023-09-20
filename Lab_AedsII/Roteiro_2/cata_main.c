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

    while(1){

        printf("_____________________________________");
        endl;
        printf("Digite 0 para sair");
        endl;
        printf("Digite 1 para adicionar o produtos ao catalogo");
        endl;
        printf("Digite 2 para verificar o estoque de um produto");
        endl;
        printf("Digite 3 para imprimir o catalogo");
        endl;

        scanf("%d",&op);
        printf("_____________________________________");
        endl;
        
        if(op == 1){

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
        }
        if(op == 2){

            printf("Digite o nome do produto que deseja verificar: ");
            endl;
            
            while (getchar() != '\n');
            fgets(nome, sizeof(nome), stdin);
            
            printf("Se possui: %d",verificarEstoque(catalogo, nome));
            endl;
        }
        if(op == 3){
            imprimirCatalogo(catalogo);
        }

        if(op == 0){
            break;
        }
    }
    limpaCatalogo(catalogo);
    return 0;
}