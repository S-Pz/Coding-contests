/*---------------- File: Merge.c  ----------------------+
|Merge Sort                                             |
| Implementado por Guilherme C. Pena em 08/11/2023      |
+-------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *numbers;
int comp, mov, numMax; 

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

void Merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    //Vetor Auxiliar - A
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] < v[j]){A[k] = v[i]; i++; comp++;mov++;}
        else {A[k] = v[j];j++;comp++;mov++;}
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++;comp++; mov++;}
    while (j<=fim) { A[k] = v[j];  j++;  k++;comp++; mov++;}
    for(i = ini, k=0; i<=fim; i++, k++) v[i] = A[k];
    free(A);
}

void MergeSort(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}
void MergeDE(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    //Vetor Auxiliar - A
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] > v[j]){ A[k] = v[i]; i++; comp++; mov++; }
        else { A[k] = v[j]; j++; comp++; mov++; }
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; mov++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; mov++; }
    for(i = ini, k=0; i<=fim; i++, k++) v[i] = A[k];
    free(A);
}

void MergeSortDE(int *v, int ini, int fim){
    
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSortDE(v, ini, meio);
        MergeSortDE(v, meio+1, fim);
        MergeDE(v, ini, meio, fim);
    }
}

int fil(){

    //FILE *file = fopen("testFile/10000-misturado.txt", "r");
    //FILE *file = fopen("testFile/10000-contrario.txt", "r");
    //FILE *file = fopen("testFile/10000-ordenado.txt", "r");
    FILE *file = fopen("testFile/10000-quaseordenado.txt", "r");

    if (file == NULL) {
        printf("ERRO");
        return 1;
    }

    fscanf(file,"%d",&numMax);

    numbers = (int*) malloc (numMax*sizeof(int));

    int i = 0;

    while (fscanf(file, "%d", &numbers[i]) != EOF && i < numMax) {
        //printf("%d",numbers[i]);
        i++;
    }

    fclose(file);

    return 0;
}

int main(){

    fil();

    //Atribuicoes iniciais
    srand(time(NULL));
    comp = 0; mov = 0;
    clock_t t;

    int *v2;
    int n;
    
    // printf("Digite o tamanho do vetor:\n");
    // scanf("%d", &n);
    
    //v = (int*) malloc (n*sizeof(int));

    //preencheAleatorio(v, n, 1, 100);
    v2 = copiaVetor(numbers, numMax);

    //imprimeVetor(v, n);
    
    t = clock();
        MergeSort(numbers, 0, numMax-1);
    t = clock() - t;
    
    printf("-----Merge Sort crescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %d\n", n*sizeof(int));

    //imprimeVetor(numbers, numMax);

    comp = 0; mov = 0;

    t = clock();
        MergeSortDE(v2, 0, numMax-1);
    t = clock() - t;
    
    printf("-----Merge Sort decrescente:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    printf("Movimentacoes: %d\n", mov);
    printf("Memoria (bytes): %d\n", n*sizeof(int));

    //imprimeVetor(v2, numMax);

    free(v2);

    return 0;
}