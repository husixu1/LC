#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return vector<vector<string>>();

        vector<vector<string>> res;
        vector<string> board;
        for(int i=0; i<n; i++){
            board.push_back("");
            for(int j=0; j<n; j++)
                board[i].push_back('.');
        }
        helper(res, board, 0, n);
        return res;
    }

    void helper(vector<vector<string>> &res, vector<string> &board, int row, int n){
        int len = board[0].size();
        bool valid;
        int j;
        for(int col=0; col<n; col++){
            valid = true;
            for(j=col + 1; j < len; j++)
                if(board[row][j] == 'Q')
                    goto invalid;
            for(j=col - 1; j >= 0; j--)
                if(board[row][j] == 'Q')
                    goto invalid;
            for(j=row + 1; j < len; j++)
                if(board[j][col] == 'Q')
                    goto invalid;
            for(j=row - 1; j >= 0; j--)
                if(board[j][col] == 'Q')
                    goto invalid;

            for(j=1; col+j < len && row+j < len; j++)
                if(board[row+j][col+j] == 'Q')
                    goto invalid;
            for(j=1; col+j < len && row-j >= 0; j++)
                if(board[row-j][col+j] == 'Q')
                    goto invalid;
            for(j=1; col-j >= 0 && row + j < len; j++)
                if(board[row+j][col-j] == 'Q')
                    goto invalid;
            for(j=1; col-j >= 0 && row - j >= 0 ; j++)
                if(board[row-j][col-j] == 'Q')
                    goto invalid;

            // if this place is valid
            board[row][col] = 'Q';

            // if this is the last row
            if(row == n-1)
                res.push_back(board);
            // if this is not the last row
            else
                helper(res, board, row+1, n);

            // jump here if invalid
        invalid:
            board[row][col] = '.';
        }
    }
};
