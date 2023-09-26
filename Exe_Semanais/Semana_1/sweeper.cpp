#include <bits/stdc++.h>

#define endl '\n'  

using namespace std;

int main(){
    int n,m;

    while((cin >> n >> m) && (n!= 0) && m!=0){

        char matriz[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                char in;
                cin >> in;
                
                matriz[i][j] = in;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matriz[i][j] == '*'){
                    continue;
                }
                int count = 0;
                if(i-1 >= 0 && j-1 >= 0 && matriz[i-1][j-1] == '*'){
                    count++;
                }
                if(i-1 >= 0 && matriz[i-1][j] == '*'){
                    count++;
                }
                if(i-1 >= 0 && j+1 < m && matriz[i-1][j+1] == '*'){
                    count++;
                }
                if(j-1 >= 0 && matriz[i][j-1] == '*'){
                    count++;
                }
                if(j+1 < m && matriz[i][j+1] == '*'){
                    count++;
                }
                if(i+1 < n && j-1 >= 0 && matriz[i+1][j-1] == '*'){
                    count++;
                }
                if(i+1 < n && matriz[i+1][j] == '*'){
                    count++;
                }
                if(i+1 < n && j+1 < m && matriz[i+1][j+1] == '*'){
                    count++;
                }
                cout << count + '0' << endl;
                matriz[i][j] = count + '0';
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}