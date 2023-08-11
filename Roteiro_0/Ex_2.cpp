#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int n, S, N = 0;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> S;
        N = S + N;
    }
    
    cout << N << endl;
    
    return 0;
}