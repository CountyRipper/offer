#include <bits/stdc++.h>
using namespace std;
vector<int> subSort(vector<int>& array) {
    //解题关键在于理解题意，假设是升序，则需要找到从左往右遍历中出现最大值并且往下降这样的“下坡”
    //同时从右往左遍历找到出现最小值并且往上升的“低谷”
    //假设升序
    vector<int> res = {-1,-1};
    if(array.size()<=0) return res;
    int min = INT16_MAX;
    int max = INT16_MIN;
    //if(l>=r) return res;
   for (int i = 0; i < array.size(); i++)
   {
       if(array[i]<max){
           res[1] = i;
       }
       else{
           max= array[i];
       }
   }
   for (int j = array.size()-1; j >= 0; j--)
   {
       if(array[j]>min){
           res[0]=j;
       }
       else{
           min =array[j];
       }
   }
    return res;
}
int main(){
    vector<int> v1 ={1,3,9,7,5};
    auto res =subSort(v1);
    for(auto i : res){
        cout<< i <<" ";
    }
}