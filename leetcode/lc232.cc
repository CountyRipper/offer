#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> A;
    stack<int> B;
    MyQueue() {
        
    }
    
    void push(int x) {
        A.push(x);
    }
    
    int pop() {
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        int res = B.top();
        B.pop();
        return res;
    }
    
    int peek() {
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        return B.top();
    }
    
    bool empty() {
        return B.empty()&&A.empty();
    }
};