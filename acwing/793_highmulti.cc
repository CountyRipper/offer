#include<bits/stdc++.h>
using namespace std;
//非负数考虑
string highadd_str(string &s1,string &s2);
string highmulti(string &s1,string &s2);
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string res = highmulti(s1,s2);
    for(int i = res.size()-1; i >= 0;  i--){
        cout<<res[i];
    }
}
string highmulti(string &s1,string &s2){
    if(s2=="0"||s1=="0") return "0";
    //int f = 1;
    //if((s1[0]=='-'&& s2[0]!='-')||(s1[0]!='-'&&s2[0]=='-')) f = -1; 
    string res;
    int i = s1.size(),j = s2.size();
    for(int k=i-1,f=0;k>=0;k--,f++){
        string res1;
        for(int m = 0 ; m<f;m++){
            res1.push_back('0');
        }
        int tmp=0;
        for(int l=j-1;l>=0;l--){
            tmp += (s1[k]-'0')*(s2[l]-'0');
            res1.push_back((tmp%10)+'0');
            tmp /=10;
        }
        if(tmp) res1.push_back(tmp+'0');
        //顺序的str参数，res和res1都是倒序
        res = highadd_str(res, res1);
        res.reserve();
    }
    return res;
    
}
string highadd_str(string &s1,string &s2){
    if(s1.empty()) return s2;
    if(s2.empty()) return s1;
    if(s1.empty()&&s2.empty()) return "\0";
    else{
        string res;
        int tmp=0;
        for(int i=0;i<max(s1.size(),s2.size());i++){
            if(i<s1.size()) tmp+=(s1[i]-'0');
            if(i<s2.size()) tmp+=(s2[i]-'0');
            res.push_back((tmp%10)+'0');
            tmp /=10;
        }
        if(tmp) res.push_back(tmp+'0');
        return res;
    }
}