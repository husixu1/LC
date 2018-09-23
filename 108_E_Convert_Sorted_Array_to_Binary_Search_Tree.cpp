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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if(!nums.size())
            return nullptr;
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode *helper(vector<int> &nums, int left, int right) {
        if(right < left)
            return nullptr;
        if(right == left)
            return new TreeNode(nums[left]);

        TreeNode *result = new TreeNode(nums[(left + right) / 2]);
        result->left = helper(nums, left, (left + right) / 2 - 1);
        result->right = helper(nums, (left + right) / 2 + 1, right);
        return result;
    }
};
