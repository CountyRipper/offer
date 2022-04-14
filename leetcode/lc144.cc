#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pretravel(TreeNode* root,vector<int> &res){
    if(root==nullptr) return;
    res.push_back(root->val);
    pretravel(root->left,res);
    pretravel(root->right,res);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    pretravel(root,res);
    return res;
}

