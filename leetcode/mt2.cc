#include<bits/stdc++.h>
using namespace std;
pair<int,int> DFS(int x, int y, int k,vector<vector<int>> &m);
int main(){
    int n,m;
    vector<vector<int>> matrix;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<int> v;
        for(auto i:s){
            v.push_back(i-'0');
        }
        matrix.push_back(v);
    }
    int T;
    cin>>T;
    vector<vector<int>> m_c;
    for(int i=0;i<T;i++){
        int x,y,k;
        cin>>x>>y>>k;
        while(!m_c.empty()) m_c.pop_back();
        //复制
        for(auto a:matrix){
            m_c.push_back(a);
        }
        pair<int,int> res = DFS(x,y,k);
        cout<<res.first<<" "<<res.second<<endl;
    }
}
pair<int,int> DFS(int x, int y, int k,vector<vector<int>> &m){
    if(x<0)
}