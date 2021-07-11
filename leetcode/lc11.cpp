//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
//在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    //解题关键：双指针，移动短板能够获得更大的值，移动长板不能，从两边往中间移动
    int a1,a2,res;
    a1=0;a2=height.size()-1;res=0;
    while(a1<a2){
        if(height[a1]<height[a2]){
            res=max((height[a1]*(a2-a1)),res);
            a1++;
        }
        else{
            res=max((height[a2]*(a2-a1)),res);
            a2--;
        }
    }
    return res;
}
int main(void){

}