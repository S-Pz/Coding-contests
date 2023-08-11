#include<bits/stdc++.h>

#define endl "\n"

using namespace std;

int main(){

    int N, aux =0;

    while (true) {
        cin >> N;

        char name1[11], name2[11];
        int A,B,par=0, impar=0;
        
        if(N == 0){
            break;
        }
        
        cin >> name1 >> name2;
        aux ++;
        cout << "Teste "<<aux<<endl;

        for(int i=0; i<N; i++){
            cin >> A >> B;

            if((A+B)%2 == 0){
                cout<<name1<<endl;
            }else{
                cout << name2<<endl;
            }
        }        
        cout << endl;
    }
    return 0;
}