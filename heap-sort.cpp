#include <bits/stdc++.h>
using namespace std;
void adjustheap(vector<int>& a, int end)
{
    //int end = a.size() - 1;
    for (int i = end; i > 0; i--)
    {

        if (a[i] > a[(i - 1) / 2])
        {
            swap(a[i], a[(i - 1) / 2]);
        }
    }
    //调整完毕
    swap(a[0], a[end]); //交换最大堆堆顶元素到叶子
}
void heap_sort(vector<int>& a, int end)
{
    adjustheap(a, end);
    if (end > 0)
    {
        heap_sort(a, end - 1);
    }
}
int main()
{
    vector<int> a = { 5, 4, 3, 6, 54, 7, 2, 1, 3, 55, 8 };
    heap_sort(a, a.size() - 1);
    for (auto&& i : a)
    {
        cout << i << ",";
    }
}