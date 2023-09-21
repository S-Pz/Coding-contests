#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int N, M;

    cin >> N >> M;

    int matriz[N][M], somaColuna[M], somaLinha[N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matriz[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        somaLinha[i] = 0;
        for(int j = 0; j < M; j++){
            somaLinha[i] += matriz[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        somaColuna[i] = 0;
        for(int j = 0; j < N; j++){
            somaColuna[i] += matriz[j][i];
        }
    }
    
    int maiorLinha = 0;
    for(int i = 0; i < N; i++){
        if(somaLinha[i] > maiorLinha){
            maiorLinha = somaLinha[i];
        }
    }

    int maiorColuna = 0;
    for(int i = 0; i < M; i++){
        if(somaColuna[i] > maiorColuna){
            maiorColuna = somaColuna[i];
        }
    }

    if(maiorLinha > maiorColuna){
        cout << maiorLinha << endl;
    }else{
        cout << maiorColuna << endl;
    }
    
    return 0;
}