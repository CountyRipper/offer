#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int j=0;j<q;j++){
        int op, i, x;
        cin>>op>>i>>x;
        if(op==1){
            v[i-1]=x;
        }
        if(op==2){
            int count=0;
            for( int k=0;k<i;k++){
                if(v[k]==x) count++;
            }
            cout<<count<<endl;
        }
    }
}
