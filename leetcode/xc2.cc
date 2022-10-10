#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long num;
        cin>>num;
        if(num%233!=0){
            cout<<-1<<endl;
        }
        else{
            int dis=0;
            
            long num1 = num;
            while(num1>0){
                num1/=10;
                dis++;
            }
            int count=0;
            while(num!=0){
                int p = 1;
                for(int j=0;j<dis-3;j++){
                    p*=10;
                }
                long cur = 233* p;
                num-=cur;
                count++;
                num1=num;
                dis=0;
                while(num1>0){
                num1/=10;
                dis++;
                }
            }
            cout<<count<<endl;
        }
    }
}