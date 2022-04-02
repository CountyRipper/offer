#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head){
    //核心：让当前节点指针的next的next指向当前节点，让当前节点指向null
    //将该结果递归回去
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* cur = reverseList(head->next);
    head->next->next=head;
    head->next=nullptr;
    return cur;
}
ListNode* reverseList_1(ListNode* head){
    ListNode* pre = head;
    ListNode* cur = nullptr;
    while(pre!=nullptr){
        ListNode* nextp = pre->next;
        pre->next=cur;
        cur=pre;
        pre=nextp;
    }
}