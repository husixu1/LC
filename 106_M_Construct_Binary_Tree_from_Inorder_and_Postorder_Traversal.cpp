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
    vector<int> inorder, postorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size())
            return nullptr;
        this->inorder = inorder;
        this->postorder = postorder;
        return helper(0, 0, inorder.size());
    }
    TreeNode *helper(int inStart, int postStart, int size){
        TreeNode *result = nullptr;
        if(!size)
            return result;
        result = new TreeNode(postorder[postStart + size - 1]);
        int counter = 0;
        while(inorder[inStart + counter] != postorder[postStart + size - 1])
            ++counter;
        result->left = helper(inStart, postStart, counter);
        result->right = helper(inStart + counter + 1, postStart + counter, size - counter - 1);
        return result;
    }
};

