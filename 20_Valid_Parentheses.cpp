#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char m[(1 << sizeof(char)*8)];
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            if(c == ')' || c == ']' || c == '}'){
                if(st.empty() || m[st.top()] != c)
                    return false;
                st.pop();
            }
        }
        if(! st.empty())
            return false;
        return true;
    }
};
