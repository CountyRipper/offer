#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *big = new ListNode(INT32_MIN);
        ListNode *bighead = big;
        ListNode *small = new ListNode(INT32_MIN);
        ListNode *smallhead = small;
        while(head!=nullptr){
            if(head->val<x){
                small->next=head;
                small=small->next;
            }
            else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }
        //注意切断big的末尾
        big->next=nullptr;
        small->next=bighead->next;
        return smallhead->next;
    }
};