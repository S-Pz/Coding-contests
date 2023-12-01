/*---------------- File: Quick.c  ---------------+
|Quick Sort                                      |
|Implementado por Guilherme C. Pena em 14/11/2023|
+------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp; 
int mov; 

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
    for(i=0; i<n; i++){
        v[i] = ini + rand() % (fim-ini + 1); 
        //v[i] = (n-i); //Para o pior caso
    }
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

//Versao do livro
int particiona(int *v, int ini, int fim){
    int esq, dir, pivo, aux;
    esq = ini; dir = fim;
    pivo = v[ini];

    while(esq < dir){
        while(esq <= fim && v[esq] <= pivo) esq++;
        while(dir >= 0 && v[dir] > pivo) dir--;
        if(esq < dir) troca(&v[esq], &v[dir]);
    }
    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        comp++;
        while(v[i] < pivo){ i++; comp++; } 
        
        comp++;
        while(v[j] > pivo){ j--; comp++;} 
        
        if(i<j){
            troca(&v[i], &v[j]); 
            mov++;
            i++;
            j--;
        }else
            return j; 
    }    
}
int particaoDe(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];

    while (1) {
        comp++;
        while(v[i] > pivo){ i++; comp++; } 
        
        comp++;
        while(v[j] < pivo){ j--; comp++;} 
        
        if(i<j){
            troca(&v[i], &v[j]); 
            mov++;
            i++;
            j--;
        }else
            return j; 
    }    
}
void QuickSortDe(int *v, int ini, int fim, int n){
    if(ini < fim ){
        int q = particaoDe(v, ini, fim);
        //printf("Parts: (%d, %d) e (%d, %d): ", ini, q, q+1, fim);
        //imprimeVetor(v, n);
        QuickSortDe(v, ini, q, n);
        QuickSortDe(v, q+1, fim, n);
    }
}

void QuickSort(int *v, int ini, int fim, int n){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        //printf("Parts: (%d, %d) e (%d, %d): ", ini, q, q+1, fim);
        //imprimeVetor(v, n);
        QuickSort(v, ini, q, n);
        QuickSort(v, q+1, fim, n);
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
        QuickSort(v, 0, n-1, n);
    t = clock() - t;
    
    printf("-----Quick Sort crescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v, n);

    comp = 0; mov = 0;

    t = clock();
        QuickSortDe(v2, 0, n-1, n);
    t = clock() - t;
    
    printf("-----Quick Sort decrescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v2, n);

    free(v);
    free(v2);

    return 0;
}