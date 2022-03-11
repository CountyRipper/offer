#include<bits/stdc++.h>
using namespace std;
int N = 100001;
int main() {
    int a[N];
    int s[N + 1];
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    
    s[0] = 0;
    for (int i = 0; i < n;i++) {
        s[i + 1] = s[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
    //一定要注意s的寻址顺序
        cout << s[k] - s[j - 1] << endl;
    }
}