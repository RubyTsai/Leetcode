class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        unsigned limit = 1000000007;
        vector<vector<vector<unsigned>>> dp(m, vector<vector<unsigned>>(n, vector<unsigned>(N+1, 0)));
        for (int k = 1; k < N+1; k++) 
            for (int mi = 0; mi < m; mi++)
                for (int ni = 0; ni < n; ni++)  {
                    dp[mi][ni][k] += mi-1 < 0 ? 1: dp[mi-1][ni][k-1];
                    dp[mi][ni][k] += mi+1 == m? 1: dp[mi+1][ni][k-1];
                    dp[mi][ni][k] += ni-1 < 0 ? 1: dp[mi][ni-1][k-1];                    
                    dp[mi][ni][k] += ni+1 == n? 1: dp[mi][ni+1][k-1];
                    dp[mi][ni][k] %= limit;
                }
        return dp[i][j][N];
    }
};
