#include<bits/stdc++.h>
using namespace std;
//用两个堆实现队列
template <class E>
class myqueue{
    public:
    stack<E> s1;
    stack<E> s2;
    void push(E element){
        s1.push(element);
    }
    void pop(){
        if(s2.empty()){
            while(!(s1.empty())){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
        else{
            //如果s2不为空
            s2.pop();
        }
    }
    E top(){
        if(s2.empty()){
            while(!(s1.empty())){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        else{
            //如果s2不为空
            return s2.top();
        }
    } 
    // void visit(){
    //     vector<E> v1;
    //     for (auto &&i : s2)
    //     {
    //         v1.push_back(i);
    //     }
    //     reverse(v1);
    //     for (auto &&i : s1)
    //     {
    //         v1.push_back(i);
    //     }
    //     for (auto &&i : v1)
    //     {
    //         cout<<i<<",";
    //     }
    //     cout<<endl;
    // }
};

int main(){
    myqueue<int>  m1;
    for(int i=0;i<5;i++){
        m1.push(i);
    }
    for(int i=0;i<3;i++){
        m1.pop();
    }
    m1.push(11);
    m1.push(12);
    //m1.visit();
    cout<<"当前顶部"<<m1.top()<<endl;
    m1.pop();
    m1.pop();
    cout<<"当前顶部"<<m1.top()<<endl;
    //m1.visit();

}