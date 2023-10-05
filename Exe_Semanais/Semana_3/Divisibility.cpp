#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

long int divide (long int a, long int b){

    long int cout = 0;

    while(1){

        if(a % b == 0){

            return cout;
            break;
        }else{
            a++;
            cout++;
        }
    }
}

int main(){

    int T;

    cin >> T;

    for(int i = 0; i<T; i++){
        
        long int a, b;
        
        cin >> a >> b;

        long int c = divide(a,b);

        cout << c << endl;
    }
    return 0;
}