#include<iostream>
#include<string>
//替换空格(或者任意指定字符串) 时间消耗在O(n)
//eg: hello my friend 空格替换为%20
using namespace std;
string solution(string s1){
    //char *a = new char[s1.size()];
    int p1,p2;
    int count=0;
    for (auto &&i : s1)
    {
        if(i==' ') count++;
    }
    count=count*3;//‘%20’占三位
    char *arr = new char[count+s1.size()+1];
    p1= s1.size()-1; p2=count+s1.size()-1;
    while(p1>=0){
        if(s1[p1]!=' '){
            arr[p2]=s1[p1];//双指针移动，当没有遇到空格时，就把字符按位置移动到p2处
            p1--;p2--;
        }
        else{
            arr[p2--]='0';
            arr[p2--]='2';
            arr[p2--]='%';
            p1--;
        }
        
    }
   return string(arr);
}
int main(int argc, char const *argv[])
{
    cout<<solution("hello my frined")<<endl;
    return 0;
}

