//回文数，双指针
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            string s;
            for(;x>0;x=x/10){
                int i=x%10;
                s.push_back(i);
            }
            int f=0,e=s.size()-1;
            bool flag=true;
            while(f<=e){
                if(s[f]!=s[e]) flag=false;
                f++;e--;
            }
            return flag;
        }
    }
int main(void){
    int x;
    cin>>x;
    cout<<isPalindrome(x);
    return 0;
}