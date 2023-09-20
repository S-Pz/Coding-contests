#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encas.h"

struct ContaBancaria *inicializarConta(struct ContaBancaria *c){

    c = (struct ContaBancaria *)calloc(1,sizeof(struct ContaBancaria));

    return c;
}

void criarConta(struct ContaBancaria *c, int numero, char *titular){

    c->numero = numero;
    c->saldo = 0;

    strcpy(c->titular, titular);

    printf("Conta criada com sucesso!");
    endl;
    endl;  
}

void depositar(struct ContaBancaria *c, double valor){

    c->saldo += valor;

    printf("Deposito realizado com sucesso!");
    endl;
    endl;
}

void sacar(struct ContaBancaria *c, double valor){

    c->saldo -= valor;
}

double consultarSaldo(struct ContaBancaria *c){

    return c->saldo;
} 

void imprimirInfo(struct ContaBancaria *c){
    
    printf("________________________________________");
    endl;
    printf("Titular: %s", c->titular);
    printf("Numero: %d", c->numero);
    endl;
    printf("Saldo: %.2lf", c->saldo);
    endl;
    printf("________________________________________");
    endl;
}

void destruirConta(struct ContaBancaria *c){

    free(c);
}