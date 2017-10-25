class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
        // 初始化
        for (int i = 0; i < s1.size(); i++) 
            dp[i+1][0] = dp[i][0] + s1[i]; // 想像 s2 為空字串，要將 s1 變成空字串所需的 cost
        for (int j = 0; j < s2.size(); j++)
            dp[0][j+1] = dp[0][j] + s2[j];
        
        for (int i = 0; i < s1.size(); i++)
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j];
                else {
                    dp[i+1][j+1] = min(dp[i][j+1] + s1[i], 
                                       dp[i+1][j] + s2[j]);
                }
            }
        return dp[s1.size()][s2.size()];
    }
};
