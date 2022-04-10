#include <bits/stdc++.h>
using namespace std;
bool thismatch(char a,char b){
    if((a=='('&&b==')')||a=='{'&&b=='}'||a=='['&&b==']') return true;
    else return false;
}
bool isValid(string s) {
    if(s.size()%2!=0) return false;
    stack<char> ss;
    for(auto &&c:s){
        if(ss.empty()) ss.push(c);
        else{
            if(thismatch(ss.top(),c)) ss.pop();
            else{
                if(c=='('||c=='['||c=='{') ss.push(c);
                else return false;
            }
        }
    }
    if(!ss.empty())return true;
    else return false;
}
int main(){
    string s1 = "({})";
    string s2 = "()[]{}";
    cout<<isValid(s1)<<" "<<isValid(s2)<<endl;
}