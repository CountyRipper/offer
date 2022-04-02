#include<bits/stdc++.h>
using namespace std;
//返回 滑动窗口中的最大值 。
//输入数组和窗口大小
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //双端队列头部必定为最大值
    deque<int> q;
    vector<int> res;
    if(nums.size()==0||k==0)
    int start=0,end=k-1;
    for (int i = 0; i < k;i++)
    {
        //如果之前的比当前的大，就追加在队列后边,否则就一直pop直到为零
        while(!q.empty()&&q.back()<nums[i]) q.pop_back();
        q.push_back(nums[i]);
    }
    res.push_back(q.front());
    for (int i = k; i < nums.size(); i++)
    {
        //为什么不是while而是直接用if，因为始终确保当新的元素加入的时候，前面的所有元素都比这个新加的大，
        //所以要么全部比这个大，依次通过左端检测后pop，要么就是在新加入时就被pop了，不会存在说在队列里的元素比当前窗口还小的情况。
        if(q.front()==nums[i-k]) q.pop_front();
        while(!q.empty()&&q.back()<nums[i]) q.pop_back();
        q.push_back(nums[i]);
        res.push_back(q.front());
    }
    return res;
}
int main(){
    vector<int> n1 = {1,3,1,2,0,5};
    vector<int> n2 = maxSlidingWindow(n1,3);
    for (auto &&i : n2)
    {
        cout<<i<<' ';
    }
    
}