#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

    int Num, Ret;

    while(cin >> Num >> Ret){
	int array[Num];
	
	for (int j=0;j<Num;j++){
	     array[j]=0;
	}

	for(int i=0; i<Ret; i++){
	   int A;
	   cin >> A;
	   array[A-1] = 1;
	}

	int posi = 0;

	for(int j=0; j<Num; j++){
	   if(array[j] != 1){
	      posi = j+1;
	      cout<< posi<< " ";
	   }
	}
	
	if(posi == 0){
	  cout << "*";
	}
         cout << endl;
	
	
	
    }
return 0;	    
}
