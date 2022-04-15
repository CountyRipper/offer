#include <bits/stdc++.h>
using namespace std;
vector<int> choose_sort(vector<int> &a){
    //int min=0;
    for (int i = 0; i < a.size(); i++)
    {
        int min = i;
        for (int j = i+1; j < a.size(); j++)
        {
            if(a[j]<a[min]) min = j;
        }
        swap(a[i],a[min]);
    }
    return a;
}

int main(){
    vector<int> v={4,51,34,562,34,15,452,3,0,5};
    auto v1 = choose_sort(v);
    for (auto &&i : v1)
    {
        cout<<i<<" ";
    }
    
}