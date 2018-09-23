#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        helper(root);
    }

    TreeNode *helper(TreeNode *root){
        if(!root->left && !root->right)
            return root;

        TreeNode *result;
        if(root->left && root->right){
            result = helper(root->left);
            result->right = root->right;
            result = helper(root->right);
            root->right = root->left;
            root->left = nullptr;
            return result;
        }

        if(!root->left && root->right){
            return helper(root->right);
        }

        if(root->left && !root->right){
            root->right = root->left;
            root->left = nullptr;
            return helper(root->right);
        }
    }
};

