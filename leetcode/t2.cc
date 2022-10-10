#include<bits/stdc++.h>
using namespace std;
class usr{
    public:
    string name;
    vector<string> stock;
    usr(string name,vector<string> stock){
        this->name = name;
        this->stock = stock;
    }
    ~usr();
};
void sign(vector<usr> &v,set<string> &s1){
    string cur_name;
    cin>>cur_name;
    int stock_num;
    cin>>stock_num;
    vector<string> stock_list;
    for(int i=0;i<stock_num;i++){
        string s;
        cin>>s;
        stock_list.push_back(s);
        if(s1.find(s)==s1.end()){
            s1.insert(s);
        }
    }
    v.push_back(usr(cur_name,stock_list));
}
void query(vector<usr> &v,set<string> &s1){
    string cur_name;
    cin>>cur_name;
    bool flag=false;
    int t;
    for(t=0;t<v.size();t++){
        if (v[t].name ==cur_name){
            flag=true;break;
        }
    }
    //vector<usr>::iterator it = find(v.begin(),v.end(),cur_name);
    if(!flag) cout<<"error"<<endl;
    else{
        usr u1 = v[t];
        int stock_sum = s1.size();
        cout<< stock_sum-u1.stock.size()<<endl;
    }
}
int main(){
    set<string> s1;
    int n;
    cin>>n;
    vector<usr> v;
    for(int i=0;i<n;i++){
        int f;
        cin>> f;
        if(f==1){
            sign(v,s1);
        }
        else{//f==2;
            query(v,s1);
        }
    }
    return 0;
}