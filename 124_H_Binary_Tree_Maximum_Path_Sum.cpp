#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// TEST CASES
// [1,2,3]
// [-10,9,20,null,null,15,7]
// [-3]
// [5,4,8,11,null,13,4,7,2,null,null,null,1]

class Solution {
private:
    // T: terminative
    unordered_map<TreeNode *, int> nodeMaxSumT;
    // LR: left-or-right
    unordered_map<TreeNode *, int> nodeMaxSumLR;

public:
    int maxPathSum(TreeNode *root) {
        maxPathSum_(root);
        return max_element(
            nodeMaxSumT.begin(), nodeMaxSumT.end(),
            [](const auto &a, const auto &b) -> bool {
                return a.second < b.second;
            })->second;
    }

    int maxPathSum_(TreeNode *root) {
        // return cached max sum
        if (nodeMaxSumLR.find(root) != nodeMaxSumLR.end())
            return nodeMaxSumLR.at(root);

        // calcualte max-sum of only a single branch (or no branch) included
        int curNodeMaxSum = root->val;
        if (root->left)
            curNodeMaxSum = max(curNodeMaxSum, root->val + maxPathSum_(root->left));
        if (root->right)
            curNodeMaxSum = max(curNodeMaxSum, root->val + maxPathSum_(root->right));
        nodeMaxSumLR.insert({root, curNodeMaxSum});

        // calcualte max-sum terminating at this node
        int curNodeMaxSumT = curNodeMaxSum;
        if (root->left && root->right)
            curNodeMaxSumT =
                max(curNodeMaxSumT,
                    maxPathSum_(root->left) + root->val + maxPathSum_(root->right));
        nodeMaxSumT.insert({root, curNodeMaxSumT});

        return curNodeMaxSum;
    }
};


