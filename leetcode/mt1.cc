#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num[26]={0};
        string s;
        cin>>s;
        for(auto i:s){
            num[i-'a']++;
        }
        int eve=0;
        int odd=0;
        bool f=false;
        for(int i=0;i<26;i++){
            if(num[i]%2==0){
                eve+=num[i];
            }
            else{
                if(!f){
                    odd+=num[i];
                    f=true;
                }
                else odd+=(num[i]-1);
            }
        }
        cout<<eve+odd<<endl;
    }
}