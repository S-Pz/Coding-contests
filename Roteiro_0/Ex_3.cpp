#include <iostream>

#define endl '\n'

using namespace std;

int main(){

    long f, R;
    cin >> f;

    R = f;
    
    if (f == 0) {
        R = 1;
    }else {
        for (long i = 1; i <= f; i++){

            if (f-i == 0) {
                break;
            }
            R = (f-i) * R;
        }
    }
    cout<< R << endl;

    return 0;
}