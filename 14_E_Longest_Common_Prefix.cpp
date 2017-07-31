#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int j=0;
        if(strs.size() == 0)
            return result;
        if(strs.size() == 1)
            return strs[0];
        for(;;){
            for(int i=1; i<strs.size(); i++){
                if(strs[i-1][j] == 0)
                    return result;
                if(strs[i][j]==0 || strs[i][j] != strs[i-1][j])
                    return result;
            }
            result.push_back(strs[0][j]);
            j++;
        }
    }
};
