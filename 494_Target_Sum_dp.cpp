class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int nsize = nums.size();
        int totalSum = 0;
        for (auto n: nums) totalSum += n;
        if (S > totalSum || S < -totalSum) return 0;
        int newTarget = S + totalSum;
        if ((newTarget % 2) != 0) return 0;
        
        S = newTarget > 1;
        vector<vector<int>> dp(nsize+1, vector<int>(S+1, 0));
        
        for (int i = 1; i <= nsize; i++) {
            for (int k = 0; k <= S; k++) {
                if (k == nums[i-1]) dp[i][k] = dp[i-1][0] + 1;
                if (k > nums[i-1]) dp[i][k] += dp[i-1][k-nums[i-1]]; // 取這個數
                dp[i][k] += dp[i-1][k];
            }
        }
        return dp[nums][S];
    } 
};
