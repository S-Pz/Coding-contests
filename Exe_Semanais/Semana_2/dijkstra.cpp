#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    
    unordered_set<string> j; //j = joias

    string joias;

    while(cin >> joias){

        if(j.find(joias) == j.end()){
            j.insert(joias);
        }
    }

    cout << j.size() << endl;

    return 0;
}