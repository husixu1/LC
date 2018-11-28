#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = 1;
        int i = 1;
        for(; i <= rowIndex / 2; ++i)
            result[i] = static_cast<long long>(result[i-1]) * (rowIndex - i + 1) / i;
        for(; i < rowIndex + 1; ++i)
            result[i] = result[rowIndex - i];
        return result;
    }
};
