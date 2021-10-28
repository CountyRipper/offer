//罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//写一个4000以内的罗马数字转换#
#include <bits/stdc++.h>
using namespace std;

int romanToTnt(string s){
    int res=0;
    //reverse(s.begin(),s.end());
    map<char,int> m1={pair<char,int>('I',1),pair<char,int>('V',5),pair<char,int>('X',10),pair<char,int>('L',50),pair<char,int>('C',100),pair<char,int>('D',500),pair<char,int>('M',1000)};
    int i =s.size()-1;
    while(i>0){
        if(i>0&&m1[s[i]]>m1[s[i-1]]){
            //如果出现前面的小于后面的，就是减
            res=res+m1[s[i]]-m1[s[i-1]];
            i--;
        }
        else{
            res+=m1[s[i]];
        }
        i--;
    } 
    if(i==0)res+=m1[s[i]];
    return res;
}
int main(){
    string s="IV";
    int x = romanToTnt(s);
    cout<<x;
    return 0;
}
