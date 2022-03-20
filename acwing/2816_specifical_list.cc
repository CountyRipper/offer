#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];

bool ismatch(int *a,int *b,int n,int m);
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i = 0 ;i<n;i++){
        scanf("%d",&a[i]);
    } 
    for(int i = 0;i<m;i++) scanf("%d",&b[i]);
    if(ismatch(a,b,n,m)) printf("Yes\n");
    else printf("No\n");

}
bool ismatch(int *a,int *b,int n,int m){
    int i=0,j=0;
    for(;i<m;i++){
        if(j==n) return true;
        if(a[j]==b[i]){
            j++;
        }
    }
    if(j==n) return true;
    else return false;
}