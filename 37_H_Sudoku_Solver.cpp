#include<vector>
#include<utility>
#include<cstdio>

using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>> &board, vector<pair<int, int>> list, int index){
        char isNotValid[9] ={0,0,0,0,0,0,0,0,0}, a;
        int row = list[index].first;
        int col = list[index].second;

        // find available
        for(int j=0; j<9; j++){
            if((a = board[row][j]) != '.')
                ++isNotValid[ a - '1' ];

            if((a = board[j][col]) != '.')
                ++isNotValid[ a - '1' ];

            int block = row - row % 3 + col/3;
            if((a = board[block - block % 3 + j / 3][3 * (block % 3) + j % 3]) != '.')
                ++isNotValid[ a - '1'];
        }

        // fill and recurse
        for(int i=0; i<9; ++i){
            if(!isNotValid[i]){
                board[row][col] = i+'1';
                if(index == list.size() - 1)
                    return true;
                else if (helper(board, list, index+1))
                    return true;
            }
        }
        board[row][col] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int i, j;
        vector<pair<int, int>> list;
        for(i = 0; i < 9; ++i)
            for(j = 0; j < 9; ++j)
                if(board[i][j] == '.')
                    list.push_back({i, j});
        helper(board, list, 0);
    }
};

