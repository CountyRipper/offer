#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//按索引来排
ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr) return nullptr;
    ListNode* pre_o = new ListNode(-1);
    ListNode* pre_e = new ListNode(-1);
    ListNode* odd=pre_o;
    ListNode* eve=pre_e; //奇数和偶数
    int n=1;
    while(head!=nullptr){
        if(n%2!=0){
            odd->next = head;
            odd=odd->next;
        }
        else{
            eve->next=head;
            eve=eve->next;
        }
        n++;
        head=head->next;
    }
    eve->next=nullptr;
    odd->next=pre_e->next;
    return pre_o->next;
}
//写错了，写成按照奇偶分类链表了
ListNode* oddEvenList1(ListNode* head) {
    if(head==nullptr) return nullptr;
    ListNode* pre_o = new ListNode(-1);
    ListNode* pre_e = new ListNode(-1);
    ListNode* f = head;
    ListNode* odd=pre_o;
    ListNode* eve=pre_e; //奇数和偶数
    if((head->val % 2) == 0){
        pre_e->next = head; eve=eve->next;
    }
    else{
        pre_o = head; odd=odd->next;
    }
    head=head->next;
    while(head!=nullptr){
        if(head->val%2==0){
            eve->next = head;
            eve=eve->next;
        }
        else{
            odd->next=head;
            odd=odd->next;
        }
        head=head->next;
    }
    odd->next=nullptr;
    eve->next=nullptr;
    if(f->val%2==0){
        //偶数在前
        eve->next=pre_o->next;
        //return pre_e->next;
    }
    else{
        //奇数在前
        odd->next = pre_e->next;
        //return pre_o->next;
    }
    return f;
}
int main(){
    auto head = new ListNode(1);
    auto cur = head;
    cur->next = new ListNode(2);cur=cur->next;
    cur->next = new ListNode(3);cur=cur->next;
    cur->next = new ListNode(4);cur=cur->next;
    cur->next = new ListNode(5);cur=cur->next;
    // cur->next = new ListNode();cur=cur->next;
    // cur->next = new ListNode(7);cur=cur->next;
    auto newc = oddEvenList(head);
    while(newc!=nullptr){
        cout<<newc->val<<" ";
    }
}