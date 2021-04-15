#include <vector>
#include <iostream>
#include <queue>
#include <stack>
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
void pretravelre(node<E> *t)
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
void midtravelre(node<E> *t)
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
void backtravelre(node<E> *t)
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
void layertravel(node<E> *t)
{
    queue<node<E> *> q1;
    node<E> *cur = t;
    q1.push(cur);
    while (q1.size() != 0)
    {
        cur->print();
        if (cur->left)
            q1.push(cur->left);
        if (cur->right)
            q1.push(cur->right);

        q1.pop();
        cur = q1.front();
    }
}
//非递归前序遍历
//先访问根节点然后访问左节点，再访问右节点
//传统方式，左右进栈
//遇到结点，先入栈，并且遍历，直到左儿子没有东西了(叶子)，
//然后出栈该节点，然后获取到上一个父节点，查找是否有有右儿子，
//有的话就遍历并且入栈，没有的话继续上一个步骤，出栈，到父节点寻找右儿子节点
template <class E>
void pretravel_1(node<E> *t)
{
    stack<node<E> *> s1;
    while (t != nullptr || !s1.empty())
    {
        if (t != nullptr)
        {
            //先对根部遍历
            t->print();
            s1.push(t);
            t = t->left;
        }
        else
        {
            //左边没有了
            t = s1.top();//一定要注意t获取堆栈的顺序！！！！
            s1.pop();
            t = t->right;
            
        }

    }
}
//前序遍历方式2，反序入栈
template <class E>
void pretravel_2(node<E> *t)
{
    stack<node<E> *> s1;
    if (t == nullptr)
        return;
    else
    {
        s1.push(t);
        while (!s1.empty())
        {
            t->print();
            if (t->right != nullptr)
            {
                s1.push(t->right);
            }
            if (t->left != nullptr)
            {
                s1.push(t->left);
            }
            t = s1.top();
            s1.pop();
        }
    }
}
//中序遍历非递归
//先一次从左边入栈，到没有左节点了，弹出后，观察上一结点是否有右边子树
//有的话，先把该节点遍历后，出栈然后把右儿子压入栈，继续返回到检查左儿子的循环中
//关键点是在遍历之后该节点弹出，但是t依旧是已经弹出的那个节点，而不是弹出之后当前栈顶的结点。
//所以它的右儿子判定不会是无限循环
template<class E>
void midtravel_1(node<E>* t){
    stack<node<E>*> s1;
    while(t!=nullptr||!s1.empty()){
        if(t!=nullptr){
            s1.push(t);
            t=t->left;
        }
        else{
            t=s1.top();
            t->print();
            s1.pop();
            t=t->right;
        }
        

    }

}