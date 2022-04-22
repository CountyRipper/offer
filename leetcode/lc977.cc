#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res;
    if(nums.size()<1) return res;
    int i=0;
    while(nums[i]<0&&i<nums.size()){i++;}
    int j = i-1;
    while(j>=0&&i<nums.size()){
        if(-nums[j]<nums[i]){
            res.push_back(nums[j]*nums[j]);
            j--;
        }
        else{
            res.push_back(nums[i]*nums[i]);
            i++;
        }
    }
    while(j>=0){res.push_back(nums[j]*nums[j]);j--;}
    while(i<nums.size()){res.push_back(nums[i]*nums[i]);i++;}
    return res;
}
int main(){
    vector<int> v ={-7,-3,2,3,11};
    auto res = sortedSquares(v);
    for(auto i: res){
        cout<<i<<" ";
    }
}