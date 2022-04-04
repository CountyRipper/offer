#include<bits/stdc++.h>
using namespace std;
//链表相交，重点是使用双指针交叉遍历得到长度差，然后等待相交即可
//若有相交，交叉一次获得数量差，并且正好两者会在合并处相遇a==b
//若无相交，长度相等时，两者都移动到最后null，退出，说明不相交
//若无相交，长度不相等，遍历两次，两指针同时到末尾null，返回，说明不相交
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(headA==nullptr||headB==nullptr) return nullptr;
    ListNode *a = headA, *b=headB;
    while(a!=b){
        //当等于nullptr的时候才会触发返回另一个头指针。
        a= a==nullptr?headB:a->next;
        b= b==nullptr?headA:b->next;
    }
    return a;
    //不会出现环
}
ListNode *getIntersectionNodehash(ListNode *headA, ListNode *headB){
    set<ListNode*> s;
    int i=0;
    while(headA!=nullptr){
        s.insert(headA);
        headA=headA->next;
    }
    while(headB!=nullptr){
        if(s.count(headB)) return headB;
        headB=headB->next;
    }
    return nullptr;
}
int main(){
    ListNode *heada = new ListNode(8);
    ListNode *headb = new ListNode(4);
    ListNode *headB =headb;
    headb->next = new ListNode(1);
    headb=headb->next;
    headb->next=heada;
    headb=headb->next;
    headb->next = new ListNode(4);
    headb=headb->next;
    headb->next = new ListNode(5);
    headb=headb->next;
    if(getIntersectionNodehash(heada,headB)){
        cout<<getIntersectionNodehash(heada,headB)->val;
    }
    else cout<<"NO";
}
