#include<bits/stdc++.h>
using namespace std;
int main() {
    int dic[100001];
    int n;
    scanf("%d", &n);
    int* a = new int[n];
    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    int q = 0, p = 0, max = 0, t = 0;
    do{
        if (dic[a[p]] == 0) {
            dic[a[p]] = 1;
            p++;
            t++;
        }
        else {
            for(int i =q; i<p;i++){
                dic[a[i]] = 0;
            }
            q = p;
            p++;
            t = 1;
        }
        if (t > max) max = t;
    }while(p<n);
    printf("%d\n",max);
}