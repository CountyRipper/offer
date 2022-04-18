#include <bits/stdc++.h>
using namespace std;
//合并有效区间，从前往后会有数组移动问题，可以反向考虑，从后往前
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    m--;n--;
    int f = n+m+1;
    while(f>0&&m>=0&&n>=0){
        if(nums1[m]>nums2[n]){
            nums1[f--] = nums1[m--];
        }
        else{
            nums1[f--] = nums2[n--];
        }
    }
    while(n>=0){
        nums1[f--]=nums2[n--];
    }
}

int main(){
    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};
    merge(v1,3,v2,3);
    for_each(v1.begin(),v1.end(),[](int f){cout<<f<<" ";});
}