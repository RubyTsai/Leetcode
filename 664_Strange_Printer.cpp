class Solution {
public:
    int strangePrinter(string s) {
        int slen = s.size();
        if (slen == 0) return 0;
        vector<vector<int>> dp (slen, vector<int>(slen, 0));
        
        for (int i = 0; i < slen; i++)
            dp[i][i] = 1;
        for (int len = 2; len <= slen; len++) {
            for (int i = 0; i <= slen-len; i++) {
                int j = i + len - 1;
                dp[i][j] = len;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 
                                   dp[i][k] + dp[k+1][j-1] + (s[k] == s[j]? 0: 1));
                }
            }
        }
        return dp[0][slen-1];
    }
};
