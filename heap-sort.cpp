#include <bits/stdc++.h>
using namespace std;
void adjustheap(vector<int>& a, int start)
{
    int end = a.size() - 1;
    for (int i = 0; i <= end - start - 1; i++)
    {
        int tmp = (end - start - i); //当前元素位置
        if (a[tmp] > a[(tmp - 1) / 2])
        {
            swap(a[tmp], a[(tmp - 1) / 2]);
        }
    }
    //调整完毕
    swap(a[0], a[end - start]); //交换最大堆堆顶元素到叶子
}
void heap_sort(vector<int>& a, int start)
{
    adjustheap(a, start);
    if (start < a.size() - 1)
    {
        heap_sort(a, start + 1);
    }
}
int main()
{
    vector<int> a = { 5, 4, 3, 6, 54, 7, 2, 1, 3, 55, 8 };
    heap_sort(a, 0);
    for (auto&& i : a)
    {
        cout << i << ",";
    }
}