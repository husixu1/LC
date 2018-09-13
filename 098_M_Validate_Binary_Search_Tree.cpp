#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        int l, r;
        return helper(root, l, r);
    }
    bool helper(TreeNode *root, int &min, int &max){
        if(!root)
            return true;

        int lmin, lmax, rmin, rmax, temp;
        if(!helper(root->left, lmin, lmax))
            return false;
        if(!helper(root->right, rmin, rmax))
            return false;
        if((root->left && lmax >= root->val) || (root->right && rmin <= root->val))
            return false;

        min = root->left ? min(root->val, lmin) : root->val;
        max = root->right? max(root->val, rmax) : root->val;
        return true;
    }
};
