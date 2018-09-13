#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        return helper(0, 0, 0, s1, s2, s3);
    }
    bool helper(int lpos, int rpos, int tpos, const string &s1, const string &s2, const string &s3){
        if(lpos == s1.size() && rpos == s2.size())
            return true;

        if(lpos < s1.size() && s1[lpos] == s3[tpos] && helper(lpos + 1, rpos, tpos + 1, s1, s2, s3))
            return true;

        if(rpos < s2.size() && s2[rpos] == s3[tpos] && helper(lpos, rpos + 1, tpos + 1, s1, s2, s3))
            return true;

        return false;
    }
};
