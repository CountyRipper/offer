#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeforList(ListNode* a, ListNode* b){
    //判断是否是单个链表，至少会有一个非空
    if(!a||!b) return a? a:b;
    ListNode* res;
    ListNode* tmp;
    res = a->val<b->val?a:b;
    a->val<b->val? a=a->next:b=b->next;
    tmp = res;
    while(a&&b){
        if(a->val<b->val){
            tmp->next = a;
            a=a->next;
        }
        else{
            tmp->next = b;
            b = b->next;
        }
        tmp=tmp->next;
    }
    while(a){tmp->next = a; a=a->next;tmp=tmp->next;}
    while(b){tmp->next=b;b=b->next;tmp=tmp->next;}
    return res;
}
ListNode* merge(vector<ListNode*>& lists,int l,int r){
    if(l==r) return lists[l];//保证至少会有一个非空
    if(l>r) return nullptr;//保证至少会有一个非空
    else{
        int mid = (l+r)>>1;
        //重点考虑
        return mergeforList(merge(lists,l,mid),merge(lists,mid+1,r));
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists){
    return merge(lists,0,lists.size()-1);
}
//合并k个升序链表,传统方法
ListNode* mergeKLists1(vector<ListNode*>& lists) {
    //if(lists[0]==nullptr) return nullptr;
    ListNode* pre = new ListNode(-1);
    ListNode* res; res=pre;
    int m = lists.size();  bool flag = !lists.empty();
    while(flag){
        int n = 0;int min = INT32_MAX;
        flag = false;
        for( int i = 0; i< m;i++){
            //if(lists[i])
            if(lists[i]==nullptr) continue;
            if(lists[i]->val<min){
                res->next = lists[i];
                n = i ;
                min = lists[i]->val;
                flag = true;
            }
        }
        if(!flag) continue;
        //当轮最小
        
        res->next = lists[n];
        //if(res==nullptr) break;
        lists[n]=lists[n]->next;
        res=res->next; 
        //if(lists[n]==nullptr) lists.erase()
        n=0;
    }
    return pre->next;
}
int main(){
    ListNode* l1  = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode* l2  = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3  = new ListNode(2);
    l3->next = new ListNode(6);
    vector<ListNode*> lists={l1,l2,l3};
    auto res = mergeKLists(lists);
    while(res->next){
        cout<<res->val<<" ";
        res=res->next;
    }
}