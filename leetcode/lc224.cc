#include<bits/stdc++.h>
using namespace std;
//本题没有涉及乘除法高优先级运算
int calculate1(string s) {
    //这个算法实质上没有实现扩展，只是 去掉括号，实现了-(a+b)，除此之外其他的就是直接去括号顺序运算
    stack<char> op; //因为是只有正负运算所以直接 -1，+1表示
    int ans = 0, num = 0, pre = 1;
    op.push(pre);
    for (auto c : s) {
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            num = num * 10 - '0' + c;
        }
        else {
            ans += pre * num;
            num = 0;
            if (c == '-') pre = -op.top();
            else if (c == '+') pre = op.top();
            else if (c == '(') op.push(pre);
            else {
                op.pop();//“)”就抛出前项
            }
        }
    }
    return ans + pre * num;
}
int calculate(string s) {

}
int main() {
    string s = "1 + 1";
    cout << calculate1(s);
}