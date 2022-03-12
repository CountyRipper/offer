#include<bits/stdc++.h>
using namespace std;
vector<int> highmulti(vector<int>&a, int &b);
int main(){
    string s1;
    int b;
    cin>>s1>>b;
    vector<int> a;
    for(int i=s1.size()-1;i>=0;i--){
        a.push_back(s1[i]-'0');
    }
    auto res = highmulti(a,b);
    for(vector<int>::reverse_iterator ri=res.rbegin();ri!=res.rend();ri++){
        cout<<*ri;
    }
}
vector<int> highmulti(vector<int>&a,int &b){
    int tmp = 0;
    vector<int> res;
    for(int i = 0 ; i<a.size()||tmp>0;i++){
        if(i<a.size()) tmp +=(a[i]*b);
        res.push_back((tmp%10));
        tmp/=10;
    }
    while(res.back()==0&&res.size()>1) res.pop_back();
    return res;
}