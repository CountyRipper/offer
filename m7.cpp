#include "tree.h"
//根据中序序列和前序序列重建二叉树
//前序序列第一个必为root，通过递归分治方法来解决
template<class E>
node<E> *constructcore(vector<E> preorder,int startpreorder,int endpreorder,vector<E> midorder,
    int startmiorder,int endmidorder);
template<class E>
node<E> *reconstruct(vector<E> preorder,vector<E> midorder){
    if(preorder.empty()||midorder.empty()) return nullptr;
    else return constructcore(preorder,0,preorder.size()-1,midorder,0,midorder.size()-1);
}
template<class E>
node<E> *constructcore(vector<E> preorder,int startpreorder,int endpreorder,vector<E> midorder,
int startmiorder,int endmidorder){
    node<E> *root = new node<E>(preorder[startpreorder]);
    if(startpreorder==endpreorder && preorder[startpreorder]==preorder[endpreorder]){
        //如果前序start=end说明前序仅有这一个元素，就为根节点(or叶子)
        return root;
    }
    // else{
    //     cout<<"invalid input"<<endl;//错误抛出
    // }
    //接下来在中序遍历中找到根节点，用于下一步划分生成左右子树
    int rootnum=startmiorder;
    for(;rootnum<=endmidorder;){
        //默认无重复
        if (midorder[rootnum]==preorder[startpreorder]) break;
        rootnum ++;
    }
    if(rootnum>endmidorder||midorder[rootnum]!=preorder[startpreorder]) cout<<"Invalid Input"<<endl;
    int leftlength=rootnum-startmiorder;
    int leftpreorderend=leftlength+startpreorder;//左子树范围是前序开始+左子树长度
    if(leftlength>0){
        //有左子树
        root->left= constructcore(preorder,startpreorder+1,leftpreorderend,midorder,startmiorder,rootnum-1);
    }
    if(leftlength<endpreorder-startpreorder){
        //说明有右子树
        root->right = constructcore(preorder, leftpreorderend+1,endpreorder, midorder,rootnum+1,endmidorder);

    }
    return root;   
}
int main(){
    tree<char> t = new node<char>('A');
    
    t.root->right = new node<char>('C');
    t.root->left = new node<char>('B');
    t.root->left->left = new node<char>('D');
    t.root->left->right = new node<char>('E');
    t.root->right->left = new node<char>('F');
    vector<int>  preorder = {1,2,4,7,3,5,6,8};
    vector<int> midorder = {4,7,2,1,5,3,8,6};
    node<int> *rt = reconstruct<int>(preorder,midorder);
    pretravelre(rt);
    cout<<endl;
    midtravelre(rt);
    cout<<endl;
    backtravel_1(rt);
}