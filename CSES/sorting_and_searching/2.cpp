/*-------------------------------
|                               |
|PROBLEM NAME: Apartments       |
|                               |
--------------------------------*/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){

    int n, m, k, ap_avail = 0;

    cin >> n >> m >> k;
    
    vector<int>applicants(n);
    vector<int>apartments(m);

    for (int i=0; i<n; i++){
        
        int a;
        cin >> a;
        applicants[i] = a;
    }

    for (int j=0; j<m; j++){

        int a;
        cin >> a;

        apartments[j] = a;
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i=0,j=0;

    while(i < n && j < m){

        if(apartments[j] < applicants[i]-k){
            j++; // se o apartamento é menor que o mínimo vai para o próximo
        }else if(apartments[j] > applicants[i]+k){
            i++;// se o apartamento e maior que o máximo vai para o próximo cliente
        }else{//caso o apartamento esteja de acordo, ande com os 2 e some no ap_availble
            ap_avail++;
            i++;
            j++;
        }
    }

    cout << ap_avail << endl;

    return 0;
}