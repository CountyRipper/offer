#include <bits/stdc++.h>
using namespace std;
//插入排序就是把前面看作有序的，跟有序数组接触的第一个数字从有序末尾开始依次对比，如果更小就往前移动空出位置
vector<int> insert_sort(vector<int> & a){
    vector<int> res;
    for (int i = 1; i < a.size(); i++)
    {
        int tmp=a[i];//tmp是已排序的之后的下一位
        int j;//核心！！
        for ( j=i-1 ; j >=0; j++)
        {
            //a[0-j]是已排序的值，如果后面那个值比前面排序的小就一直往前试探直到前面的都比自己小然后插入进去
            if(a[j]>tmp){
                a[j+1]=a[j];
            }
            else break;
        }
        //此时j位置已经被空出，等待插入
        a[j]=tmp;
    }
    
}