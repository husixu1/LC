#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (char *l = &s.front(), *r = &s.back();
             l < &s.back() && r > &s.front() && l < r;) {

            if (isalnum(*l) && isalnum(*r)) {
                if(tolower(*l) == tolower(*r)){
                    ++l, --r;
                    continue;
                } else {
                    return false;
                }
            }
            if (!isalnum(*l))
                ++l;
            if (!isalnum(*r))
                --r;
        }

        return true;
    }
};
