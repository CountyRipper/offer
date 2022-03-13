#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int** matrix = new int* [n];
    int** s = new int* [n + 1];
    for (int i = 0;i < n;i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0;i < n + 1;i++) {
        s[i] = new int[m + 1];
    }
    s[0][0] = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 1; i < n + 1;i++) {
        for (int j = 1;j < m + 1;j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }
    for (int i = 0;i < q;i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d \n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }

}