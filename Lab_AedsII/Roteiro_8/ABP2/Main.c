#include "Abp.h"
#include <stdio.h>

#define endl printf("\n")

int main(){

    ABP* A;
    Aluno aluno, busca;

    int *cont = (int*) calloc(1,sizeof(int));
    char nome[100];
    double nota = 0.0;
    int op, mat;

    do{
        
        int elem;

        printf("0 - Sair");
        endl;
        printf("1 - Criar ABP");
        endl;
        printf("2 - Inserir um Aluno");
        endl;
        printf("3 - Buscar um Aluno pelo nome e imprimir suas informações");
        endl;
        printf("4 - Remover um Aluno pelo nome");
        endl;
        printf("5 - Imprimir a ABP em ordem");
        endl;
        printf("6 - Imprimir as informações do aluno com a maior nota");
        endl;
        printf("7 - Imprimir as informações do aluno com a menor nota");
        endl;
        printf("8 - Mostrar a quantidade de nos na ABP");
        endl;
        printf("9 - Destruir a ABP");
        endl;

        scanf("%d", &op);

        switch (op) {
            case 1:
               A = criaABP();
               printf("ABP criada com sucesso");
               endl;
                break;
            case 2:
                
                printf("Digite o nome do aluno:");
                endl;
                while (getchar() != '\n'); 
                fgets(nome, sizeof(nome), stdin);

                printf("Digite a matricula do aluno:");
                endl;
                scanf("%d", &mat);

                printf("Digite a nota do aluno:");
                endl;
                scanf("%lf", &nota);

                strcpy(aluno.nome,nome);
                aluno.mat = mat;
                aluno.nota = nota;

                insereElem(A, aluno);
                break;
            case 3:
                
                printf("Digite o nome do aluno que deseja procurar:");
                while (getchar() != '\n'); 
                fgets(nome, sizeof(nome), stdin);
                
                strcpy(aluno.nome, nome);

                if(pesquisa(A, aluno)){
                    printf("Nome aluno: %s \nMatricula: %d \nNota: %lf", aluno.nome, aluno.mat, aluno.nota);
                    endl;
                }else{
                    printf("Aluno nao encontrado");
                    endl;
                }
                break;
            case 4:
                printf("Digite o nome do aluno que deseja remover:");
                while (getchar() != '\n'); 
                fgets(nome, sizeof(nome), stdin);

                strcpy(aluno.nome, nome);

                removeElem(A, aluno);
                break;
            case 5:
                em_ordem(*A, 0);
                endl;
                break;
            case 6:
                menorNota(*A);
                endl;
                break;
            case 7:
                maiorNota(*A);
                endl;
                break;
            case 8:
                *cont = 0;
                printf("Qtd elementos: %d", qtd_elementos(*A, cont));
                endl;
                break;
            case 9:
                printf("Destruindo árvore!");
                endl;
                destroiABP(A);
                break;
        }

    }while(op != 0);

    free(cont);

    return 0;
}

