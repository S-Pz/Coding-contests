#include <bits/stdc++.h>
#include <vector>

#define endl '\n'

using namespace std;

int main (){

    int k;

    vector<int>array;

    cin >> k;
    
    for(int i=0; i<12; i++){

        int a;
        cin >> a;
    
        array.push_back(a);
    }

    sort(array.begin(), array.end(), greater<int>());

    int a = 0;
    int mo = 0;

    for(int i = 11; i>=0; i--){

        a += array[i];
        

        if(a >= k){
            cout << mo << endl;
            break;
        }
        
        mo ++;
    }

    if (a < k){

        cout << "-1" << endl;
    }

    return 0;
}