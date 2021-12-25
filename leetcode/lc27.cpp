#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val){
    vector<int>:: iterator it=nums.begin();
        while(it!=nums.end()){
            if(*it==val){
                nums.erase(it);
                it--;
            }
            it++;
        }
        return nums.size();
}
int main(){
    vector<int> v={0,1,2,2,3,0,4,2};
    //vector<int>:: iterator it1=v.begin();
    cout<<removeElement(v,2)<<endl;
    string s1="23342354";
    s1.reserve(0);
    for (auto &&i : s1)
    {
        cout<<i<<" ";
        
    }  
}