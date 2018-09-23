#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int *dp;
    int numDistinct(string s, string t) {
        if(!t.size())
            return 1;
        if(!s.size())
            return 0;
        if(s.size() < t.size())
            return 0;

        dp = (int *)calloc(sizeof(int), s.size() * t.size());
        dp[0] = (s[0] == t[0] ? 1 : 0);
        for(int i=1; i < s.size(); ++i){
            dp[i] = (s[i] == t[0] ? dp[i-1] + 1 : dp[i-1]);
        }
        for(int i=1; i < t.size(); ++i){
            for(int j=i; j < s.size(); ++j){
                dp[i * s.size() + j] = (s[j] == t[i]
                        ? dp[i * s.size() + j - 1] + dp[(i-1) * s.size() + j - 1]
                        : dp[i * s.size() + j - 1]);
            }
        }
        return dp[s.size() * t.size() - 1];
    }
};

