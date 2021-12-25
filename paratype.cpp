#include<bits/stdc++.h>
using namespace std;
template <typename T>
void f(T&& param){
   // param++;
}
int main(){
    const char* const ptr = "I can see you";
    auto x  = ptr;
    cout<<sizeof(x);
    int* const ptr2 = new int[10];
    auto y = ptr2;
    cout<<sizeof(y);
    auto z {3};
    decltype(auto) d = ptr;
    cout<<endl<<typeid(x).name()<<endl;
    cout<<typeid(z).name()<<endl;
    cout<<typeid(y).name()<<endl;
    return 0;
}