#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    MinStack() {
        support.push(INT32_MAX);
    }
    
    void push(int val) {
        s.push(val);
        if(val<support.top()) support.push(val);
        else support.push(support.top());
    }
    
    void pop() {
        s.pop();
        support.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return support.top();
    }
private:
    stack<int> s;
    stack<int> support;
};