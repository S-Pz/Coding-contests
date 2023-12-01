/*---------------- File: Heap Sort .c ------------------+
|Heap Sort                                              |
| Implementado por Guilherme C. Pena em 18/11/2023      |
+-------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp; 
int mov; 

int *copiaVetor(int* v, int n){
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

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2*pai + 1;
    
    while(filho <= fim){
        if(filho < fim){
            comp++;
            if(v[filho] < v[filho+1]){
                filho++;
            }
        }
        comp++;
        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
            mov++;
        }else {
            filho = fim + 1;
        }
    }
    v[pai] = aux;
    mov++;
}
void criaHeapMax(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2*pai + 1;
    
    while(filho <= fim){
        if(filho < fim){
            comp++;
            if(v[filho] > v[filho+1]){
                filho++;
            }
        }
        comp++;
        if(aux > v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
            mov++;
        }else {
            filho = fim + 1;
        }
    }
    v[pai] = aux;
    mov++;
}
void HeapSortMax(int *v, int n){
    int i;

    for(i=(n-1)/2; i>=0; i--)
        criaHeapMax(v, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        criaHeapMax(v, 0, i-1);
    }
}

void HeapSort(int *v, int n){
    int i;

    for(i=(n-1)/2; i>=0; i--)
        criaHeap(v, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        criaHeap(v, 0, i-1);
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
        HeapSort(v, n);
    t = clock() - t;

    printf("-----Heap Sort crescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v, n);

    comp = 0; mov = 0;

    t = clock();
        HeapSortMax(v2, n);
    t = clock() - t;

    printf("-----Heap Sort decrescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %ld\n", n*sizeof(int));

    imprimeVetor(v2, n);

    free(v);
    free(v2);

    return 0;
}