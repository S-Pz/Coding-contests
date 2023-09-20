#ifndef CUBO_H 
#define CUBO_H

#define endl printf("\n")

struct Cubo{
    float dimensao;
};

struct Cubo *cria_cubo(struct Cubo *cubo, float dimensao);

void imprime_cubo(struct Cubo *cubo);
void volume_cubo(struct Cubo *cubo);
void area_cubo(struct Cubo *cubo);
void libera_cubo(struct Cubo *cubo);

#endif // CUBO_H