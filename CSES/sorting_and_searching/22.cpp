#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int compare (int *app, int *ap, int diff_min, int diff_max){

    if((apartments[l] >= diff_min ) && (apartments[l] <= diff_max )){
            ap_avail ++;

            cout << apartments[l]<< applicants[l] << endl;
        }

    return 1;
}

int main(){

    int n, m, k, ap_avail = 0;

    cin >> n >> m >> k;
    
    int *applicants = (int *) malloc(n*sizeof(int));
    int *apartments =(int *) malloc(m*sizeof(int)) ;
       

    // vector<int>applicants(n);
    // vector<int>apartments(m);

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

    for (int l=0; l<n; l++){
        
       
        int diff_min, diff_max;

        diff_min  = applicants[l]-k;
        diff_max = applicants[l]+k;

        app = &applicants[l];
        ap = &apartments[l];

        compare(app, ap, diff_min, diff_max);

        free(app);
        free(ap);
    }

    cout << ap_avail << endl;

    return 0;
}