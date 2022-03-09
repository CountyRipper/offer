#include<bits/stdc++.h>
using namespace std;
int quickpartition(vector<int> &a, int start, int end){
    //f排序核心
    int pivot = a[start];//初始数设为枢轴
    int i = start, j = end;
    int tmp = a[start];//存储枢轴
    while(i<j){
        while(a[j]>=tmp&&(i<j)){
            j--;
        }
        a[i]=a[j];
        while(a[i]<=tmp&&(i<j)){
            i++;
        }
        a[j]=a[i];
    }
    a[i] = tmp;
    return i;
}
void quick_sort(vector<int> &a,int low, int high){
    if(low<high){
        int pivot = quickpartition(a, low, high);
        quick_sort(a, low , pivot-1);
        quick_sort(a, pivot+1, high);
    }
    else return;
}
int main(){
    vector<int> arr = {4,35,215,64,2,5,34,3,666,53,2,1};
    quick_sort(arr,0,arr.size()-1);
    for (const auto &i : arr)
    {
        cout<<i<<",";
    }
}