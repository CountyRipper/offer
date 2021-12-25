#include<bits/stdc++.h>
using namespace std;
int minArray(vector<int>& numbers) {
        int size = numbers.size();
    if (size == 0) return 0;
    int left = 0, right = size - 1;
    int mid = (left + right) / 2;
    while (left < right) {
        if (right - left == 1) return min(numbers[left], numbers[right]);
        if (numbers[mid] == numbers[right] && numbers[mid] == numbers[left]) {
            int min = numbers[left];
            for (int i = left; i < right;i++) {
                if (numbers[i] < min) min = numbers[i];
            }
            return min;
        }
        if (numbers[mid] > numbers[right]) {
            left = mid;
            mid = (left + right) / 2;
        }
        else {
            right = mid;
            mid = (left + right) / 2;
        }
    }
    return numbers[left];
}
int main(){
    vector<int> a1 = {3,5,1};
    cout<<minArray(a1)<<endl;
}