#include "Abp.h"

#define endl printf("\n")


int main(){

    ABP* A;;
    int op;
    int *cont = (int*) calloc(1,sizeof(int));

    do{
        
        int elem;

        printf("0 - Sair");
        endl;
        printf("1 - Criar ABP");
        endl;
        printf("2 - Inserir um elemento");
        endl;
        printf("3 - Buscar um elemento");
        endl;
        printf("4 - Remover um elemento");
        endl;
        printf("5 - Imprimir a ABP em ordem");
        endl;
        printf("6 - Imprimir a ABP em pre-ordem");
        endl;
        printf("7 - Imprimir a ABP em pos-ordem");
        endl;
        printf("8 - Mostrar a quantidade de nos na ABP");
        endl;
        printf("9 - Destruir a ABP");
        endl;

        scanf("%d", &op);

        switch (op) {
            case 1:
               A = criaABP();
               printf("ABP criada com sucesso");
               endl;
                break;
            case 2:
                printf("Digite o elemento que deseja inserir:");
                scanf("%d", &elem);
                insereElem(A, elem);
                break;
            case 3:
                printf("Digite o elemento que deseja procurar:");
                scanf("%d", &elem);
                pesquisa(A, elem);
                break;
            case 4:
                printf("Digite o elemento que deseja remover:");
                scanf("%d",&elem);
                removeElem(A, elem);
                break;
            case 5:
                em_ordem(*A, 0);
                endl;
                break;
            case 6:
                pre_ordem(*A, 0);
                endl;
                break;
            case 7:
                pos_ordem(*A, 0);
                endl;
                break;
            case 8:
                *cont = 0;
                printf("Qtd elementos: %d", qtd_elementos(*A, cont));
                endl;
                break;
            case 9:
                printf("Destruindo árvore!");
                endl;
                destroiABP(A);
                break;
        }

    }while(op != 0);

    free(cont);

    return 0;
}