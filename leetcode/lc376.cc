#include <bits/stdc++.h>
using namespace std;
int wiggleMaxLength(vector<int>& nums) {
    if(nums.size()<2) return nums.size() ;
    int a,b;
    int pre=nums[1]-nums[0];
    int res = pre!=0?2:1;
    for (int i = 2; i < nums.size(); i++)
    {
        int cur = nums[i]-nums[i-1];
        if((cur<0&&pre>=0)||(cur>0&&pre<=0)){
            pre=cur; res++;
        }
    }
    return res;
}
int main(){
    vector<int> v={3,3,3,2,5};
    cout<<wiggleMaxLength(v)<<endl;
}