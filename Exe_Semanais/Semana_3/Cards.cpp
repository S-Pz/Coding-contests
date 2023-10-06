#include <bits/stdc++.h>
#include <cstddef>

#define endl '\n'

using namespace std;

int main(){

    int n, countN, countZ;

    cin >> n;
    
    for(int i = 0; i<n; i++){
        
        char let;
        cin >> let;

        if (let == 'n'){
            countN++;

        }else if(let == 'z'){
            countZ++;
        } 
    }

    for (int j = countN ; j>0; j--){
        cout << "1 ";
    }

    for (int k = countZ ; k>0; k--){
        cout << "0" << endl;
    }

    return 0;
}