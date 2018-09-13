#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int reader=0, writer=0;

        for(; reader < nums.size() && nums[reader] == val; reader++);
        while(reader < nums.size()){
            nums[writer] = nums[reader];
            writer++;
            for(reader++; reader < nums.size() && nums[reader] == val; reader++);
        }
        return writer;
    }
};
