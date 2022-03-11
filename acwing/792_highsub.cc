#include<bits/stdc++.h>
using namespace std;
//高精度减法，可以直接使用string而不用vector;
vector<int> highsub(vector<int> &a1, vector<int> &a2);
bool cmp(vector<int> &a1, vector<int> &a2);
int main() {
    string s1, s2;
    vector<int> a1, a2;
    cin >> s1; cin >> s2;
    // for (auto&& i : s1) a1.push_back(i - '0');
    // for (auto&& i : s2) a2.push_back(i - '0');
    for(int i = s1.size()-1;i>=0;i--){
        a1.push_back(s1[i]-'0');
    }
    for(int i = s2.size()-1;i>=0;i--){
        a2.push_back(s2[i]-'0');
    }
    if (cmp(a1,a2)) {
        vector<int> res = highsub(a1, a2);
        for (vector<int>::reverse_iterator ri = res.rbegin();ri != res.rend();ri++) {
            cout << *ri;
        }
    }
    else {
        vector<int> res = highsub(a2, a1);
        cout << "-";
        for (vector<int>::reverse_iterator ri = res.rbegin();ri != res.rend();ri++) {
            cout << *ri;
        }
    }
}
vector<int> highsub(vector<int> &a1, vector<int> &a2){
    vector<int> res;
    int tmp=0;
    for(int i=0;i<a1.size();i++){
        tmp= a1[i]-tmp;
        if(i<a2.size()) tmp-=a2[i];
        //如果tmp没有借位就(tmp+10)%10等于原来的tmp，如果借位了就是借10-tmp
        res.push_back((tmp+10)%10);
        //用于下一个循环的借位-1;
        if(tmp<0) tmp=1;
        else tmp=0;
    }
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}
bool cmp(vector<int> &a1, vector<int> &a2){
    if(a1.size()!=a2.size())return a1.size()>a2.size();
    for(int i = a1.size()-1;i>=0;i--){
        if(a1[i]!=a2[i]) return a1[i]>a2[i];
    }
    return true;
}