#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;

        queue<TreeLinkNode *> q;
        int size, nextSize;

        q.push(root);
        size = 1;
        while(q.size()){
            nextSize = 0;
            while(size--){
                if(q.front()->left){
                    q.push(q.front()->left);
                    ++nextSize;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    ++nextSize;
                }

                TreeLinkNode *front = q.front();
                q.pop();
                if(!size)
                    front->next = nullptr;
                else
                    front->next = q.front();
            }
            size = nextSize;
        }
    }
};

