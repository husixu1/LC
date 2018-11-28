#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;

        // calculate difference
        vector<int> diff(prices.size() - 1);
        for (int i = 0; i < prices.size() - 1; ++i)
            diff[i] = prices[i + 1] - prices[i];

        // find max continuous sum
        int maxSum = 0;
        int curSum = 0;
        for(int i = 0; i < diff.size(); ++i){
            if(curSum < 0)
                curSum = diff[i];
            else
                curSum += diff[i];
            if(curSum > maxSum)
                maxSum = curSum;
        }

        return maxSum;
    }
};
