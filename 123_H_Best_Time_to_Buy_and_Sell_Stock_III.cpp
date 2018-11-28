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

        // max profit of prices[0:i]
        vector<int> maxProfitForward(diff.size());
        // max profit of prices[i:n]
        vector<int> maxProfitBackWard(diff.size());

        int maxSumFoward = 0, maxSumBackward = 0;
        int curSumFoward = 0, curSumBackward = 0;

        for (int i = 0; i < diff.size(); ++i) {
            if (curSumFoward < 0)
                curSumFoward = diff[i];
            else
                curSumFoward += diff[i];
            if (curSumFoward > maxSumFoward)
                maxSumFoward = curSumFoward;
            maxProfitForward[i] = maxSumFoward;

            if (curSumBackward < 0)
                curSumBackward = diff[diff.size() - i - 1];
            else
                curSumBackward += diff[diff.size() - i - 1];
            if (curSumBackward > maxSumBackward)
                maxSumBackward = curSumBackward;
            maxProfitBackWard[diff.size() - i - 1] = maxSumBackward;
        }

        // profit of make 2 transactions, separating at i
        vector<int> twoTransactionProfit(diff.size() + 1);
        twoTransactionProfit[0] = maxProfitBackWard[0];
        for (int i = 1; i < diff.size() - 1; ++i)
            twoTransactionProfit[i] =
                maxProfitForward[i] + maxProfitBackWard[i + 1];
        twoTransactionProfit[diff.size() - 1] =
            maxProfitForward[diff.size() - 1];

        return *max_element(
            twoTransactionProfit.begin(), twoTransactionProfit.end());
    }
};
