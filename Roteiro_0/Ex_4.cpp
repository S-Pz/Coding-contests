#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){

    int R, aux = 0;

    while (true){

        cin >> R;

        if (R == 0){
            break;
        }

        int Aldo = 0, Beto = 0;

        for (int i = 0; i < R; i++){
            int A, B;
            cin >> A >> B;

            Aldo += A;
            Beto += B;
        }
        aux++;

        if (Aldo > Beto) {
            cout << "Teste " << aux << "\nAldo" << endl;
        } else {
            cout << "Teste " << aux << "\nBeto" << endl;
        }
    }
  return 0;
}