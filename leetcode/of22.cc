#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* getKthFromEnd(ListNode* head, int k){
    int i=1;
    ListNode* fast=head;
    ListNode* slow=head;
    while(i<=k){
        fast=fast->next;
        i++;
    }
    while (fast!=nullptr)
    {
        fast=fast->next;
        slow = slow->next;
    }
    return slow;
}
//最蠢的哈希表
ListNode* getKthFromEnd_hash(ListNode* head, int k) {
    map<int,ListNode*> m;
    ListNode* cur=head;
    int i=0;
    while(cur!=nullptr){
        m.insert(pair<int,ListNode*>(i++,cur));
        cur=cur->next;
    }
    return m.at(i-k);
}
