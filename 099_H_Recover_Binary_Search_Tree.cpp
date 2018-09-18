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
    TreeNode *lastNode;
    TreeNode *resL, *resR;
    void recoverTree(TreeNode* root) {
        lastNode = nullptr;
        helper(root);
        lastNode = nullptr;
        helper2(root);

        swap(resL->val, resR->val);
    }
    bool helper(TreeNode *root){
        if(!root)
            return true;
        if(!helper(root->left))
            return false;

        if(lastNode && root->val < lastNode->val){
            resL = lastNode;
            return false;
        }
        lastNode = root;
        if(!helper(root->right))
            return false;

        return true;
    }
    bool helper2(TreeNode *root){
        if(!root)
            return true;
        if(!helper2(root->right))
            return false;

        if(lastNode && root->val > lastNode->val){
            resR = lastNode;
            return false;
        }
        lastNode = root;
        if(!helper2(root->left))
            return false;

        return true;
    }
};

