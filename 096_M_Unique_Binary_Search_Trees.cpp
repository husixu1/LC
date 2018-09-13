#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;

        unordered_map<int, int> cache;
        return helper(1, n, cache);
    }
    int helper(int l, int r, unordered_map<int, int> &cache){
        auto it = cache.find(r-l);
        if(it != cache.end())
            return cache.at(r-l);

        if(l >= r)
            return 1;

        int result = 0;
        for(int i=l; i <= r; ++i)
            result += (helper(l, i-1, cache) * helper(i+1, r, cache));

        cache[r-l] = result;
        return result;
    }
};
