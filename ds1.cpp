#include<iostream>
using namespace std;
//实现链表
//结点
template <class E> 
class node{
    public:
        E ele;
        node* next;
        node(const E &e,node* nextval=nullptr){
            ele=e;next=nextval;
        }
};
template <class E>
class linklist{
    public:
        node<E> *head;
        node<E> *cur;
        linklist(node<E>* first=nullptr){
            head=first;
            cur=head;
        }
        push(const E &val){
            if(head==nullptr){
                head= new node<E>(val);
                cur=head;
            }else{
                // n.ele=val;
            cur->next = new node<E>(val);
            cur=cur->next;
            }
            
        }
        clean(){            
            while(head->next!=nullptr){
                node<E> *t =head->next;
                head->next=head->next->next;
                delete t;
            }
            node<E> *t =head;
            delete t;
            head=nullptr;
        }
        print(){
            node<E> *t=head;
            while(t!=nullptr){
                cout<< t->ele<<" ";
                t=t->next;
            }
        }
};
int main(int argc, char const *argv[])
{
    linklist<int> l1;
    node<int> n(1);    
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.print();
    l1.clean();
    l1.print();
    return 0;
}
