#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        vector<int> temp;
        ListNode *p = head;
        while(p){
            temp.push_back(p->val);
            p = p->next;
        }
        return helper(temp, 0, temp.size() - 1);
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

