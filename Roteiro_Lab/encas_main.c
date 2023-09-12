#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encas.h"

int main(){

    struct ContaBancaria *c1;
    int num_conta;

    char nome[50];

    double depo, saq;

    c1 = inicializarConta(c1);

    printf("Digite o numero da conta: ");
    endl;
    scanf("%d", &num_conta);

    printf("Digite o nome do titular: ");
    endl;

    while (getchar() != '\n'); 
    fgets(nome, sizeof(nome), stdin);

    criarConta(c1, num_conta, nome);
    
    printf("Digite o valor do deposito: ");
    endl;
    scanf("%lf", &depo);
    
    depositar(c1, depo);
    printf("Saldo antes do saque: %.2lf", consultarSaldo(c1));
    endl;

    printf("Digite o valor do saque: ");
    endl;
    scanf("%lf", &saq);
    
    sacar(c1, saq);
    printf("Saldo depois do saque: %.2lf", consultarSaldo(c1));
    endl;
    

    imprimirInfo(c1);
    destruirConta(c1);

    return 0;
}