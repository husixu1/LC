#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return nullptr;
        this->preorder = preorder;
        this->inorder = inorder;
        return helper(0, 0, preorder.size());
    }

    TreeNode *helper(int preStart, int inStart, int size){
        TreeNode *result = nullptr;
        if(!size)
            return result;

        result = new TreeNode(preorder[preStart]);
        int counter = 0;
        while(inorder[inStart + counter] != preorder[preStart])
            ++counter;

        result->left = helper(preStart + 1, inStart, counter);
        result->right = helper(preStart + counter + 1, inStart + counter + 1, size - counter - 1);
        return result;
    }
};

