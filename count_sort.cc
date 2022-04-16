#include <bits/stdc++.h>
using namespace std;
//计数排序适用于较小范围的多个重复数字的排序
const int N = 101;//一百以内的计数排序
int myindex[N];
void count_sort(int *a,int n){
    for(int i = 0;i<n;i++){
        myindex[a[i]]++;
    }
    int m = 0;
    for(int i=0;i<N;i++){
        while(myindex[i]!=0){
            a[m++]=i;
            myindex[i]--;
        }
        //else continue;
    }
}
int main(){
    int a[] = {4,51,34,62,34,15,52,3,0,5};
    //vector<int> v={4,51,34,562,34,15,452,3,0,5};
    count_sort(a,10);
    for(int i = 0;i<10;i++){
        cout<<a[i]<<" ";
    }
}