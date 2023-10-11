#include "DequeDim.h"
#include <stdlib.h>

int main () {

    Deque *D;
    int op;

    do{
        int elem;

        printf("0 - Sair");
        endl;
        printf("1 - Criar Deque");
        endl;
        printf("2 - Inserir um item no fim");
        endl;
        printf("3 - Inserir um item no inicio");
        endl;
        printf("4 - Ver o inicio do Deque");
        endl;
        printf("5 - Ver o fim do Deque");
        endl;
        printf("6 - Remover um item do inicio");
        endl;
        printf("7 - Remover um item do fim");
        endl;
        printf("8 - Imprimir o Deque");
        endl;
        printf("9 - Destruir o Deque");
        endl;
        printf("10 - Tamanho do Deque");
        endl;

        scanf("%d",&op);
        
        switch (op) {
            case 1:
                system("clear");
                D = criaDeque();
                break;
            case 2:
                printf("Digite o valor que deseja inserir no fim: ");
                endl;
                scanf("%d", &elem);
                insereFim(D, elem);
                system("clear");
                break;
            case 3:
                printf("Digite o valor que deseja inserir no inicio: ");
                endl;
                scanf("%d", &elem);
                insereIni(D, elem);
                system("clear");
                break;
            case 4:
                verInicio(D, &elem);
                system("clear");
                printf("Inicio: %d\n", elem);
                break;
            case 5:
                verFim(D, &elem);
                system("clear");
                printf("Fim: %d\n", elem);
                break;
            case 6:
                system("clear");
                removeIni(D);
                break;
            case 7:
                system("clear");
                removeFim(D);
                break;
            case 8:
                imprime(D);
                break;
            case 9:
                destroiDeque(D);
                break;
            case 10:
                system("clear");
                tamanhoDeque(D);
                break;
        }
    }while(op != 0);   

    return 0;
}