class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N+1, 0)));
        for (int ii = 0; ii < m; ii++) {
            dp[ii][0][1] += 1;
            dp[ii][n-1][1] += 1;
        }
        for (int jj = 0; jj < n; jj++) {
            dp[0][jj][1] += 1;
            dp[m-1][jj][1] += 1;
        }
        for (int k = 2; k < N+1; k++) 
            for (int ii = 0; ii < m; ii++)
                for (int jj = 0; jj < n; jj++)  {
                    if (ii-1 >= 0) dp[ii][jj][k] += dp[ii-1][jj][k-1];
                    if (jj-1 >= 0) dp[ii][jj][k] += dp[ii][jj-1][k-1];
                    if (ii+1 < m) dp[ii][jj][k] += dp[ii+1][jj][k-1];
                    if (jj+1 < n) dp[ii][jj][k] += dp[ii][jj+1][k-1];
                    dp[ii][jj][k] += dp[ii][jj][k-1];
                }
        return dp[i][j][N];
    }
};
