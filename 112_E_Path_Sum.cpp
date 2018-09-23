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
    int sum;
    bool hasPathSum(TreeNode* root, int sum) {
        this->sum = sum;
        if(!root)
            return false;
        return helper(root, 0);
    }
    bool helper(TreeNode *root, int curSum){
        curSum += root->val;
        if(!root->left && !root->right){
            if(curSum == sum)
                return true;
            return false;
        }
        bool res = false;
        if(root->left)
            res |= helper(root->left, curSum);
        if(root->right)
            res |= helper(root->right, curSum);
        return res;
    }
};

