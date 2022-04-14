#include<bits/stdc++.h>
using namespace std;
vector<int> pop_sort(vector<int> & a){
    for(int i=0;i<a.size();i++){
        for (int j = a.size()-1; j >i; j--)
        {
            if(a[j]<a[j-1]) swap(a[j],a[j-1]);
        }
    }
    return a;
}
int main(){
    vector<int> v={4,51,34,562,34,15,452,3,0,5};
    auto v1 = pop_sort(v);
    for (auto &&i : v1)
    {
        cout<<i<<" ";
    }
    
}