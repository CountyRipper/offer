#include <bits/stdc++.h>
using namespace std;
void heap_sort(vector<int>& a, int end);
void quick_sort(int *a,int l,int r);
//排序函数需要传出枢轴排序后的索引位置
int mypartition(int *a,int l,int r){
    int pivot=a[l];
    int i=l,j=r;
    while(i<j){
        //核心在于选择枢轴之后在该次循环中，所有小于枢轴的值应该在枢轴位置之前，所有大于的应该在枢轴之后
        while(a[j]>=pivot&&(i<j)) j--;
        //注意调换的对象
        a[i]=a[j];
        while(a[i]<=pivot&&(i<j)) i++;
        a[j]=a[i];
    }
    //会和的时候枢轴的位置也就定下来了，此时应该是i=j，所以a[i]还是a[j]都行
    a[i] = pivot;
    return i;
}
void quick_sort(int *a,int l,int r){
    
    if(l<r){
        int pivot=mypartition(a,l,r);
        quick_sort(a,l,pivot-1);
        quick_sort(a,pivot+1,r);
    }
    else return;
}
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