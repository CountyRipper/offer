#include <bits/stdc++.h>
using namespace std;
int ind[100010];
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(),0);
    //for (int i = 0; i < temperatures.size(); i++) res.push_back(0);
    //int j=0;
    int k=-1;
    for (int i = 0 ; i< temperatures.size();i++) {
        while (k>=0 && (temperatures[i] > temperatures[ind[k]])) {
            //大于的情况
            res[ind[k]] = i - ind[k];
            k--;
        }
        //k++;
        ind[++k]=i;
    }
    return res;
}
int main() {
    vector<int> tmp = { 73,74,75,71,69,72,76,73 };
    auto r = dailyTemperatures(tmp);
    for (auto& i : r) {
        cout << i << " ";
    }
}