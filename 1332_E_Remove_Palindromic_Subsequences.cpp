#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if(0 == s.size())
            return 0;
        string srev(s);
        std::reverse(srev.begin(), srev.end());
        if (srev == s)
            return 1;
        else
            return 2;
    }
};
