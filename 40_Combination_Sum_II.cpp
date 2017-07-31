#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        // candidates are sorted
        sort(candidates.begin(), candidates.end());
        helper(candidates, candidates.size(), target, res);
        return res;
    }

    void helper(vector<int>& candidates, int size, int target, vector<vector<int>> &tempResult){
        // if size reaches zero and target is zero, then there's a match, push an empty vector into result
        if(size == 0 && target == 0) {
           tempResult.push_back({});
        // if size reaches zero but target is not zero, then math failed, do not push anything
        } else if (size == 0) {
            return;
        } else {
            // if the last candidate is bigger than target, use (candidates[0 ... size-2], target) pair to find
            if(candidates[size-1] > target){
                helper(candidates, size-1, target, tempResult);
            } else {
                // i is number of the same candidates
                int i = 0, temp = candidates[size-1];
                for(; size-i > 0 && candidates[size-i-1] == temp; i++);

                // use 0 ... i of same candidates in this search
                for(int j=0; j < i+1; j++){
                    int originalSize = tempResult.size();

                    // when use j same candidates, recursive target will become target-j*candidate
                    helper(candidates, size-i, target - j*candidates[size-1], tempResult);

                    // append j candidates after the newly found result (whose target is target-j*candidate)
                    for(int m = originalSize; m < tempResult.size(); m++){
                        for(int n = 0; n < j; n++)
                            tempResult[m].push_back(candidates[size-1]);
                    }
                }
            }
        }
    }
};
