#include <bits/stdc++.h>
using namespace std;

//排序函数需要传出枢轴排序后的索引位置
int mypartition(int *a,int l,int r){
    int pivot=a[l];
    int i=l,j=r;
    while(i<j){
        //核心在于选择枢轴之后在该次循环中，所有小于枢轴的值应该在枢轴位置之前，所有大于的应该在枢轴之后
        while(a[j]>=pivot&&(i<j)) j--;
        //注意调换的对象
        a[i]=a[j];
        while(a[i]<=pivot&&(i<j)) i++;
        a[j]=a[i];
    }
    //会和的时候枢轴的位置也就定下来了，此时应该是i=j，所以a[i]还是a[j]都行
    a[i] = pivot;
    return i;
}
void quick_sort(int *a,int l,int r){
    
    if(l<r){
        int pivot=mypartition(a,l,r);
        quick_sort(a,l,pivot-1);
        quick_sort(a,pivot+1,r);
    }
    else return;
}
int main(){
    int a[] = {4,51,34,562,34,15,452,3,0,5};
    //vector<int> v={4,51,34,562,34,15,452,3,0,5};
    quick_sort(a,0,9);
    for(int i = 0;i<10;i++){
        cout<<a[i]<<" ";
    }
}
