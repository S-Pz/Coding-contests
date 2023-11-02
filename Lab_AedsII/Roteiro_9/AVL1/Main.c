#include "Avl.h"

#define endl printf("\n")

int main(){

    AVL *A;
    int op;
    int *cont = (int*) calloc(1,sizeof(int));

    do{
        
        int elem;

        printf("0 - Sair");
        endl;
        printf("1 - Criar AVL");
        endl;
        printf("2 - Inserir um elemento");
        endl;
        printf("3 - Buscar um elemento");
        endl;
        printf("4 - Remover um elemento");
        endl;
        printf("5 - Imprimir a AVL em ordem");
        endl;
        printf("6 - Mostrar a quantidade de nos na AVL");
        endl;
        printf("7 - Destruir a AVL");
        endl;

        scanf("%d", &op);

        switch (op) {
            case 1:
               A = criaAVL();
               printf("AVL criada com sucesso");
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
            /*
            case 6:
                pre_ordem(*A, 0);
                endl;
                break;
            case 7:
                pos_ordem(*A, 0);
                endl;
                break;
            */
            case 6:
                *cont = 0;
                printf("Qtd elementos: %d", qtd_elementos(*A, cont));
                endl;
                break;
            case 7:
                printf("Destruindo arvore!");
                endl;
                destroiAVL(A);
                break;
        }

    }while(op != 0);

    free(cont);
    return 0;
}