#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
    int max = nums[0];
    int m = nums.size();
    
    for (int i = 0; i < m; i++)
    {
        if(max<(nums[i]+i)){
            max = nums[i]+i;
        }
    }
    return max>=nums.size()-1;
}