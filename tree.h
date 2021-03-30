#include <vector>
#include <iostream>
#include<queue>
//父子结点单项结点树的链表实现
using namespace std;
template <class E>
class node
{
public:
    E element;
    node *left;
    node *right;
    node(E ele, node *l = nullptr, node *r = nullptr)
    {
        this->element = ele;
        this->left = l;
        this->right = r;
    }
    node();
    void print()
    {
        cout << element << " ";
    }
};

template <class E>
class tree
{
public:
    node<E> *root;
    tree(node<E> *root)
    {
        this->root = root;
    }
};
//前序遍历(递归)
//先访问根节点，然后访问左节点，最后访问右节点
template <class E>
void pretravelre(node<E>* t)
{
    node<E> *cur = t;
    //visit
    cur->print();
    if (cur->left != nullptr)
    {
        pretravelre(cur->left);
    }
    //左边没有了
    if (cur->right != nullptr)
    {
        pretravelre(cur->right);
    }
}
//中序遍历(递归)
template <class E>
void midtravelre(node<E>* t)
{
    node<E> *cur = t;
    if (cur->left != nullptr)
    {
        midtravelre(cur->left);
    }
    cur->print();
    if (cur->right != nullptr)
    {
        midtravelre(cur->right);
    }
}
//后续遍历(递归)
template <class E>
void backtravelre(node<E>* t)
{
    node<E> *cur = t;
    if (cur->left != nullptr)
    {
        midtravelre(cur->left);
    }

    if (cur->right != nullptr)
    {
        midtravelre(cur->right);
    }
    cur->print();
}
//层次遍历
template <class E>
void layertravel(node<E>* t){
    queue<node<E>*> q1;
    node<E> *cur = t;
    q1.push(cur);
    while(q1.size()!=0){
        cur->print();
        if(cur->left) q1.push(cur->left);
        if(cur->right) q1.push(cur->right);
        
        q1.pop();
        cur=q1.front();
        
    }
}