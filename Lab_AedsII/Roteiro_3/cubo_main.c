#include <stdio.h>

#include "cubo.h"

int main(){

    float dimensao;
    struct Cubo *cubo;

    printf("Digite a dimensao do cubo");
    endl;
    scanf("%f", &dimensao);
    endl;

    cubo = cria_cubo(cubo, dimensao);

    imprime_cubo(cubo);

    volume_cubo(cubo);

    area_cubo(cubo);

    libera_cubo(cubo);

    return 0;
}