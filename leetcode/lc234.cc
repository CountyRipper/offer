#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
bool isPalindrome(ListNode* head) {
    int N[100010];
    int p = 0;
    //判断回文链表,快慢指针
    ListNode* cur = head;
    while (cur != nullptr) {
        N[p++] = cur->val;
        cur = cur->next;
    }
    int l = 0;p = p - 1;
    while (l <= p) {
        if (N[l] != N[p]) return false;
        l++, p--;
    }
    return true;
}