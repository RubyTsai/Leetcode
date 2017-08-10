class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp (n+1, vector<int>(k+1, 0));
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = 1;             
            for (int j = 0; j <= k; j++) {
                for (int addPairs = 0; addPairs < i; addPairs++) {
                    if (j + addPairs > k) break;
                    if (j + addPairs == 0) continue;
                    dp[i][j + addPairs] = 
                        (dp[i][j + addPairs] + dp[i-1][j]) % mod;
                    // Since the answer may be very large, the answer should be modulo 109 + 7.
                }
            }
        }
        return dp[n][k]; 
    }
private:
    int mod = 1000000007; // 題目的要求
};
