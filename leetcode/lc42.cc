#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int s[100010];
    int cur = 0;
    int ans = 0;
    int s_num = -1;//栈的位置
    while (cur < height.size()) {
        while (s_num >= 0 && height[s[s_num]] <= height[cur]) {
            int low = height[s[s_num--]];
            if (s_num < 0) break;
            //面积计算,当前高度和
            int left = s[s_num];
            ans = ans + (cur - left - 1) * (min(height[left], height[cur]) - low);
        }
        s[++s_num] = cur;
        cur++;
    }
    return ans;
}
int main() {
    vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << trap(v);
}