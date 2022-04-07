#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//第一次相遇fast=2s, fast=s+nb. 一定是转了n圈+s走的路，因为可以减去s当前的距离入口的距离
//可得s=nb
//然后将f指向链表头部,速度变成s一致，这样当f走完a的时候，s此时必然为nb+a,此时s必然在入口处

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(1){
            if(fast==nullptr||fast->next==nullptr)return nullptr;
            fast = fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        fast=head;
        while(fast!=slow){fast=fast->next;slow=slow->next;}
        return fast;
    }
};