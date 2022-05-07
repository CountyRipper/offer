#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    int m = num.size();
    if(m==k) return "0";
    string res;
    deque<char> q;
    for (int i = 0; i < m; i++)
    {
        if(q.empty()||q.back()<=num[i]){
            q.push_back(num[i]);
        }
        else{
            while(k>0&&(!q.empty()&&q.back()>num[i])){q.pop_back(); k--;}
            q.push_back(num[i]);
        }
    }
    while(k){
        q.pop_back();
        k--;
    }
    while(q.front()=='0'&&q.size()>1) q.pop_front();
    for (auto &&i : q)
    {
        res.push_back(i);
    }
    return res;
}
int main(){
    string s = "10001";
    int k = 4;
    cout<<removeKdigits(s,k)<<endl;
}