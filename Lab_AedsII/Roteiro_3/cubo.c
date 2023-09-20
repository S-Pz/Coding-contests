#include <stdio.h>
#include <stdlib.h>

#include "cubo.h"

struct Cubo *cria_cubo(struct Cubo *cubo, float dimensao){

    cubo = (struct Cubo*) malloc(sizeof(struct Cubo));
    cubo->dimensao = dimensao;

    return cubo;
}
void imprime_cubo(struct Cubo *cubo){

    printf("Altura: %.2f", cubo->dimensao);
    endl;
    printf("Largura: %.2f", cubo->dimensao);
    endl;
    printf("Profundidade: %.2f", cubo->dimensao);
    endl;
}

void volume_cubo(struct Cubo *cubo){

    float volume = cubo->dimensao * cubo->dimensao * cubo->dimensao;

    printf("Volume do cubo: %.2f", volume);
    endl;
}

void area_cubo(struct Cubo *cubo){

    float area = 6 * (cubo->dimensao * cubo->dimensao);

    printf("Area do cubo: %.2f", area);
    endl;
}

void libera_cubo(struct Cubo *cubo){

    free(cubo);
}
