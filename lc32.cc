#include <bits/stdc++.h>
using namespace std;
int main(){

}
/*
注意要先push一个-1入栈，然后再进行出入栈匹配，如果识别反括号pop后栈为空应该push这个反括号说明不能识别（确保连续子串
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_num=0;
        stack<int> ss;
        ss.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]=='('){
                ss.push(i);
            }       
            else{
                ss.pop();
                if(ss.empty()){
                    ss.push(i);
                }
                else{
                    max_num = max(max_num,i-ss.top());
                }
            }
        }
        return max_num;
    }
};