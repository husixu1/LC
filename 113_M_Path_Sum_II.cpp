#include <iostream>
#include <vector>
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
    vector<int> curSeq;
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return vector<vector<int>>();

        this->sum = sum;
        curSeq = vector<int>();
        result = vector<vector<int>>();
        helper(root, 0);
        return result;
    }
    void helper(TreeNode *root, int curSum){
        curSeq.push_back(root->val);
        curSum += root->val;

        if(!root->left && !root->right){
            if(curSum == sum)
                result.push_back(curSeq);

            curSum -= root->val;
            curSeq.pop_back();
            return;
        }

        if(root->left)
            helper(root->left, curSum);
        if(root->right)
            helper(root->right, curSum);

        curSum -= root->val;
        curSeq.pop_back();
    }
};

