#include<vector>
#include<utility>
#include<unordered_map>

using namespace std;

class Solution {
public:
    inline int min(int a, int b){
        return a < b ? a : b;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // renew the first line
        for(int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i-1];

        // renew the first column
        for(int i = 1; i < m; ++i)
            grid[i][0] += grid[i-1][0];

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);

        return grid.back().back();
    }
};

// dijkstra, correct but time limit exceeded
class _Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int m, n;

        unordered_map<pair<int, int>, int, pair_hash> notVisited;
        unordered_map<pair<int, int>, int, pair_hash>::iterator iter, iter2;
        notVisited.insert({{0, 0}, grid[0][0]});

        while(1){
            iter2 = notVisited.begin();
            for(iter = notVisited.begin(); iter!=notVisited.end(); iter++){
                if(iter->second < iter2->second)
                    iter2 = iter;
            }

            m = (*iter2).first.first;
            n = (*iter2).first.second;

            if(m == height-1 && n == width-1)
                return grid[m][n];

            // renew
            if(m+1 < height){
                if(notVisited.find({m+1,n}) == notVisited.end()){
                    grid[m+1][n] += grid[m][n];
                    notVisited.insert({{m+1, n}, grid[m+1][n]});
                }
            }
            if(n+1 < width){
                if(notVisited.find({m, n+1}) == notVisited.end()){
                    grid[m][n+1] += grid[m][n];
                    notVisited.insert({{m, n+1}, grid[m][n+1]});
                }
            }

            // pop
            notVisited.erase(iter2);
        }
    }
};
