#include <bits/stdc++.h>
#include <vector>

#define endl '\n'

using namespace std;

int main(){
    
    int N,n_teste = 1;

    while(cin >> N && N != 0){
        int Array[N];

        for(int i = 1; i <= N; i++){
            int input;
            cin >> input;
            Array[i] = input;
        }
        for(int i = 1; i <= N; i++){
            if(Array[i] == i){
                cout << "Teste " << n_teste << endl;
                cout << Array[i] << endl;
                cout << endl;
                n_teste++;
                break;
            }
        }
    }
}