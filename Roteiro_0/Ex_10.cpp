#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    int N,A,C,aux;
    char B;
    cin >> N>> A>> B>> C;

    switch (B) {
        case '*':
            aux = A * C;
        break;
        case '+':
            aux = A + C;
        break;
    }

    if(aux>N){
        cout << "OVERFLOW" << endl;
    }else {
        cout << "OK" << endl;
    }
    
    return 0;
}