#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int p = s.size();
        int count = 0;

        for(;p > 0 && s[p-1] == ' '; p--);
        for(;p > 0 && s[p-1] != ' '; count++, p--);
        return count;
    }
};
