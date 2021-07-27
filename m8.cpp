#include<bits/stdc++.h>
#include "tree.h"
using namespace std;
template <class E>
node<E>* nextnode(node<E>* pnode){
    if(pnode==nullptr) return nullptr;
    node<E>* curnode=nullptr;
    if(pnode->right!=nullptr){
        //有右子树的时候
        curnode=pnode->right;
        while(curnode->left!=nullptr){
            curnode=curnode->left;
        }
        //return curnode;
    }
    else{
        //没有右子树
        if(pnode->parent!=nullptr){
            //有父节点
            node<E>* parentnode= pnode->parent; 
            if(pnode==parentnode->left){
                //如果是左儿子
                curnode=parentnode;
            }
            else{
                //如果是右儿子
                while(parentnode!=nullptr){
                    pnode = parentnode;
                    parentnode= pnode->parent;
                }
                curnode=parentnode;
            }
        }
        
        //包含一种情况就是root节点没有右子树，全是左子树，此时下一节点为null
    }
    return curnode;
}
int main(){
    //给定一个二叉树结点，找到该节点中序遍历的下一个节点
    //分析：1.如果二叉树有右子树，则沿着右子树的最左节点是下一个节点
    //2.如果没有右子树，并且是父子树的左儿子，则父节点为下一个节点，
    //3.如果没有右子树，并且是父节点的右儿子需要一直向上遍历直到该节点是其父节点的左儿子，取该父节点
    //BADCFE中序
    tree<char> t = new node<char>('A');
    t.root->right = new node<char>('C');
    t.root->left = new node<char>('B');
    t.root->left->parent = t.root;
    t.root->right->parent = t.root;
    t.root->right->left = new node<char>('D');
    t.root->right->left->parent = t.root->right;
    t.root->right->right = new node<char>('E');
    t.root->right->right->parent = t.root->right;
    t.root->right->right->left = new node<char>('F');
    t.root->right->right->left->parent = t.root->right->right;
    node<char>* pt  = t.root->right->right->left;
    cout<<"F的下一节点：";
    node<char>* pn = nextnode(pt);
    if(pn){pn->print();};
    cout<<endl;
    midtravelre(t.root);
}