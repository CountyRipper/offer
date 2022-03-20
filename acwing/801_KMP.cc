#include<bits/stdc++.h>
using namespace std;
char a[100010], b[100010],kmpnext[100010];
//第一种next数组算法
void getnext1(char *b,char kmpnext[],int m){
    //m是字符串长度
    for(int i = 1; i<m;i++){
        int k = kmpnext[i-1];//k得到之前的最长前缀数;
        while(b[i]!=b[k]&&k!=0){
            //如果不相等，依次往回退探索是否含有公共前缀
            k = kmpnext[k-1];
        }
        if(b[i]==b[k]){
            k++;
        }
        kmpnext[i] = k;
    }
}
//第二种next算法
void getnext2(char *b,char kmpnext[],int m){

}
int main(){
    int n,m;
    scanf("%d",&n );
    scanf("%s", a);
    scanf("%d",&m );
    scanf("%s", b);
    
    getnext1(b,kmpnext,m);
    for(int i = 0,j=0; i < n ;i++)
    {
        while(j>0&&a[i]!=b[j]){
            //如果没有匹配上
            j = kmpnext[j-1];
        }
        if(a[i]==b[j]){
            j++;
        }
        //匹配上了，输出,m比位置大1所以要+1
        if(j == m) printf("%d ",i-m+1);
    }
}