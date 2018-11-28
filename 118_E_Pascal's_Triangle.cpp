#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0; i < numRows; ++i){
            vector<int> row(i + 1);
            for(int j=0; j < i + 1; ++j){
                if(j == 0 || j == i)
                    row[j] = 1;
                else
                    row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
