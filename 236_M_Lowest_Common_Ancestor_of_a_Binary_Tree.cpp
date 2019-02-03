#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    std::stack<TreeNode *> s;
    int foundPQ;
    int deep;

public:
    Solution() : s(), foundPQ(0), deep(0) {}
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        using namespace std;
        if (!foundPQ)
            s.push(root);

        if (root == p || root == q) {
            if (foundPQ) {
                return s.top();
            } else {
                foundPQ = 1;
                deep = 1;
            }
        }

        if (root->left) {
            TreeNode *res = lowestCommonAncestor(root->left, p, q);
            if (res)
                return res;
        }

        if (root->right) {
            TreeNode *res = lowestCommonAncestor(root->right, p, q);
            if (res)
                return res;
        }

        if (root == p || root == q)
            deep = 0;

        if ((!foundPQ || !deep) && root == s.top())
            s.pop();

        return nullptr;
    }
};
