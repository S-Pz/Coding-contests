#include<bits/stdc++.h>
#include <cstdio>

#define endl '\n'

using namespace std;

long long fatorial(int f){

    long long R;
    
    R = (long long)f;
    if (f == 0) {
        R = 1;
    }else {

        for (long i = 1; i <= f; i++){

            if (f-i == 0) {
                break;
            }

            R = (f-i) * R;
        }
    }

    return R;
}

int main(){

    int M,N;
    
    while (scanf("%d %d", &M, &N) != EOF){
        long long sum;
        
        sum = fatorial(M) + fatorial(N);
        cout<< sum << endl;
    }

    return 0;
}