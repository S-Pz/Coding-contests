/*---------------- File: Shell.c  ------------------+
|Shell Sort                                         |
| Implementado por Guilherme C. Pena em 20/11/2023  |
+---------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes
int mov; //Num. de movimentacoes

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void ShellSort(int *v, int n) {
  int i, j, atual;
  int h = 1;
  while(h < n) h = 3*h+1;
  while (h > 0) {
    for(i = h; i < n; i++) {
      atual = v[i];
      j = i;
      while (j > h-1 && atual <= v[j - h]) {
        comp ++;
        v[j] = v[j - h];
        mov++;
        j = j - h;
      }
      v[j] = atual;
      mov ++;
    }
    h = h/3;
  }
}
void ShellSortDe(int *v, int n) {
  int i, j, atual;
  int h = 1;
  while(h < n) h = 3*h+1;
  while (h > 0) {
    for(i = h; i < n; i++) {
      atual = v[i];
      j = i;
      while (j > h-1 && atual >= v[j - h]) {
        comp ++;
        v[j] = v[j - h];
        mov++;
        j = j - h;
      }
      v[j] = atual;
      mov ++;
    }
    h = h/3;
  }
}

int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    comp = 0; mov = 0;
    clock_t t;

    int *v,*v2;
    int n;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    v = (int*) malloc (n*sizeof(int));

    preencheAleatorio(v, n, 1, 100);
    v2 = copiaVetor(v, n);
    //imprimeVetor(v, n);
    
    
    t = clock();
        ShellSort(v, n);
    t = clock() - t;
    
    printf("-----Shell Sort crescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v, n);

    comp = 0; mov = 0;

    t = clock();
        ShellSortDe(v2, n);
    t = clock() - t;
    
    printf("-----Shell Sort decrescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v2, n);

    free(v);
    free(v2);

    return 0;
}