#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int PA, PB, anos=1;
    float G1, G2;

    cin >> PA >> PB >> G1 >> G2;

    G1 = G1/100;
    G2 = G1/100;

    do{
        PA += PA * G1;
        PB += PB * G2;
        anos++;

    }while(PA <= PB);

    if(anos > 100)
        cout << "Mais de 1 seculo." << endl;
    else
        cout << anos << " anos." << endl;

    return 0;
}