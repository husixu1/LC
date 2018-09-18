#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode *> q;
        int num;

        q.push(root);
        num = 1;

        while(q.size()){
            vector<int> row;
            int nextNum = 0;
            for(int i=0; i < num; ++i){
                row.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                    ++nextNum;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    ++nextNum;
                }
                q.pop();
            }
            num = nextNum;
            result.push_back(std::move(row));
        }

        return result;
    }
};
