#include<bits/stdc++.h>
using namespace std;
char a[100010], b[100010],kmpnext[100010];
void getnext(char *b,char *kmpnext,int m){
    int i = 0, j =1;
    for(; i<m;i++){
        if(b[i]!=b[j]){
            kmpnext[j]=0;
            j=0;
        }
        else{
            //能匹配上
            kmpnext[j++] = j+1;
        }
    }
}
int main(){
    int n,m;
    scanf("%d",&n );
    scanf("%s", a);
    scanf("%d",&m );
    scanf("%s", b);
    int i = 0,j=0;
    getnext(b,kmpnext,m);
    while(i<(n-m))
    {
        if(a[i]==b[j]&&j<m){j++;i++;}
        else{
            //如果失配
            i = i+ kmpnext[j];
            j = 0;
        }
        if(j == m){
            printf("%d ",i);
            j=0;
            i++;
        }
    }
}