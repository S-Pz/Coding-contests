#include<bits/stdc++.h>

#define endl '\n'
using namespace std;

int main(){

    int R;

    cin>> R;

    int Fib[R];

    Fib[0]=0;
    Fib[1]=1;

    for(int i=2; i<R;i++){
        Fib[i]=Fib[i-2]+Fib[i-1];
    }
    cout<< Fib[0];

    for(int i=1; i<R;i++){
        cout<<" ";
        cout<<Fib[i];
    }
    cout<< endl;
    return 0;
}