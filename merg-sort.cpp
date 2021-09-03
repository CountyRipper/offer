#include<bits/stdc++.h>
using namespace std;
// 1.使用递归的方式分裂数组
//2.合并时使用双指针从小到大
void mergesort(){

}
void merge(vector<int> &a,int l,int mid,int r){
    vector<int> tmp;//开辟临时数组
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            tmp.push_back(a[i++]);
        }
        else{
            tmp.push_back(a[j++]);
        }
    }
    //总有一个数组填完，只剩下另一个数组了
    while(i<=mid){
        tmp.push_back(a[i++]);
    }
    while(j<=r){
        tmp.push_back(a[j++]);
    }
    for(int n=l;n<=r;n++){
        a[n]=tmp[n-l];
    }
}
void merge_sort(vector<int>&a, int l,int mid,int r){
    if(l>=r) return;
    int mid1=(l+mid)/2;
    int mid2=(r+mid+1)/2;
    merge_sort(a, l,mid1,mid);
    merge_sort(a, mid+1, mid2,r);
    merge(a, l, mid, r);
}
int main(){
    vector<int> v1={4,6,2,8,5,46,53,13,232,124,23245,2,1234};
    merge_sort(v1,0,(v1.size()/2),v1.size()-1);
    for (const auto &i : v1)
    {
        cout<<i<<",";
    }

}