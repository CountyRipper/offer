#include<bits/stdc++.h>
using namespace std;
char a[100010], b[100010],kmpnext[100010];
void getnext(char *b,char *kmpnext,int m){
    kmpnext[0] = 0;
    for(int i=1,j=0; i<m;i++){
        j = kmpnext[i-1];
        while(b[i]!=b[j]&&j>0){
            j = kmpnext[j-1];
        }
        if(b[i]==b[j]){j++;}
        kmpnext[i] = j;
    }
}
int main(){
    int n,m;
    scanf("%d",&m );
    scanf("%s", b);
    scanf("%d",&n );
    scanf("%s", a);
    getnext(b,kmpnext,m);
    for(int i=0,j=0;i<n;i++){
        while(a[i]!=b[j]&&j>0){
            j = kmpnext[j-1];
        }
        if(a[i]==b[j]) j++;
        if(j == m){
            printf("%d ",(i-m+1));
        }
    }
}