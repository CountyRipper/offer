#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int dic[N], a[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    int max = 0;
    for(int i=0,j=0;i<n;i++){
        dic[a[i]]++;
        while (dic[a[i]] > 1) {
            dic[a[j]]--;
            j++;
        }
        if ((i - j + 1) > max) max = (i - j + 1);
    }
    printf("%d\n", max);
}