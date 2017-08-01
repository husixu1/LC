#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 1)
            return "1";
        if(k == 0)
            return "";

        string buf;
        for(int i=0; i<n; i++)
            buf.push_back(char(i+'1'));

        std::string::iterator first, second;
        for(int i=0; i<k-1; i++){
            // *first is the fist value after a ascending sequence (counting from tail to front)
            for(first = buf.end()-2; *first > *(first+1); --first);
            // *second is the first value which bigger than first in the ascending sequence above
            for(second = buf.end()-1; *second < *first; --second);
            // swap *first and *second
            *first  = (*first) ^ (*second);
            *second = (*first) ^ (*second);
            *first  = (*first) ^ (*second);

            // reverse the ascending sequence above
            std::reverse(first+1, buf.end());
        }

        return buf;
    }
};

// best solution

class _Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};
// theory: pay attention to the repitition period of each digit
// highest digit repeats every (n-1)! num, second highest repeats every (n-2)! num, etc.

// 1234
// 1243
// 1324
// 1342
// 1423
// 1432
//
// 2134
// 2143
// 2314
// 2341
// 2413
// 2431
//
// 3124
// 3142
// 3214
// 3241
// 3412
// 3421
//
// 4123
// 4132
// 4213
// 4231
// 4312
// 4321
