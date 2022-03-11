#include<bits/stdc++.h>
using namespace std;
int main(){
    string a1,a2;
    cin>>a1;
    cin>>a2;
    vector<int> v1,v2,res;
    for(auto &&i:a1){
        v1.push_back(i-'0');
    }
    for(auto &&i:a2){
        v2.push_back(i-'0');
    }
    int size1 = v1.size()-1;
    int size2 = v2.size()-1;
    int max1 = max(size1,size2);
    int tmp=0;
    for(int i=0;i<=max1;i++){
        if(size1-i>=0) tmp+=v1[size1-i];
        if(size2-i>=0) tmp+=v2[size2-i];
        res.push_back(tmp%10);
        tmp /=10;
    }
    if(tmp) res.push_back(tmp);
    
    for(vector<int>::reverse_iterator ri = res.rbegin();ri!=res.rend();ri++){
        cout<<*ri;
    }
    return 0;
}