#include<iostream>
#include<string>
//校招题，子序列匹配
using namespace std;
bool res(char *s,char *t);
int main(){
    char *s = new char[500001];
    char *t = new char[128];
    cin>>s;
    cin>>t;
    if(res(s,t)) cout<<"true";
    else cout<<"false";
}
bool res(char *s,char *t){
    while(*s&&*t){
        if(*s==*t) s++;
        t++;
    }
    if(*s=='\0'){
        return true;
    }
    else return false;
}