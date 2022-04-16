#include <bits/stdc++.h>
using namespace std;
// const int N=10010;
// int tmp[N];//N可以调整,一般是待排序数组长度
void merge(int *a,int l, int mid, int r){
    int i = l, j = mid + 1;
    int n = 0;
    int tmp[(r-l+1)];
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) tmp[n++] = a[i++];
        else tmp[n++] = a[j++];
    }
    while (i <= mid) tmp[n++] = a[i++];
    while (j <= r) tmp[n++] = a[j++];
    //merge
    for (int i = l; i <= r;i++) {
        a[i] = tmp[i - l];
    }
}
void merge_sort(int* a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a,l,mid,r);
    //auto tmp = new int[r - l + 1];
    
}

int main() {
    int a[] = { 4,51,34,62,34,15,52,3,0,5 };
    //vector<int> v={4,51,34,562,34,15,452,3,0,5};
    merge_sort(a, 0, 10);
    for (int i = 0;i < 10;i++) {
        cout << a[i] << " ";
    }
}