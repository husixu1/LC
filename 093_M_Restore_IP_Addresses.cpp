#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        helper(s, result, s, 0);
        return result;
    }

    void helper(string s, vector<string> &result, string current, int level){
        if(level == 4){
            if(!s.size())
                result.push_back(current);
            return;
        }

        auto results = findValid(s);
        if(results.size() == 0)
            return;

        for(auto res : results){
            if(level == 0)
                helper(s.substr(res.size(), s.size()), result, res, level + 1);
            else
                helper(s.substr(res.size(), s.size()), result, current + string(".") + res, level + 1);
        }
    }

    vector<string> findValid(string s){
        vector<string> result;
        if(!s.size())
            return result;
        result.push_back(s.substr(0, 1));
        if(s.size() > 1 && s[0] != '0')
            result.push_back(s.substr(0, 2));
        if(s.size() > 2 && s[0] != '0' && s[1] != 0 && stoi(s.substr(0, 3)) <= 255)
            result.push_back(s.substr(0, 3));
        return result;
    }
};

