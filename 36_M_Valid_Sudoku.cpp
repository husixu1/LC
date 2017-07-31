#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // line check;
        char line[9], col[9], block[9], a;
        for(int i=0; i<9; i++){
            memset(line,  0, 9);
            memset(col,   0, 9);
            memset(block, 0, 9);
            for(int j=0; j<9; j++){
                if((a = board[i][j]) != '.')
                    if((++line[ a - '1' ]) == 2)
                      return false;
                if((a = board[j][i]) != '.')
                    if((++col[ a - '1' ]) == 2)
                        return false;
                if((a = board[i - (i%3) + j/3][3 * (i%3) + (j%3)]) != '.')
                    if((++block[ a - '1']) == 2)
                        return false;
            }
        }
        return true;
    }
};

