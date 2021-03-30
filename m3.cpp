#include<iostream>
#include<vector>
using namespace std;
//m3 数组中重复的数字，
//给出一个长度为n的数组，数字在0-n-1内，有些数字是重复出现的，
//找出重复的数字
//方法：使用哈希表
void solution(vector<int> &v1);
int main(int argc, char const *argv[])
{
    vector<int> v = {3,5,0,3,6,4,1,7};
    solution(v);
    return 0;
}
void solution(vector<int> &v1){
    
    int arr[v1.size()]={0};
    for (auto &&i : v1)
    {
        if(arr[i]==0){
            //没有出现
            arr[i]=1;
        }
        else{
            arr[i]++;
            cout<<i<<" ";
        }
        
    }
    cout<<endl;
    for (size_t i = 0; i < v1.size(); i++)
        {
            cout<<arr[i]<<" ";
        }

}
