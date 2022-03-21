#include<bits/stdc++.h>
using namespace std;
vector<int> max_fix(string s);
int main(){
    //寻找字符串的最长公共前后缀
    string s;
    cin>>s;
    cout<<"max:";
    vector<int> v =max_fix(s);
    for (auto &&i : v)
    {
        cout<<i<<" ";
    }
    return 0;
}
vector<int> max_fix(string s){
    vector<int> Next ;//next数组用于存储最大公共前后缀
    for(auto i : s){
        Next.push_back(0);
    }
    Next.push_back(0);
    for(int i=1,j=0;i<s.size();i++){
        j = Next[i-1];//因为后面j++，所以要往前一位
        while(s[i]!=s[j]&&j!=0){
            j = Next[j-1]; //dp回溯
        }
        if(s[i]==s[j]){
            j++;
        }
        Next[i] = j;
    }
    return Next;
}