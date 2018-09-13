#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int index, counter;
        bool dotflag = false,
             eflag = false,
             digitBeforeFlag = false,
             digitAfterFlag = false,
             signBeforeFlag = false,
             signAfterFlag= false;

        // remove ' ' prefix
        for(counter = 0; s[counter] == ' '; counter++);
        s.erase(0,counter);

        // remove ' ' suffix
        for(index = s.size(); index > 0 && s[index-1] == ' '; index--);
        s.erase(index, s.size()-index);

        if(s.empty())
            return false;

        for(index = 0; index < s.size(); ++index){
            if(!(('0' <= s[index] && s[index] <= '9') ||
                        s[index] == '.' ||
                        s[index] == 'e' ||
                        s[index] == '+' ||
                        s[index] == '-') )
                return false;

            // digit
            if('0' <= s[index] && s[index] <= '9'){
                if(!eflag)
                    digitBeforeFlag = true;
                else
                    digitAfterFlag = true;
            }
            // sign
            if(s[index] == '+' || s[index] == '-'){
                // appears before e
                if(!eflag){
                    if(signBeforeFlag || digitBeforeFlag || dotflag)
                        return false;
                    else
                        signBeforeFlag = true;
                // appears after e
                } else {
                    if(signAfterFlag || digitAfterFlag)
                        return false;
                    else signAfterFlag = true;
                }
            }
            // dot
            if(s[index] == '.') {
                if(dotflag || eflag)
                    return false;
                else
                    dotflag = true;
            }
            // exp
            if(s[index] == 'e'){
                if(eflag || !digitBeforeFlag)
                    return false;
                else
                    eflag = true;
            }
        }
        if(!digitBeforeFlag || (eflag && !digitAfterFlag))
            return false;
        else
            return true;
    }
};
