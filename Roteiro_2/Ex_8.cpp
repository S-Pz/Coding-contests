
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main (){

    long  N, Q;
    cin >> N >> Q;

    vector<long long> Array(N);

    for(int i=0; i<N; i++){
        long long  num;
        cin >> num;
        Array.push_back(num);
    }

    long long in;
    
    while(Q--){

        cin >> in;

        vector<long long>::iterator low;
        low = lower_bound(Array.begin(),Array.end(),in);

        if(low != Array.end() && *low == in){
            cout << (low - Array.begin()) << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}