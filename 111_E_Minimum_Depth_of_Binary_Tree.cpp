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
    int finDepth;
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        finDepth = -1;
        helper(root, 1);
        return finDepth;
    }

    void helper(TreeNode *root, int depth){
        if(!root->left && !root->right) {
            if (finDepth == -1 || depth < finDepth)
                finDepth = depth;
            return;
        }

        if(root->left)
            helper(root->left, depth + 1);
        if(root->right)
            helper(root->right, depth + 1);
    }
};

