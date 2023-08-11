#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main(){

int p;

cin >> p;

for (int i=0; i<p; i++){

    string A;
    bool result;

    cin >> A;


    for(auto& x : A){
       x = tolower(x);
    }
    int cont = 0;

    for(int i=0;i<(int)A.size() - 1;i++){
    	
 	if(A[i] < A[i+1]){
		cont+=1;
    	}
    }
    
    if(cont == (int)A.size() -1 ){
	result = true;

    }else{
       	result = false;
    }	

    if(result){
	cout << A << ": " << "O" << endl;

    }else{
       	cout << A << ": " << "N" << endl;
    }	
}
return 0;
}
