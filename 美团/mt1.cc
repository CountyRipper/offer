#include <bits/stdc++.h>
using namespace std;
bool check(string s1);
int main(){
    int m=0;
    cin>>m;
    for(int i = 0 ;i<m;i++){
        string s;
        cin>>s;
        if(check(s)){
            cout<<"Accept"<<endl;
        }
        else{
            cout<<"Wrong"<<endl;
        }
    }
}
bool check(string s1){
    regex rule("^([a-zA-Z])([a-zA-z]*)([0-9]+)+([a-zA-Z0-9]*)$");
    //regex_match(rule)
    return regex_match(s1,rule);
}