#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if(n < 10)
            return {1, n-1};

        int originalN = n;
        int ncopy = n;

        int index = 1;
        int result = 0;

        while (n >= 10) {
            if (((ncopy / index) % 10) == 0 || ((ncopy / index) % 10) == 1) {
                result += index * 2;
                ncopy -= index * 2;
            } else {
                result += index;
                ncopy -= index;
            }
            n /= 10;
            index *= 10;
        }
        return {result, originalN - result};
    }
};
