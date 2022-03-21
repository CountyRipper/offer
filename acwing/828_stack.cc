#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s1;
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        string a;
        cin>>a;
        int f=0;
        if(a=="push") f=1;
        if(a=="pop") f=2;
        if(a=="query") f=3;
        if(a=="empty") f=4;
        switch (f)
        {
        case 1:
            int x; cin>>x;
            s1.push(x);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            printf("%d",s1.top());
            break;
        case 4:
            if(s1.empty()) printf("YES\n");
            else printf("NO\n");
        default:
            break;
        }
    }
}