#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(int i = digits.size(); i>0; --i){
            if(carry){
                digits[i-1] += 1;
                carry = digits[i-1]/10;
                digits[i-1] %= 10;
            } else
                break;
        }
        if(carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
