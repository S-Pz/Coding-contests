#include <stdio.h>
#include <stdlib.h>

#include "FilaDin.h"

int main(){

    Fila *F;
    int op;
    
    do{
        int elem;

        printf("0 - Sair");
        endl;
        printf("1 - Criar fila");
        endl;
        printf("2 - Enfileirar um item");
        endl;
        printf("3 - Ver o inicio da fila");
        endl;
        printf("4 - Desenfileirar um item");
        endl;
        printf("5 - Imprimir a fila");
        endl;
        printf("6 - Destruir a fila");
        endl;
        scanf("%d",&op);
        
        switch (op) {
            case 1:
                system("clear");
                F = cria_Fila();
                break;
            case 2:
                printf("Digite o valor que deseja enfileirar: ");
                endl;
                scanf("%d", &elem);
                insere_Fila(F, elem);
                system("clear");
                break;
            case 3:
                system("clear");
                inicio_Fila(F, &elem);
                printf("Frente: %d\n", elem);
                break;
            case 4:
                system("clear");
                remove_Fila(F);
                break;
            case 5:
                imprime(F);
                break;
            case 6:
                system("clear");
                libera_Fila(F);
                break;
        }
    }while(op != 0);
    return 0;
}