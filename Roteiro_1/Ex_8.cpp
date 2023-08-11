#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int N, aux, cem, cinquenta, vinte, dez, cinco, dois, um;
    cin >> N;

    cem = N/100;
    aux = N - (100*cem);
    
    cinquenta = aux/50;
    aux = aux - (50*cinquenta);

    vinte = aux/20;
    aux = aux - (20*vinte);

    dez = aux/10;
    aux = aux - (10*dez);

    cinco = aux/5;
    aux = aux - (5*cinco);

    dois = aux/2;
    aux = aux - (2*dois);
    
    um = aux/1;
    aux = aux - (1*um);

    cout<<N<<endl;
    cout<< cem << " nota(s) de R$ 100,00" << endl;
    cout<< cinquenta << " nota(s) de R$ 50,00" << endl;
    cout<< vinte << " nota(s) de R$ 20,00" << endl;
    cout<< dez << " nota(s) de R$ 10,00" << endl;
    cout<< cinco << " nota(s) de R$ 5,00" << endl;
    cout<< dois << " nota(s) de R$ 2,00" << endl;
    cout<< um << " nota(s) de R$ 1,00" << endl;

    return 0;
}