class node{
    public:
        int value;
        node* next;
        node(int value){
            this->value = value;
            this->next=nullptr;
        }
        node(int value,node* next){
            this->value = value;
            this->next = next;
        }
};
class linklist{
    public:
        node* head;
        linklist(node* head){
            this->head = head;
        }
        int insert(int k, int x){
            //此题目保证合法,也就是cur不会是空指针
            node *cur = head;
            while(k){
                cur = cur->next;
                k--;
            }
            node *add = new node(x);
            add->next = cur->next;
            cur->next = add;

        } 
}

#include<bits/stdc++.h>
using namespace std;
int main(){

}