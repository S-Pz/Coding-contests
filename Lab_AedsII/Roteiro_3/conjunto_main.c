#include <stdio.h>
#include "conjunto.h"

int main(){

    struct Conjunto *conjunto1, *conjunto2, *uniao, *interseccao, *diferenca;

    conjunto1 = cria_conjunto_vazio(conjunto1);
    conjunto2 = cria_conjunto_vazio(conjunto2);

    for(int i = 0; i < 5; i++){
        insere_elemento(conjunto1, i);
    }
    for (int j= 3; j<8; j++){
        insere_elemento(conjunto2, j);
    }

    uniao = uniao_conjunto(conjunto1, conjunto2);
    interseccao = interseccao_conjunto(conjunto1, conjunto2);
    diferenca = diferenca_conjunto(conjunto1, conjunto2); 

    imprime_conjunto(conjunto1);
    imprime_conjunto(conjunto2);

    printf("Printando o conjunto união e interseccao:");
    endl;
    imprime_conjunto(uniao);
    imprime_conjunto(interseccao);

    printf("Diferença entre os conjutos:");
    endl;
    imprime_conjunto(diferenca);

    limpa_conjunto(conjunto1);
    limpa_conjunto(conjunto2);

    limpa_conjunto(uniao);
    limpa_conjunto(interseccao);
    limpa_conjunto(diferenca);
    


    return 0;
}