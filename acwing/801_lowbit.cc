#include<bits/stdc++.h>
using namespace std;
int a[100010];
int lowbit(int a);
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",lowbit(a[i]));
    }
}
int lowbit(int a){
    int res = 0;
    while(a){
        a -= a&(-a);
        res++;
    } 
    return res;
}