#ifndef CONJUNTO_H  
#define CONJUNTO_H

#define endl printf("\n")
#define MAX 30

/*
• criar um conjunto vazio;

• intersecção entre dois conjuntos;
• diferença de dois conjuntos;
• união de dois conjuntos;

• inserir um elemento no conjunto;
• remover um elemento do conjunto;
• testar se um número pertence ao conjunto;
• menor valor do conjunto;
• maior valor do conjunto;
• testar se dois conjuntos são iguais;
• tamanho do conjunto;
• testar se o conjunto é vazio.
*/

struct Conjunto{
    int elementos[MAX];
    int qtd_elementos;
};

// OPERAÇÕES
struct Conjunto *cria_conjunto_vazio(struct Conjunto *conjunto);
struct Conjunto *uniao_conjunto(struct Conjunto *conjunto1, struct Conjunto *conjunto2);
struct Conjunto *interseccao_conjunto(struct Conjunto *conjunto1, struct Conjunto *conjunto2);
struct Conjunto *diferenca_conjunto(struct Conjunto *conjunto1, struct Conjunto *conjunto2);

//AÇÕES
int pertence_conjunto(struct Conjunto *conjunto, int elemento);
void insere_elemento(struct Conjunto *conjunto, int elemento);
void remove_elemento(struct Conjunto *conjunto, int elemento);
int menor_valor(struct Conjunto *conjunto);
int maior_valor(struct Conjunto *conjunto);
int conjunto_vazio(struct Conjunto *conjunto);
int conjunto_igual(struct Conjunto *conjunto1, struct Conjunto *conjunto2);
int tamanho_conjunto(struct Conjunto *conjunto);

void imprime_conjunto(struct Conjunto *conjunto);
void limpa_conjunto(struct Conjunto *conjunto);


#endif // CONJUNTO_H