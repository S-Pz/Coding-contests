
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main (){

    int N, Q;
    vector<int>Array;

    cin >> N >> Q;

    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        Array.push_back(num);
    }

    for (int j=0; j<Q; j++){

        int busca, ini = 0, end = N - 1, mid = 0;
        bool find = true;

        cin >> busca;

        while (ini <= end){

            mid = ini + (end - ini) / 2;
          
            if(Array[mid] == busca){
                cout << mid << endl;
                find = false;
                break;
            }else if(Array[mid] > busca){
                end = mid - 1;
            }else{
                ini = mid + 1;
            }
        }
        if(find){
            cout << -1 << endl;
        }
    }
    return 0;
}