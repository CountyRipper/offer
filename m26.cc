#include <bits/stdc++.h>
using namespace std;
int main(){

}
bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr) return false;
        if(A==nullptr) return false;
        return DFS(A,B)||isSubStructure(A->left, B)||isSubStructure(A->right, B);
    }
bool DFS(TreeNode* A,TreeNode* B){
    if(B==nullptr) return true;
    if(A==nullptr||A->val!=B->val) return false;
    return DFS(A->left, B->left)&&DFS(A->right, B->right);
}