#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // init the first line
        int result = 1, line[n];
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i]){
                for(; i < n; i++)
                    line[i] = 0;
                break;
            }
            line[i] = 1;
        }

        // calculate the rest lines
        for(int i = 1; i < m; ++i){
            if(obstacleGrid[i][0])
                line[0] = 0;
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j])
                    line[j] = 0;
                else
                    line[j] += line[j-1];
            }
        }

        return line[n-1];
    }
};

