#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int N,aux =0;
    cin >> N;

    for(int i=2; i<N;i++){
        if(N%i==0){
            aux++;
            break;
        }
    }    
    if(aux != 0 || N == 1 || N == 0){
        cout<<"nao"<<endl;
    }else {
        cout<<"sim"<<endl;
    }
    return 0;
}