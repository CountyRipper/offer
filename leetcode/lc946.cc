#include <bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    int n = 0;
    for (auto i : pushed) {
        s.push(i);
        while (!s.empty() && s.top() == popped[n]) {
            s.pop();n++;
        }
    }
    return s.empty();
}
int main() {
    vector<int> a = { 2,1,0 };
    vector<int> b = { 1,2,0 };
    cout << validateStackSequences(a, b);
}