#include<bits/stdc++.h>

int main(){

    float x1,y1,x2,y2,D;

    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);

    D = sqrt(pow((x2-x1),2)+pow((y2-y1),2));

    printf("%0.4f\n",D);

    return 0;
}
