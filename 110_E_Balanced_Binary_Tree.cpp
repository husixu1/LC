#include <iostream>
#include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(helper(root) != -1)
            return true;
        return false;
    }
    int helper(TreeNode *root){
        if(!root)
            return 0;

        int ldepth = helper(root->left), rdepth = helper(root->right);
        if(ldepth == -1 || rdepth == -1)
            return -1;
        if(abs(ldepth - rdepth) > 1)
            return -1;
        return max(ldepth, rdepth) + 1;
    }
};

