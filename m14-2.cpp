/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1）
，每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]k[1]...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/
//实际上当n>=5的时候，倾向于剪长度为3的绳子。n==4，剪2x2显然是更好的
#include<bits/stdc++.h>
using namespace std;
int cuttingRope(int n);
int main() {
    cout << cuttingRope(10) << endl;
}
int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int res = 1;
    for (int i = n;i >= 2;) {
        if (i >= 5) {
            i -= 3;
            res *= 3;
        }
        else if (i == 4) {
            i -= 4;
            res *= 4;
        }
        else if (i == 3) {
            i -= 3;
            res *= 3;
        }
        else {
            res *= 2;
            break;
        }
    }
    return res;
}