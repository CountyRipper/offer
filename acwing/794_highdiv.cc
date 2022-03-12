#include<bits/stdc++.h>
using namespace std;
vector<int> highdiv(vector<int>&a, int b, int &r);
int main(){
    string s1;
    int b;
    cin>>s1>>b;
    vector<int> a;
    for(int i=s1.size()-1;i>=0;i--){
        a.push_back(s1[i]-'0');
    }
    int r=0;
    auto res = highdiv(a,b,r);
    for(auto &&i:res){
        cout<<i;
    }
    cout<<endl<<r;
}
vector<int> highdiv(vector<int> &a, int b,int &r){
    r=0;
    vector<int> res;
    for(int i=a.size()-1;i>=0;i--){
        r=r*10+a[i];
        res.push_back((r/b));
        r%=b;
    }
    reverse(res.begin(),res.end());
    while(res.size()>1&&res.back()==0) res.pop_back();
    return res;
}
