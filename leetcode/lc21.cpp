#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
    };
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ml=nullptr;
        ListNode* big;
        ListNode* cur;
        if(l1!=nullptr&&l2!=nullptr){
            if(l1->val<=l2->val){
                cur = l1;
                big = l2;
            }
            else{
              cur = l2;
              big = l1;
            }
        }
        else if(l1!=nullptr&&l2==nullptr){
            return l1;
        }
        else if(l1==nullptr&&l2!=nullptr){
            return l2;
        }
        else return nullptr;
        ml=cur;
        while(big!=nullptr&&cur!=nullptr){
            while(cur->next!=nullptr&&(cur->next->val<=big->val)){
                cur=cur->next;
            }
            //出现变化
            ListNode* tmp=big;
            big=cur->next;
            cur->next=tmp;
        }
        return ml;
    }
int main(){
    ListNode* l1=new ListNode(2);
    //l1->next=new ListNode(2);
    ListNode* l2= new ListNode(1);
    //l2->next=new ListNode(3);
    ListNode* t=mergeTwoLists(l1,l2);
    while(t!=nullptr){
        cout<<t->val<<" ";
        t=t->next;
    }
}