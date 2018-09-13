class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;

        int result = 1, line[n-1];
        for(int i=0; i<n-1; ++i)
            line[i] = 1;

        for(int i=0; i<m-1; ++i){
            ++line[0];
            for(int j=1; j<n-1; j++)
                line[j] += line[j-1];
        }

        return line[n-2];
    }
};
