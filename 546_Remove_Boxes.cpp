class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int bsize = boxes.size();
        if (bsize == 0) return 0;
        vector<vector<int>> dp(bsize, vector<int>(bsize, 0));
        for (int i = 0; i < bsize; i++)
            dp[i][i] = 1;
        
        for (int length = 2; length <= bsize; length++) {
            for (int i = 0; i <= bsize-length; i++) {
                int j = i + length - 1;
                for (int k = i; k <= j; k++) {
                    int same = 1;
                    while (k+same <= j && boxes[k+same] == boxes[k]) {
                        same++;
                    }
                    int seg0 = (k-1 < i)? 0: dp[i][k-1];
                    int seg1 = same * same;
                    int seg2 = (k+same > j)? 0: dp[k+same][j];
                    dp[i][j] = max(dp[i][j], seg0 + seg1 + seg2);                    
                }
            }
        }
        return dp[0][bsize-1];
    }
};
