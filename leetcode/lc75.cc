#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
    vector<int> tmp={0,0,0};
    for (auto &&i : nums)
    {
        switch (i)
        {
        case 0:
            tmp[0]++;
            break;
        case 1:
            tmp[1]++;
            break;
        case 2:
            tmp[2]++;
            break;
        default:
            break;
        }
    }
    int n=0;
    for(int i = 0 ;i<tmp.size();i++){
        while(tmp[i]>0){
            nums[n++] = i;
            tmp[i]--;
        }
    }
            
}