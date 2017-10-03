class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, -1)));
        return helper(N, K, r, c, dp)/pow(8, K);
    }
private:
    int ii[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int jj[8] = {-1,  1, -2,  2,-2, 2,-1, 1};
    // 計算在 pos(r, c)，還有 k steps 時，有幾個結果是留在 chess board 裡的
    double helper(int N, int k, int r, int c, vector<vector<vector<double>>>& dp) {
        if (r < 0 || c < 0 || r >= N || c >= N) return 0;
        if (k == 0) return 1;
        
        if (dp[r][c][k] != -1) return dp[r][c][k];        
        
        dp[r][c][k] = 0;
        for (int i = 0; i < 8; i++) {
            dp[r][c][k] += helper(N, k-1, r + ii[i], c + jj[i], dp);
        }
        return dp[r][c][k];
    }
};
