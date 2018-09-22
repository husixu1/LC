#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> result;
        int size, nextSize;

        if(!root)
            return result;

        q.push(root);
        size = 1;

        while(!q.empty()){
            nextSize = 0;
            vector<int> row;
            while(size--){
                if(q.front()->left){
                    q.push(q.front()->left);
                    ++nextSize;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    ++nextSize;
                }
                row.push_back(q.front()->val);
                q.pop();
            }
            size = nextSize;
            result.push_back(row);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};
