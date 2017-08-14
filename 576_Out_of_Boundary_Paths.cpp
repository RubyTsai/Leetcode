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
        for (int ii = 0; ii < m; ii++)
            for (int jj = 0; jj < n; jj++) 
                for (int k = 2; k < N+1; k++)
                    if (dp[ii][jj][k] == 0) dp[ii][jj][k] = -1;
        return helper(m, n, N, i, j, dp);
    }
private:
    int helper(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp) {
        if (N == 0) return 0;
        if (dp[i][j][N] != -1) return dp[i][j][N];
        
        int paths = 0;
        if (i-1 >= 0) paths += helper(m, n, N-1, i-1, j, dp);
        if (j-1 >= 0) paths += helper(m, n, N-1, i, j-1, dp);
        if (i+1 < m) paths += helper(m, n, N-1, i+1, j, dp);
        if (j+1 < n) paths += helper(m, n, N-1, i, j+1, dp);
        
        if (dp[i][j][N-1] != -1) paths += dp[i][j][N-1];
        else paths += helper(m, n, N-1, i, j, dp);
        
        dp[i][j][N] = paths;
        return paths;
    }
};
