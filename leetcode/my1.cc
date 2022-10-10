#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int count=0;
    for(int pre=0;pre<s.length();pre++){
        for(int end = pre+1;end<=s.length();end++){
            string cur_s = s.substr(pre,end-pre);
            int  cur=0;
            for(int j=0;j<cur_s.length();j++){
                cur*=10;
                cur+=cur_s[j]-'0';
            }
            //int cur = stoi(cur_s);
            if(cur<k) count++;
            else{
                break;
            }
        }  
    }
    cout<<count<<endl;
}