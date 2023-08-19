#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int T;
    cin >> T;

    for (int t=0; t<T; t++){

        string patterns, text, rev;

        cin >> patterns >> text;

        text = text + text;
        rev = patterns;
        
        reverse(rev.begin(),rev.end());

        if(text.find(patterns) != string::npos){

            cout << "S" << endl;

        }else if (text.find(rev) != string::npos){

            cout << "S" << endl;

        }else{

            cout << "N" << endl;
        }
    }

return 0;
}