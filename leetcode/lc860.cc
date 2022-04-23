#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
    int wallet[2]={0,0};
    //int n = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if(bills[i]==5){
            wallet[0]++;
        }
        else if(bills[i]==10){
            if(wallet[0]!=0){
                wallet[0]--;
                wallet[1]++;
            }
            else return false;
        }
        else if(bills[i]==20){
            if(wallet[1]!=0){
                wallet[1]--;
                if(wallet[0]!=0){
                    wallet[0]--;
                }
                else return false;
            }
            else if(wallet[0]>2){
                wallet[0]--;wallet[0]--;wallet[0]--;
            }
            else return false;
        }
    }
    return true;
}
int main(){
    vector<int> v = {5,5,20,5,5,10,5,10,5,20};
    cout<<lemonadeChange(v);
}