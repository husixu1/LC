#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode *>();
        return helper(1, n);
    }
    vector<TreeNode *> helper(int l, int r){
        vector<TreeNode *> result;
        if(l > r)
            result.push_back(nullptr);

        for(int i=l; i<=r; ++i){
            vector<TreeNode *> lresult = helper(l, i-1);
            vector<TreeNode *> rresult = helper(i+1, r);
            for (auto l : lresult){
                for (auto r : rresult){
                    auto newNode = new TreeNode(i);
                    newNode->left = l;
                    newNode->right = r;
                    result.push_back(newNode);
                }
            }
        }

        return result;
    }
};


