#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    //也可以直接用哈希表
    Node* copyRandomList(Node* head) {
        Node* pre = new Node(INT32_MIN);
        pre->next = head;
        while(head!=nullptr){
            Node* thiscur = new Node(head->val);
            thiscur->next=head->next;
            head->next = thiscur;
            head = head->next->next;
        }
        head = pre->next;
        while(head!=nullptr){
            //如果不是指向null就进行复制
            if(head->random!=nullptr) head->next->random = head->random->next;
            head=head->next->next;
        }
        head = pre->next;
        Node* cur = pre;
        while(head!=nullptr){
            cur->next = head->next;
            cur=cur->next;
            head->next = cur->next;
            head = head->next;
        }
        return cur;
    }
};
int main(){
    auto head = new Node(7);
    auto cur = head;
    cur->next= new Node(13);cur=cur->next;
    cur->next = new Node(11);cur=cur->next;
    cur->next = new Node(10);cur=cur->next;
    cur->next = new Node(1);cur=cur->next;
    cur=head;cur->next->random=head;
    cur->next->next->random=cur->next->next->next->next;
    cur->next->next->next->random=cur->next->next;
    cur->next->next->next->next->random=head;
    Solution s1;
    auto res = s1.copyRandomList(head);
}