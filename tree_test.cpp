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

    return 0;
}
