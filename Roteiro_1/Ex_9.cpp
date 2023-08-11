#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int N;
    while(true){

        cin >> N;

        int M[N][N];

        if(N == 0){
            break;
        }
        //Pensar que tenho que criar a matriz meio que de dentro para fora, para conseguir fazer as bordas.
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
            }
        }


        //print the matrix
        for(int i=0;i<N;i++){
        
            for(int j=0;j<N;j++){
                cout<<" "<< M[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}