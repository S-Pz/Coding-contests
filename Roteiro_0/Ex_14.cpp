#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	
  float Q, D, P;

  
  while(true){
    
    int Num_page;
    float Ma[2][2];
    float X, Y, A,Dx,Dy,Da;

    cin>> Q>> D>> P;

    if(Q == 0 || D == 0 || P == 0){
      break; 
    }
    
    Dx = D;
    Dy = D/Q;  
    Da = (-1/Q)-(-1/P);
  
    X = Dx/Da;
    Y = Dy/Da;

   cout << "X= "<< X <<endl; 
   cout << "Y= "<< Y <<endl;

  }

  return 0;
}
