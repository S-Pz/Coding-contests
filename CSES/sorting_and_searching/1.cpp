/*-------------------------------
|                               |
|PROBLEM NAME: Distinct Numbers |
|                               |
--------------------------------*/

#include < bits/stdc++.h >
#define endl "\n"
 
using namespace std;
 
int main(){
 
    int n, a;
    set<int>numbers;
 
    cin >> n;
 
    for(int i=0; i<n; i++){
        cin >> a; 
        numbers.insert(a);
    }
 
    cout << numbers.size() <<endl;
    
    return 0;
}