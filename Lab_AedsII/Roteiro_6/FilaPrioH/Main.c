#include "FilaPrioH.h"

int main(){

    FilaP *F;
    int op;

    do{
        int elem, pri;

        printf("0 - Sair");
        endl;
        printf("1 - Criar Fila");
        endl;
        printf("2 - Inserir um item pela prioridade");
        endl;
        printf("3 - Ver o inicio da Fila");
        endl;
        printf("4 - Remover um item");
        endl;
        printf("5 - Imprimir a Fila");
        endl;
        printf("6 - Mostrar o tamanho da Fila");
        endl;
        printf("7 - Destruir a Fila");
        endl;

        scanf("%d", &op);

        switch (op) {
            case 1:
                system("clear");
                F = criaFila();
                break;
            case 2:
                printf("Digite o valor que deseja inserir e sua prioridade:");
                endl;
                scanf("%d %d", &elem, &pri);
                inserirPrio(F, elem, pri);
                system("clear");
                break;
            case 3:
                verIni(F, &elem , &pri);
                system("clear");
                printf("Inicio: %d %d\n", elem, pri);
                break;
            case 4:
                system("clear");
                removeIni(F);
                break;
            case 5:
                imprime(F);
                break;
            case 6:
                system("clear");
                printf("Tamanho da fila %d:", tamanhoFila(F));
                break;
            case 7:
                destroiFila(F);
                break;
        }
    }while(op != 0);
    return 0;
}