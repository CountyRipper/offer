#include<bits/stdc++.h>
using namespace std;
void ismatch(int a[],int l, int r ,int x);
int main(){
    int n, m;
    scanf("%d %d", &n,&m);
    //printf("%d , %d", n,m);
    int *a = new int[n];
    int *b = new int[m];
    for(int i = 0; i < n ; i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < m; i++){
        ismatch(a,0, n-1 ,b[i]);
    }
    return 0;
}
void ismatch(int a[],int l,int r, int x){
    if(a[r]<x||a[l]>x){printf("-1 -1\n"); return;}
    int i=l,j=r;
    while(i<j){
        int mid =(i+j)>>1;
        if(a[mid]>=x) j = mid;
        else i = mid+1;
    }
    if(a[i]!=x){printf("-1 -1\n"); return;}
    int t1 = i;
    i = l, j =r;
    while(i<j){
        int mid =(i+j+1)>>1;
        if(a[mid]<=x) i=mid;
        else j = mid-1;
    }
    int t2 = j;
    if(a[j]!=x){printf("-1 -1\n");return;}
    printf("%d %d\n", t1, t2);
    return;
}