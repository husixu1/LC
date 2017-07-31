#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writer=0, reader=0;
        while(reader < nums.size()){
            nums[writer] = nums[reader];
            while(reader < nums.size() && nums[reader] == nums[writer])
                reader++;
            writer++;
        }
        return writer;
    }
};
