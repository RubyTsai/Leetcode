class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int nsize = nums.size();
        int totalSum = 0;
        for (auto n: nums) totalSum += n;
        if (S > totalSum || S < -totalSum ||
            (S + totalSum) % 2 != 0) return 0;
        S = (S + totalSum) >> 1; // new target

        vector<vector<int>> dp(nsize+1, vector<int>(S+1, 0));
        dp[0][0] = 1;
            
        for (int i = 1; i <= nsize; i++) {
            for (int k = 0; k <= S; k++) {
                if (k >= nums[i-1]) dp[i][k] += dp[i-1][k-nums[i-1]]; // 取這個數
                dp[i][k] += dp[i-1][k];
            }
        }
        return dp[nsize][S];
    } 
};
