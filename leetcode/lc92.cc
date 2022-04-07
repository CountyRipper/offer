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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* dummynode = new ListNode(INT32_MIN);
        dummynode->next = head;
        ListNode * pre = dummynode;
        for(int i=0;i<left-1;i++){
            pre=pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* Nextp;
        //穿针引线，需要三个指针引用
        //循环内部
        //先将nextp记录为cur的下一个节点
        //把cur的下一个节点指向nextp的下一个节点
        //注意先把nextp迁到pre的next指向的位置，再把pre的next指针指向nextp
        //把nextp的下一个节点指向pre的下一个节点***
        //把pre的下一个节点指向nextp***
        for(int i = 0;i<(right-left);i++){
            Nextp=cur->next;
            cur->next = Nextp->next;
            Nextp->next = pre->next;
            pre->next = Nextp;
        }
        //保留的头节点
        return dummynode->next;
    }
};
int main(){
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for(int i =2;i<=5;i++){
        cur->next = new ListNode(i); cur=cur->next;
    }
    Solution s1;
    ListNode* res = s1.reverseBetween(head,2,4);
    while(res!=nullptr){
        cout<<res->val<<"->";
        res=res->next;
    }

}