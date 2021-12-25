#include <bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2) {
    int sum = 0;
    int i = num1.size() ;
    int w1 = 1;
    for (;i > 0;i--) {
        int w2 = 1;
        int j = num2.size() ;
        for (;j > 0;j--) {
            sum += w1 * w2 * ((num1[i-1] - 48) * (num2[j-1] - 48));
            w2 *= 10;
        }
        w1 *= 10;
    }
    
    string res1=0;
    if(sum=0) return res1;
    while (sum > 0) {
        res1.push_back(sum % 10 +48);
        sum /= 10;
    }
    reverse(res1.begin(), res1.end());
    return res1;
}
int main(){
    string s1="45";
    string s2="3";
    cout<<multiply(s1,s2);
    //cout<<(s1[0]-48)*(s2[0]-48);
}
