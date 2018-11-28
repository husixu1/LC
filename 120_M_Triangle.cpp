#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if(triangle.size() == 0)
            return 0;
        vector<int> sums(triangle.size(), 0);
        sums[0] = triangle[0][0];
        for(int i=1; i < triangle.size(); ++i){
            sums[i] = sums[i-1] + triangle[i][i];
            for(int j = i - 1; j > 0; --j)
                sums[j] = min(sums[j], sums[j-1]) + triangle[i][j];
            sums[0] += triangle[i][0];
        }
        return *min_element(sums.begin(), sums.end());
    }
};


