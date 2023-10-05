#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    
    int T, PA,PB, anos=0;
    float G1, G2;
    
    cin >> T;
    
    for(int i = 0; i < T; i++){
        
        cin >> PA >> PB >> G1 >> G2;
        
        //G1 = ;
        //G2 = (G2/100) * 100;
        
        while (PA <= PB) {

            PA += floor(PA * (G1 / 100.0));
            PB += floor(PB * (G2 / 100.0));
            
            anos++;

            if (anos > 100) break;
        }
    }
    
    if(anos >= 100){
        cout << "Mais de 1 seculo." << endl;
    }else{
        cout << anos << " anos." << endl;
    }

    return 0;
}