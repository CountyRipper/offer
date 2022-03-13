#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int a[N][N]={0}; int b[N][N]={0};
void insert( int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c; b[x1][y2+1] -= c; b[x2+1][y1] -= c; b[x2+1][y2+1] += c;
}
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    // int** a = new int* [n + 1];//a是和，b是前缀
    // int** b = new int* [n + 1];
    // for (int i = 0;i <= n;i++) {
    //     a[i] = new int[m + 1];
    // }
    // for (int i = 0;i < n;i++) {
    //     b[i] = new int[m + 1];
    // }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //构造差分
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            insert(i, j, i, j, a[i][j]);
        }
    }
    for (int i = 0;i < q;i++) {
        int x1, y1, x2, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            //如果是a[][]应该是 a[i][j] = a[i-1][j]+a[i][j-1]+b[i][j]-a[i][j]
            b[i][j] += b[i - 1][j] + b[i][j - 1]-b[i-1][j-1] ;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}