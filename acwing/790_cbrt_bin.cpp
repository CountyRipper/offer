#include<bits/stdc++.h>
using namespace std;
double n,l=-10000.0,r=10000.0,mid;
int main(){
    scanf("%lf",&n);
    while(r-l>=1e-7){
        mid = (l+r)/2;
        if(mid*mid*mid>=n) r=mid;
        else l = mid;
    }
    printf("%.6f",mid);
}