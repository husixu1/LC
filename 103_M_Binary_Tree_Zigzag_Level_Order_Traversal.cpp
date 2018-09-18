#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode *> q;
        int num;

        q.push(root);
        num = 1;
        int curRow = 0;

        while(q.size()){
            vector<int> row;
            stack<int> rev;
            int nextNum = 0;

            for(int i=0; i < num; ++i){
                if(curRow % 2)
                    rev.push(q.front()->val);
                else
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

            if(curRow % 2)
                while(rev.size()){
                    row.push_back(rev.top());
                    rev.pop();
                }

            result.push_back(std::move(row));
            ++curRow;
        }

        return result;
    }
};

