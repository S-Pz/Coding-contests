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
        cout << "Text concat " << text << endl;

        rev = patterns;
        reverse(rev.begin(),rev.end());

        cout << "Reverse text is : " << rev << endl;
        
        //auto find_rev= find(text.begin(), text.end(),rev);

        if(text.find(patterns) != string::npos){

            cout << "padrão presente" << endl;

        }else if (text.find(rev) != string::npos){

            cout << "reverse presente" << endl;

        }else{

            cout << "N" << endl;
        }
    }
return 0;
}