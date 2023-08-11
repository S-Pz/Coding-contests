#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int array[100],max_value=0,max_position=0;

    for(int i=0; i<100;i++){
        cin >> array[i];

        if(array[i]>max_value){

            max_value =array[i];
            max_position = i;
        }
    }
    cout << max_value << endl;
    cout << max_position+1<< endl;
    return 0;
}
