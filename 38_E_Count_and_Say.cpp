#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string origin = "1";
        stringstream generated;
        char temp;
        int count;

        for(int i=1; i<n; i++){
            generated.str("");

            temp = origin[0];
            count = 0;

            for(char c : origin){
                if(c == temp)
                    count++;
                else{
                    generated << count;
                    generated << temp;
                    temp = c;
                    count = 1;
                }
            }
            generated << count;
            generated << temp;

            origin = generated.str();
        }
        return origin;
    }
};
