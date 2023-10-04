#include <stdio.h>
#include "PE.h"

#define endl printf("\n")

int main(){

    Pilha *P;
    int op;

    do {
        int elem;

        printf("0 - Sair");
        endl;
        printf("1 - Criar pilha");
        endl;
        printf("2 - Empilhar um item");
        endl;
        printf("3 - Ver o topo da pilha");
        endl;
        printf("4 - Desempilhar um item");
        endl;
        printf("5 - Imprimir a pilha");
        endl;
        printf("6 - Destruir a pilha");
        endl;
        scanf("%d",&op);

        switch (op) {
            case 1:
                system("clear");
                P = criaPilha();
                break;
            case 2:
                printf("Digite o valor que deseja empilhar: ");
                endl;
                scanf("%d", &elem);
                empilhar(P, elem);
                system("clear");
                break;
            case 3:
                system("clear");
                verTopo(P, &elem);
                printf("Topo: %d\n", elem);
                break;
            case 4:
                system("clear");
                desempilhar(P);
                break;
            case 5:
                imprime(P);
                break;
            case 6:
                destroiPilha(P);
                break;
        }
    }while (op != 0);
    return 0;
}