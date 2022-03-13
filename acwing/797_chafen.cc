#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int *a = new int[n+1];
    //差分和前缀和类似，都是要有个前缀0才方便
    for(int i = 1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    int *b = new int[n+1];
    for(int i = 1;i<=n;i++){
        b[i] = a[i]-a[i-1];
    }
    for(int i=0;i<m;i++){
        int l,r,c;
        scanf("%d %d %d",&l,&r,&c);
        b[l]+=c;
        b[r+1]-=c;
    }
    for(int i = 1;i<=n;i++){
        a[i] = a[i-1]+b[i];
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
