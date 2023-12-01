#include "Avl.h"
#include <string.h>

#define endl printf("\n")

int main(){

    AVL* A;
    Funcionario funcionario;

    int *cont = (int*) calloc(1,sizeof(int));

    char nome[100];
    double salario = 0.0;
    int op, ano;

    do{
    
        printf("0 - Sair");
        endl;
        printf("1 - Criar AVL");
        endl;
        printf("2 - Inserir um Funcionário pelo salário");
        endl;
        printf("3 - Buscar um Funcionário pelo salario e imprimir suas informações");
        endl;
        printf("4 - Remover um Funcionário pelo nome");
        endl;
        printf("5 - Imprimir a AVL em ordem");
        endl;
        printf("6 - Imprimir as informações do Funcionário com o maior salário");
        endl;
        printf("7 - Imprimir as informações do Funcionário com o menor salário");
        endl;
        printf("8 - Mostrar a quantidade de nos na AVL");
        endl;
        printf("9 - Destruir a AVL");
        endl;

        scanf("%d", &op);

        switch (op) {
            case 1:
               A = criaAVL();
               printf("AVL criada com sucesso");
               endl;
                break;
            case 2:
                
                printf("Digite o nome do funcionario:");
                endl;
                while (getchar() != '\n'); 
                fgets(nome, sizeof(nome), stdin);

                printf("Digite o salario do funcionario:");
                endl;
                scanf("%lf", &salario);

                printf("Digite o ano de contratacao do funcionario:");
                endl;
                scanf("%d", &ano);

                strcpy(funcionario.nome, nome);
                
                funcionario.salario = salario;
                funcionario.ano = ano;

                insereElem(A, funcionario);
                break;
            case 3:
                
                printf("Digite o nome do funcionario que deseja procurar:");
                while (getchar() != '\n'); 
                fgets(nome, sizeof(nome), stdin);
                
                strcpy(funcionario.nome, nome);

                if(pesquisa(A, funcionario)){
                    printf("Nome funcionario: %s \nSalario: %lf \nAno de contratacao: %d", funcionario.nome, funcionario.salario, funcionario.ano);
                    endl;
                }else{
                    printf("Funcionario nao encontrado");
                    endl;
                }
                break;
            case 4:
                printf("Digite o nome do funcionario que deseja remover:");
                while (getchar() != '\n'); 
                fgets(nome, sizeof(nome), stdin);

                strcpy(funcionario.nome, nome);

                removeElem(A, funcionario);
                break;
            case 5:
                em_ordem(*A, 0);
                endl;
                break;
            case 6:
                menorSalario(*A);
                endl;
                break;
            case 7:
                maiorSalario(*A);
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
                destroiAVL(A);
                break;
        }

    }while(op != 0);

    free(cont);

    return 0;
}
