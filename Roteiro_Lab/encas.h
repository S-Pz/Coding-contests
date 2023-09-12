#ifndef ENCAS_H
#define ENCAS_H

#define endl printf("\n")

struct ContaBancaria {
    int numero;
    char titular[50];
    double saldo;
};

struct ContaBancaria *inicializarConta(struct ContaBancaria *conta);

void criarConta(struct ContaBancaria* conta, int numero, char *titular);

void depositar(struct ContaBancaria *conta, double valor);

void sacar(struct ContaBancaria *conta, double valor);

double consultarSaldo(struct ContaBancaria *conta);

void imprimirInfo(struct ContaBancaria *conta);

void destruirConta(struct ContaBancaria *conta);

#endif // ENCAS_H