#include<bits/stdc++.h>
using namespace std;
int minArray(vector<int>& numbers) {
        int mid=(numbers.size()-1)/2;
        int left = 0;
        int right = numbers.size()-1;
        while(left!=right){
            if(numbers[mid]<numbers[left]){//如果出现了旋转
                right = mid;
                mid = (left+right)/2-1;
            }
            else{
                left = mid;
                mid = (left+right)/2+1;
            }
        }
        return numbers[mid];
}
int main(){
    vector<int> a1 = {3,5,1};
    cout<<minArray(a1)<<endl;
}