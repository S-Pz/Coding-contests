/*-------------------------------
|                               |
|PROBLEM NAME: Weird Algorithm  |
|                               |
--------------------------------*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    long int n;
    
    cin >> n;
    
    if (n==1){
        cout << n << " " << endl;
    }else{

        do{
            cout << n << " ";
            
            if (n%2 == 0){
                n = n/2; 
            }else{//Se não ímpar
                n = (n * 3) + 1;
            }

        }while(n>1);

        cout << 1 << endl;
    }
    
    return 0;
}