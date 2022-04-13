#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//从头到尾反过来返回
vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    if(head==nullptr) return res;
    ListNode* pre = head;
    ListNode* cur = pre->next;
    while(cur!=nullptr){
        ListNode* nextp = cur->next;
        cur->next=pre;
        pre=cur;
        cur=nextp;
    }
    head->next=nullptr;

    while(pre!=nullptr){
        res.push_back(pre->val);
        pre=pre->next;
    }
    return res;
}
int main(){
    auto head = new ListNode(1);
    auto cur = head;
    //cur->next = new ListNode(2);cur=cur->next;
    //cur->next = new ListNode(3);cur=cur->next;
    //cur->next = new ListNode(4);cur=cur->next;
    //cur->next = new ListNode(5);cur=cur->next;
    auto newc = reversePrint(head);
    for(auto &i:newc){
        cout<<i<<" ";
    }
}