#include <stdio.h>
#include "conjunto.h"

int main(){

    struct Conjunto *conjunto1, 
    *conjunto2, *uniao,
    *interseccao, *diferenca1, *diferenca2;

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
    diferenca1 = diferenca_conjunto(conjunto2, conjunto1); 
    diferenca2 = diferenca_conjunto(conjunto1, conjunto2);

    imprime_conjunto(conjunto1);
    imprime_conjunto(conjunto2);

    //removendo o elemento 3 do conjunto1
    printf("Removendo o elemento 3 do conjunto1:");
    endl;
    remove_elemento(conjunto1,3);
    imprime_conjunto(conjunto1);
    
    //removendo o elemento 5 do conjunto2
    printf("Removendo o elemento 5 do conjunto2:");
    endl;
    remove_elemento(conjunto2,5);
    imprime_conjunto(conjunto2);

    printf("Printando o conjunto união e interseccao:");
    endl;
    imprime_conjunto(uniao);
    imprime_conjunto(interseccao);

    printf("Diferença entre os conjutos 2 e 1:");
    endl;
    imprime_conjunto(diferenca1);

    printf("Diferença entre os conjuntos 1 e 2:");
    endl;
    imprime_conjunto(diferenca2);
    





    
    limpa_conjunto(conjunto1);
    limpa_conjunto(conjunto2);
    limpa_conjunto(uniao);
    limpa_conjunto(interseccao);
    limpa_conjunto(diferenca1);
    limpa_conjunto(diferenca2);
    
    return 0;
}