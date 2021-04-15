#include "tree.h"
int main(int argc, char const *argv[])
{
    tree<char> t = new node<char>('A');
    
    t.root->right = new node<char>('C');
    t.root->left = new node<char>('B');
    t.root->left->left = new node<char>('D');
    t.root->left->right = new node<char>('E');
    t.root->right->left = new node<char>('F');
    pretravelre(t.root);
    cout<<endl;
    midtravelre(t.root);
    cout<<endl;
    backtravelre(t.root);
    cout<<endl;
    layertravel(t.root);
    cout<<endl<<"非递归："<<endl<<"前序1：";
    pretravel_1(t.root);
    cout<<endl<<"前序2：";
    pretravel_2(t.root);
    cout<<endl<<"中序:";
    midtravel_1(t.root);
    cout<<endl<<"后序：";
    return 0;
}
